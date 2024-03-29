//
//  QuarkView.m
//  Quark
//
//  Created by Rasmus Rønn Nielsen on 28/01/14.
//  Copyright (c) 2014 Tickleworks. All rights reserved.
//

#include "Zep/Geometry/Point2D.h"
#include "Quark/Rendering/OpenGL.h"
#include "Quark/Resolution.h"
#include "Quark/System.h"
#include "Quark/Rendering/OGLConfig.h"
#include "Quark/Input/TouchSurface.h"
#include "Quark/iOS/TouchIDHelper.h"
#import "Quark/iOS/View.h"

@interface QuarkView()
- (int)pointsToPixels:(float)points;
- (Zep::Point2D)UITouchToQuarkPoint:(UITouch*)touch;
@end

@implementation QuarkView

- (id)initWithQuarkSystem:(Quark::System&)system
{
    self = [self initWithFrame:[UIScreen mainScreen].bounds];
    
    if(self) {
        buffersCreated = false;

        touchIDHelper = new Quark::TouchIDHelper();
        quarkScreen = &system.getScreen();
        quarkTouchSurface = &system.getTouchSurface();
        quarkOGLConfig = &system.getOGLConfig();
        
        self.contentScaleFactor = [[UIScreen mainScreen] scale];
        [self setupLayer];
        [self setupContext];
    }
    
    return self;
}

- (void)setupLayer
{
    self.layer.opaque = YES;
    CAEAGLLayer *eaglLayer = (CAEAGLLayer *)self.layer;
    
    eaglLayer.drawableProperties = [NSDictionary dictionaryWithObjectsAndKeys:[NSNumber numberWithBool:NO], kEAGLDrawablePropertyRetainedBacking, kEAGLColorFormatSRGBA8, kEAGLDrawablePropertyColorFormat, nil];
}

- (void)setupContext
{
    context = [[EAGLContext alloc] initWithAPI:kEAGLRenderingAPIOpenGLES2];
    [EAGLContext setCurrentContext:context];
}

- (void)createSamplingFramebuffer
{
    glGenFramebuffers(1, &samplingFramebufferHandle);
    glBindFramebuffer(GL_FRAMEBUFFER, samplingFramebufferHandle);
    
    int width = [self widthsInPixels];
    int height = [self heightInPixels];

    glGenRenderbuffers(1, &samplingColorRenderbufferHandle);
    glBindRenderbuffer(GL_RENDERBUFFER, samplingColorRenderbufferHandle);
    glRenderbufferStorageMultisampleAPPLE(GL_RENDERBUFFER, 4, GL_RGBA8_OES, width, height);
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_RENDERBUFFER, samplingColorRenderbufferHandle);

    if(quarkOGLConfig->isDepthBufferEnabled()) {
        glGenRenderbuffers(1, &samplingDepthRenderbufferHandle);
        glBindRenderbuffer(GL_RENDERBUFFER, samplingDepthRenderbufferHandle);
        glRenderbufferStorageMultisampleAPPLE(GL_RENDERBUFFER, 4, GL_DEPTH_COMPONENT16, width, height);
        glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, samplingDepthRenderbufferHandle);
    }
    
    if(glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE) {
        NSLog(@"Failed to make complete framebuffer object %x", glCheckFramebufferStatus(GL_FRAMEBUFFER));
    }
}

- (void)createPrimaryFramebuffer
{
    glGenFramebuffers(1, &primaryFramebufferHandle);
    glBindFramebuffer(GL_FRAMEBUFFER, primaryFramebufferHandle);
    
    glGenRenderbuffers(1, &primaryColorRenderbufferHandle);
    glBindRenderbuffer(GL_RENDERBUFFER, primaryColorRenderbufferHandle);
    [context renderbufferStorage:GL_RENDERBUFFER fromDrawable:(CAEAGLLayer*)self.layer];
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_RENDERBUFFER, primaryColorRenderbufferHandle);

    if(quarkOGLConfig->isDepthBufferEnabled()) {
        int width = [self widthsInPixels];
        int height = [self heightInPixels];
        glGenRenderbuffers(1, &primaryDepthRenderbufferHandle);
        glBindRenderbuffer(GL_RENDERBUFFER, primaryDepthRenderbufferHandle);
        glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT16, width, height);
        glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, primaryDepthRenderbufferHandle);
    }
    
    if(glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE) {
        NSLog(@"Failed to make complete framebuffer object %x", glCheckFramebufferStatus(GL_FRAMEBUFFER));
    }
}

- (void)deleteBuffers {
    glDeleteFramebuffers(1, &primaryFramebufferHandle);
    glDeleteRenderbuffers(1, &primaryColorRenderbufferHandle);
    if(quarkOGLConfig->isDepthBufferEnabled()) {
        glDeleteRenderbuffers(1, &primaryDepthRenderbufferHandle);
    }

    if(quarkOGLConfig->isMultisamplingEnabled()) {
        glDeleteFramebuffers(1, &samplingFramebufferHandle);
        glDeleteRenderbuffers(1, &samplingColorRenderbufferHandle);
        if(quarkOGLConfig->isDepthBufferEnabled()) {
            glDeleteRenderbuffers(1, &samplingDepthRenderbufferHandle);
        }
    }
    glDeleteFramebuffers(1, &primaryFramebufferHandle);
}

- (void)createBuffers
{
    [self createPrimaryFramebuffer];
    if(quarkOGLConfig->isMultisamplingEnabled()) {
        [self createSamplingFramebuffer];
    }
    buffersCreated = true;
}

- (void)layoutSubviews
{
    if(buffersCreated) [self deleteBuffers];
    [self createBuffers];
    
    int width = [self widthsInPixels];
    int height = [self heightInPixels];
    Quark::Resolution resolution(width, height);
    quarkScreen->setResolution(resolution);
}

- (void)present
{
    if(quarkOGLConfig->isMultisamplingEnabled()) {
        glBindFramebuffer(GL_DRAW_FRAMEBUFFER_APPLE, primaryFramebufferHandle);
        glBindFramebuffer(GL_READ_FRAMEBUFFER_APPLE, samplingFramebufferHandle);
        glResolveMultisampleFramebufferAPPLE();
        glBindFramebuffer(GL_FRAMEBUFFER, samplingFramebufferHandle);
    }
    
    glBindRenderbuffer(GL_RENDERBUFFER, primaryColorRenderbufferHandle);
    [context presentRenderbuffer:GL_RENDERBUFFER];
}

- (int)widthsInPixels
{
    return [self pointsToPixels:self.bounds.size.width];
}

- (int)heightInPixels
{
    return [self pointsToPixels:self.bounds.size.height];
}

- (void)touchesBegan:(NSSet*)touches withEvent:(UIEvent *)event
{
    for(UITouch *touch in touches) {
        int id = touchIDHelper->createID((intptr_t)touch);
        Zep::Point2D position = [self UITouchToQuarkPoint:touch];
        quarkTouchSurface->startTouch(id, position);
    }
}

- (void)touchesMoved:(NSSet*)touches withEvent:(UIEvent *)event
{
    for(UITouch *touch in touches) {
        int id = touchIDHelper->getID(intptr_t(touch));
        Zep::Point2D position = [self UITouchToQuarkPoint:touch];
        quarkTouchSurface->updateTouch(id, position);
    }
}

- (void)touchesEnded:(NSSet*)touches withEvent:(UIEvent *)event
{
    for(UITouch *touch in touches) {
        intptr_t touchAddress = intptr_t(touch);
        int id = touchIDHelper->getID(touchAddress);
        touchIDHelper->destroyID(touchAddress);
        
        Zep::Point2D position = [self UITouchToQuarkPoint:touch];
        quarkTouchSurface->endTouch(id, position);
    }
}

- (void)touchesCancelled:(NSSet*)touches withEvent:(UIEvent*)event
{
    for(UITouch *touch in touches) {
        intptr_t touchAddress = intptr_t(touch);
        int id = touchIDHelper->getID(touchAddress);
        touchIDHelper->destroyID(touchAddress);
        
        Zep::Point2D position = [self UITouchToQuarkPoint:touch];
        quarkTouchSurface->cancelTouch(id, position);
    }
}

- (Zep::Point2D)UITouchToQuarkPoint:(UITouch*)touch {
    CGPoint iOSpoint = [touch locationInView:self];
    Zep::Point2D position;
    position[0] = (iOSpoint.x/self.layer.bounds.size.width)*2-1;
    position[1] = (iOSpoint.y/self.layer.bounds.size.height)*-2+1;
    return position;
}

- (int)pointsToPixels:(float)points
{
    return [[UIScreen mainScreen] scale] * points;
}

+ (Class)layerClass
{
    return [CAEAGLLayer class];
}

- (void)dealloc
{
    delete touchIDHelper;
}

@end
