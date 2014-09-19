//
//  DragStartEvent.cpp
//  Quark
//
//  Created by Rasmus Rønn Nielsen on 19/09/14.
//  Copyright (c) 2014 Tickleworks. All rights reserved.
//

#include "DragStartEvent.h"

namespace Quark {
    DragStartEvent::DragStartEvent(int id) : id(id) { }

    int DragStartEvent::getID() const {
        return id;
    }
}
