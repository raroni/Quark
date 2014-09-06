//
//  OGLConfig.h
//  Quark
//
//  Created by Rasmus Rønn Nielsen on 06/09/14.
//  Copyright (c) 2014 Tickleworks. All rights reserved.
//

#ifndef __Quark__OGLConfig__
#define __Quark__OGLConfig__

namespace Quark {
    class OGLConfig {
        bool multisampling = false;
    public:
        void enableMultisampling();
        bool isMultisamplingEnabled();
    };
}

#endif
