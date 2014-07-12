//
//  Game.h
//  Quark
//
//  Created by Rasmus Rønn Nielsen on 28/01/14.
//  Copyright (c) 2014 Tickleworks. All rights reserved.
//

#ifndef __Quark__Game__
#define __Quark__Game__

#include "Quark/Screen.h"
#include "Quark/Input/TouchSurface.h"
#include "Quark/Rendering/ShaderProgramRegistry.h"

namespace Quark {
    class Game {
        Screen screen;
        TouchSurface touchSurface;
        ShaderProgramRegistry shaderProgramRegistry;
    public:
        virtual void update(float timeDelta) = 0;
        virtual void initialize() { }
        Screen& getScreen();
        TouchSurface& getTouchSurface();
        ShaderProgramRegistry& getShaderProgramRegistry();
        virtual ~Game() { }
    };
}

#endif
