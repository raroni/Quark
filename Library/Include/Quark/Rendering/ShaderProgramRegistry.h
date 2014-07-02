//
//  ShaderProgramRegistry.h
//  Quark
//
//  Created by Rasmus Rønn Nielsen on 02/07/14.
//  Copyright (c) 2014 Tickleworks. All rights reserved.
//

#ifndef __Quark__ShaderProgramRegistry__
#define __Quark__ShaderProgramRegistry__

#include <map>
#include <string>
#include "Quark/Rendering/ShaderProgram.h"

namespace Quark {
    class ShaderProgram;
    
    class ShaderProgramRegistry {
        typedef std::map<std::string, ShaderProgram> ProgramMap;
        ProgramMap programs;
    public:
        void add(std::string name, ShaderProgram program);
    };
}

#endif
