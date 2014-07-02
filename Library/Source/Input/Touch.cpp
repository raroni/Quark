//
//  Touch.cpp
//  Quark
//
//  Created by Rasmus Rønn Nielsen on 28/01/14.
//  Copyright (c) 2014 Tickleworks. All rights reserved.
//

#include "Quark/Input/Touch.h"

namespace Quark {
    Touch::Touch(int id, Point position) : id(id), position(position) { }
    
    void Touch::setStatus(Touch::Status status) {
        this->status = status;
    }
    
    Touch::Status Touch::getStatus() {
        return status;
    }
    
    void Touch::setPosition(Point position) {
        this->position = position;
    }
    
    Point Touch::getPosition() {
        return position;
    }
    
    int Touch::getID() {
        return id;
    }
}
