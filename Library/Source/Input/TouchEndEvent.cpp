//
//  TouchEndEvent.cpp
//  Quark
//
//  Created by Rasmus Rønn Nielsen on 31/08/14.
//  Copyright (c) 2014 Tickleworks. All rights reserved.
//

#include "Quark/Input/TouchEndEvent.h"

namespace Quark {
    TouchEndEvent::TouchEndEvent(int id) : id(id) { }
    
    int TouchEndEvent::getID() const {
        return id;
    }
}
