//
//  ShaderProgram.h
//  Quark
//
//  Created by Rasmus Rønn Nielsen on 02/07/14.
//  Copyright (c) 2014 Tickleworks. All rights reserved.
//

#ifndef __Quark__ShaderProgram__
#define __Quark__ShaderProgram__

#include <string>
#include "Quark/Rendering/OpenGL.h"

namespace Zep {
    class Matrix4;
    class Vector3;
    class Vector2;
    class Matrix3;
}

namespace Quark {
    class ShaderProgram {
        GLuint handle;
    public:
        ShaderProgram(GLuint handle);
        void use() const;
        GLint getAttributeHandle(std::string name) const;
        GLint getUniformHandle(std::string name) const;
        static void setUniform(GLint uniformHandle, Zep::Matrix4 matrix);
        static void setUniform(GLint uniformHandle, Zep::Matrix3 matrix);
        static void setUniform(GLint uniformHandle, Zep::Vector3 vector);
        static void setUniform(GLint uniformHandle, Zep::Vector2 vector);
        static void setUniform(GLint uniformHandle, float number);
    };
}

#endif
