//
//  ShaderProgram.cpp
//  Quark
//
//  Created by Rasmus Rønn Nielsen on 02/07/14.
//  Copyright (c) 2014 Tickleworks. All rights reserved.
//

#include "Zep/Math/Matrix4.h"
#include "Zep/Math/Vector3.h"
#include "ShaderProgram.h"

namespace Quark {
    ShaderProgram::ShaderProgram(GLuint handle) : handle(handle) { }
    
    void ShaderProgram::use() const {
        glUseProgram(handle);
    }
    
    GLint ShaderProgram::getAttributeHandle(std::string name) const {
        auto cName = name.c_str();
        return glGetAttribLocation(handle, cName);
    }
    
    GLint ShaderProgram::getUniformHandle(std::string name) const {
        auto cName = name.c_str();
        return glGetUniformLocation(handle, cName);
    }
    
    void ShaderProgram::setUniform(GLint handle, Zep::Matrix4 matrix) {
        glUniformMatrix4fv(handle, 1, GL_FALSE, matrix.components);
    }
    
    void ShaderProgram::setUniform(GLint handle, Zep::Vector3 vector) {
        glUniform3fv(handle, 1, vector.components);
    }
}
