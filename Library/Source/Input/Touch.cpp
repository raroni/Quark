//
//  Touch.cpp
//  Quark
//
//  Created by Rasmus Rønn Nielsen on 28/01/14.
//  Copyright (c) 2014 Tickleworks. All rights reserved.
//

#include "Quark/Input/Touch.h"

namespace Quark {
    Touch::Touch(int id, Zep::Point2D position) : id(id), position(position), startPosition(position) { }
    
    void Touch::setPosition(Zep::Point2D position) {
        this->position = position;
    }
    
    Zep::Point2D Touch::getPosition() {
        return position;
    }
    
    Zep::Point2D Touch::getStartPosition() {
        return startPosition;
    }
    
    int Touch::getID() {
        return id;
    }
    
    float Touch::getSquaredDistance() {
        auto difference = static_cast<Zep::Vector2>(startPosition-position);
        return difference.getSquaredLength();
    }
}
