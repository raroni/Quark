//
//  QuarkView.h
//  Quark
//
//  Created by Rasmus Rønn Nielsen on 28/01/14.
//  Copyright (c) 2014 Tickleworks. All rights reserved.
//

#import <UIKit/UIKit.h>
#include "Quark/iOS/TouchIDHelper.h"

namespace Quark {
    class Screen;
    class TouchSurface;
}

@interface QuarkView : UIView
{
    Quark::Screen *QuarkScreen;
    Quark::TouchSurface *QuarkTouchSurface;
    Quark::TouchIDHelper *touchIDHelper;
    EAGLContext *context;
    GLuint colorRenderbufferHandle;
    GLuint depthRenderbufferHandle;
}
- (id)initWithQuarkScreen:(Quark::Screen&)screen QuarkTouchSurface:(Quark::TouchSurface&)touchSurface;
- (void)setupFrameBuffer;
- (void)present;
- (void)dealloc;
@end
