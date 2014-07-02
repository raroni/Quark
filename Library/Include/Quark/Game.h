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

namespace Quark {
    class Game {
        Screen screen;
        TouchSurface touchSurface;
    public:
        virtual void update(int timeDelta) = 0;
        virtual void initialize() { }
        Screen& getScreen();
        TouchSurface& getTouchSurface();
        virtual ~Game() { }
    };
}

#endif
