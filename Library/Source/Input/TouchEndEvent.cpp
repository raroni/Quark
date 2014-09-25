//
//  TouchEndEvent.cpp
//  Quark
//
//  Created by Rasmus Rønn Nielsen on 31/08/14.
//  Copyright (c) 2014 Tickleworks. All rights reserved.
//

#include "Quark/Input/TouchEndEvent.h"

namespace Quark {
    TouchEndEvent::TouchEndEvent(int id, Zep::Point2D position) :
    id(id),
    position(position) { }
    
    int TouchEndEvent::getID() const {
        return id;
    }

    Zep::Point2D TouchEndEvent::getPosition() const {
        return position;
    }
}
