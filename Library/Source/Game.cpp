//
//  Game.cpp
//  Quark
//
//  Created by Rasmus Rønn Nielsen on 28/01/14.
//  Copyright (c) 2014 Tickleworks. All rights reserved.
//

#include "Quark/Game.h"

namespace Quark {
    Screen& Game::getScreen() {
        return screen;
    }
    
    TouchSurface& Game::getTouchSurface() {
        return touchSurface;
    }
    
    ShaderProgramRegistry& Game::getShaderProgramRegistry() {
        return shaderProgramRegistry;
    }
}
