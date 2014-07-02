//
//  ShaderProgramSetup.h
//  Quark
//
//  Created by Rasmus Rønn Nielsen on 02/07/14.
//  Copyright (c) 2014 Tickleworks. All rights reserved.
//

#ifndef __Quark__ShaderProgramSetup__
#define __Quark__ShaderProgramSetup__

#include <string>
#include "Quark/Rendering/OpenGL.h"

namespace Quark {
    class ShaderProgramSetup {
        std::string vertexSource;
        std::string fragmentSource;
        GLuint handle;
        GLuint vertexHandle;
        GLuint fragmentHandle;
        GLuint compileShader(std::string source, GLenum type);
    public:
        ShaderProgramSetup(std::string vertexSource, std::string fragmentSource);
        void compile();
        void link();
        GLuint getHandle();
    };
}

#endif
