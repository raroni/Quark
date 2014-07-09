//
//  QuarkView.m
//  Quark
//
//  Created by Rasmus Rønn Nielsen on 28/01/14.
//  Copyright (c) 2014 Tickleworks. All rights reserved.
//

#include "Quark/Rendering/OpenGL.h"
#include "Quark/Point.h"
#include "Quark/Resolution.h"
#include "Quark/Screen.h"
#include "Quark/Input/TouchSurface.h"
#include "Quark/iOS/TouchIDHelper.h"
#import "Quark/iOS/View.h"

@interface QuarkView()
- (float)pointsToPixels:(float)points;
- (Quark::Point)UITouchToQuarkPoint:(UITouch*)touch;
@end

@implementation QuarkView

- (id)initWithQuarkScreen:(Quark::Screen&)screen QuarkTouchSurface:(Quark::TouchSurface&)touchSurface
{
    self = [self initWithFrame:[UIScreen mainScreen].bounds];
    
    if(self) {
        touchIDHelper = new Quark::TouchIDHelper();
        QuarkScreen = &screen;
        QuarkTouchSurface = &touchSurface;
        
        self.contentScaleFactor = [[UIScreen mainScreen] scale];
        [self setupLayer];
        [self setupContext];
        [self setupFrameBuffer];
        glGenRenderbuffers(1, &colorRenderbufferHandle);
        glGenRenderbuffers(1, &depthRenderbufferHandle);
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

- (void)setupFrameBuffer
{
    GLuint framebufferHandle;
    glGenFramebuffers(1, &framebufferHandle);
    glBindFramebuffer(GL_FRAMEBUFFER, framebufferHandle);
}

- (void)layoutSubviews
{
    glBindRenderbuffer(GL_RENDERBUFFER, colorRenderbufferHandle);
    [context renderbufferStorage:GL_RENDERBUFFER fromDrawable:(CAEAGLLayer*)self.layer];
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_RENDERBUFFER, colorRenderbufferHandle);
    
    float width = [self pointsToPixels:self.bounds.size.width];
    float height = [self pointsToPixels:self.bounds.size.height];
    glBindRenderbuffer(GL_RENDERBUFFER, depthRenderbufferHandle);
    glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT16, width, height);
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, depthRenderbufferHandle);
    
    Quark::Resolution resolution(width, height);
    QuarkScreen->setResolution(resolution);
}

- (void)present
{
    glBindRenderbuffer(GL_RENDERBUFFER, colorRenderbufferHandle);
    [context presentRenderbuffer:GL_RENDERBUFFER];
    
}

- (void)touchesBegan:(NSSet*)touches withEvent:(UIEvent *)event
{
    for(UITouch *touch in touches) {
        int id = touchIDHelper->createID((intptr_t)touch);
        Quark::Point position = [self UITouchToQuarkPoint:touch];
        QuarkTouchSurface->registerTouch(id, position);
    }
}

- (void)touchesMoved:(NSSet*)touches withEvent:(UIEvent *)event
{
    for(UITouch *touch in touches) {
        int id = touchIDHelper->getID(intptr_t(touch));
        Quark::Point position = [self UITouchToQuarkPoint:touch];
        QuarkTouchSurface->updateTouch(id, position);
    }
}

- (void)touchesEnded:(NSSet*)touches withEvent:(UIEvent *)event
{
    for(UITouch *touch in touches) {
        intptr_t touchAddress = intptr_t(touch);
        int id = touchIDHelper->getID(touchAddress);
        touchIDHelper->destroyID(touchAddress);
        
        Quark::Point position = [self UITouchToQuarkPoint:touch];
        QuarkTouchSurface->endTouch(id, position);
    }
}

- (void)touchesCancelled:(NSSet*)touches withEvent:(UIEvent*)event
{
    for(UITouch *touch in touches) {
        intptr_t touchAddress = intptr_t(touch);
        int id = touchIDHelper->getID(touchAddress);
        touchIDHelper->destroyID(touchAddress);
        
        Quark::Point position = [self UITouchToQuarkPoint:touch];
        QuarkTouchSurface->cancelTouch(id, position);
    }
}

- (Quark::Point)UITouchToQuarkPoint:(UITouch*)touch {
    CGPoint iOSpoint = [touch locationInView:self];
    Quark::Point position;
    position.x = (iOSpoint.x/self.layer.bounds.size.width)*2-1;
    position.y = (iOSpoint.y/self.layer.bounds.size.height)*-2+1;
    return position;
}

- (float)pointsToPixels:(float)points
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
