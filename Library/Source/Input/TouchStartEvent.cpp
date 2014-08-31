//
//  TouchStartEvent.cpp
//  Quark
//
//  Created by Rasmus Rønn Nielsen on 31/08/14.
//  Copyright (c) 2014 Tickleworks. All rights reserved.
//

#include "Quark/Input/TouchStartEvent.h"

namespace Quark {
    TouchStartEvent::TouchStartEvent(int id) : id(id) { }
    
    int TouchStartEvent::getID() const {
        return id;
    }
}
