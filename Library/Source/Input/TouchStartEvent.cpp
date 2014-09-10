//
//  TouchStartEvent.cpp
//  Quark
//
//  Created by Rasmus Rønn Nielsen on 31/08/14.
//  Copyright (c) 2014 Tickleworks. All rights reserved.
//

#include "Quark/Input/TouchStartEvent.h"

namespace Quark {
    TouchStartEvent::TouchStartEvent(int id, Zep::Point2D position) :
    id(id),
    position(position) { }
    
    int TouchStartEvent::getID() const {
        return id;
    }
    
    Zep::Point2D TouchStartEvent::getPosition() const {
        return position;
    }
}
