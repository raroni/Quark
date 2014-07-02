//
//  ShaderProgram.h
//  Quark
//
//  Created by Rasmus Rønn Nielsen on 02/07/14.
//  Copyright (c) 2014 Tickleworks. All rights reserved.
//

#ifndef __Quark__ShaderProgram__
#define __Quark__ShaderProgram__

#include "Quark/Rendering/OpenGL.h"

namespace Quark {
    class ShaderProgram {
        GLuint handle;
    public:
        ShaderProgram(GLuint handle);
        void use() const;
    };
}

#endif
