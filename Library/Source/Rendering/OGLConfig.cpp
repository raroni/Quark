//
//  OGLConfig.cpp
//  Quark
//
//  Created by Rasmus Rønn Nielsen on 06/09/14.
//  Copyright (c) 2014 Tickleworks. All rights reserved.
//

#include "Quark/Rendering/OGLConfig.h"

namespace Quark {
    void OGLConfig::enableMultisampling() {
        multisampling = true;
    }
    
    bool OGLConfig::isMultisamplingEnabled() {
        return multisampling;
    }

    bool OGLConfig::isDepthBufferEnabled() {
        return depthBuffer;
    }

    void OGLConfig::enableDepthBuffer() {
        depthBuffer = true;
    }
}
