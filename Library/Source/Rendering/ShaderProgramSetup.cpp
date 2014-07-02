//
//  ShaderProgramSetup.cpp
//  Quark
//
//  Created by Rasmus Rønn Nielsen on 02/07/14.
//  Copyright (c) 2014 Tickleworks. All rights reserved.
//

#include "ShaderProgramSetup.h"
#include "Quark/Exception.h"

namespace Quark {
    ShaderProgramSetup::ShaderProgramSetup(std::string vertexSource, std::string fragmentSource) : vertexSource(vertexSource), fragmentSource(fragmentSource) {
    }
    
    void ShaderProgramSetup::compile() {
        handle = glCreateProgram();
        vertexHandle = compileShader(vertexSource, GL_VERTEX_SHADER);
        fragmentHandle = compileShader(fragmentSource, GL_FRAGMENT_SHADER);
    }
    
    GLuint ShaderProgramSetup::compileShader(std::string source, GLenum type) {
        GLuint shaderHandle = glCreateShader(type);
        
        const char *cString = source.c_str();
        glShaderSource(shaderHandle, 1, &cString, NULL);
        
        glCompileShader(shaderHandle);
        
        GLint compileSuccess;
        glGetShaderiv(shaderHandle, GL_COMPILE_STATUS, &compileSuccess);
        if(compileSuccess == GL_FALSE) {
            GLint logLength;
            glGetShaderiv(shaderHandle, GL_INFO_LOG_LENGTH, &logLength);
            
            GLchar *log = new GLchar[logLength+1];
            glGetShaderInfoLog(shaderHandle, logLength, NULL, log);
            
            delete[] log;
            
            throw Exception("Compilation error in shader.");
        }
        
        return shaderHandle;
    }
    
    void ShaderProgramSetup::link() {
        glAttachShader(handle, vertexHandle);
        glAttachShader(handle, fragmentHandle);
        
        glLinkProgram(handle);
        
        GLint linkSuccess;
        glGetProgramiv(handle, GL_LINK_STATUS, &linkSuccess);
        if(linkSuccess == GL_FALSE) {
            throw Exception("GL program linking failed.");
        }
    }
    
    GLuint ShaderProgramSetup::getHandle() {
        return handle;
    }
}
