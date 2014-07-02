//
//  ShaderProgramRegistry.cpp
//  Quark
//
//  Created by Rasmus Rønn Nielsen on 02/07/14.
//  Copyright (c) 2014 Tickleworks. All rights reserved.
//

#include "Quark/Exception.h"
#include "Quark/Rendering/ShaderProgramRegistry.h"

namespace Quark {
    void ShaderProgramRegistry::add(std::string name, ShaderProgram program) {
        auto iterator = programs.find(name);
        if(iterator != programs.end()) {
            throw Exception("Name already used.");
        }
        ProgramMap::value_type value(name, program);
        programs.insert(value);
    }
}
