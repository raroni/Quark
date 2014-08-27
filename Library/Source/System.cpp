//
//  System.cpp
//  Quark
//
//  Created by Rasmus Rønn Nielsen on 27/08/14.
//  Copyright (c) 2014 Tickleworks. All rights reserved.
//

#include "Quark/System.h"

namespace Quark {
    Screen& System::getScreen() {
        return screen;
    }
    
    TouchSurface& System::getTouchSurface() {
        return touchSurface;
    }
    
    Zep::EventBus& System::getEventBus() {
        return eventBus;
    }
}
