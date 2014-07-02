//
//  ShaderProgram.cpp
//  Quark
//
//  Created by Rasmus Rønn Nielsen on 02/07/14.
//  Copyright (c) 2014 Tickleworks. All rights reserved.
//

#include "ShaderProgram.h"

namespace Quark {
    ShaderProgram::ShaderProgram(GLuint handle) : handle(handle) { }
    
    void ShaderProgram::use() const {
        glUseProgram(handle);
    }
}
