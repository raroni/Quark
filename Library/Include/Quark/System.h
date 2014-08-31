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
#include "Zep/Events/EventBus.h"

namespace Quark {
    class System {
        Zep::EventBus eventBus;
        TouchSurface touchSurface;
        Screen screen;
    public:
        System();
        TouchSurface& getTouchSurface();
        Screen& getScreen();
        Zep::EventBus& getEventBus();
    };
}

#endif
