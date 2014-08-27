//
//  System.h
//  Quark
//
//  Created by Rasmus Rønn Nielsen on 27/08/14.
//  Copyright (c) 2014 Tickleworks. All rights reserved.
//

#ifndef __Quark__System__
#define __Quark__System__

#include "Quark/Input/TouchSurface.h"
#include "Quark/Screen.h"
#include "Zep/Events/EventManager.h"

namespace Quark {
    class System {
        TouchSurface touchSurface;
        Screen screen;
        Zep::EventManager eventManager;
    public:
        TouchSurface& getTouchSurface();
        Screen& getScreen();
        Zep::EventManager& getEventManager();
    };
}

#endif
