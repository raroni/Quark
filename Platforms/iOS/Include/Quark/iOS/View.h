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
    class System;
    class TouchSurface;
    class TouchIDHelper;
    class OGLConfig;
}

@interface QuarkView : UIView
{
    Quark::Screen *quarkScreen;
    Quark::TouchSurface *quarkTouchSurface;
    Quark::TouchIDHelper *touchIDHelper;
    Quark::OGLConfig *quarkOGLConfig;
    EAGLContext *context;
    GLuint primaryFramebufferHandle;
    GLuint samplingFramebufferHandle;
    GLuint primaryColorRenderbufferHandle;
}
- (id)initWithQuarkSystem:(Quark::System&)system;
- (void)present;
- (void)dealloc;
@end
