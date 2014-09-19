//
//  TouchSurface.cpp
//  Quark
//
//  Created by Rasmus Rønn Nielsen on 28/01/14.
//  Copyright (c) 2014 Tickleworks. All rights reserved.
//

#include "Zep/Events/EventBus.h"
#include "Quark/Input/Touch.h"
#include "Quark/Input/TouchStartEvent.h"
#include "Quark/Input/DragStartEvent.h"
#include "Quark/Input/TouchEndEvent.h"
#include "Quark/Input/TouchSurface.h"

namespace Quark {
    float TouchSurface::squaredDragTolerance = std::pow(0.02, 2);
    
    TouchSurface::TouchSurface(Zep::EventBus &eventBus) : eventBus(eventBus) { }
    
    void TouchSurface::startTouch(int id, Zep::Point2D position) {
        auto touch = new Touch(id, position);
        
        map.insert(std::map<int, Touch*>::value_type(id, touch));
        
        TouchStartEvent event(id, position);
        eventBus.emit(event);
    }
    
    Zep::EventBus& TouchSurface::getEventBus() {
        return eventBus;
    }
    
    void TouchSurface::updateTouch(int id, Zep::Point2D position) {
        Touch *touch = map.find(id)->second;
        touch->setPosition(position);
        
        if(!touch->dragging) {
            auto squaredDistance = touch->getSquaredDistance();
            if(squaredDistance > squaredDragTolerance) {
                touch->dragging = true;

                DragStartEvent event(id);
                eventBus.emit(event);
            }
        }
    }
    
    void TouchSurface::endTouch(int id, Zep::Point2D position) {
        auto touch = map.find(id)->second;
        touch->setPosition(position);
        
        TouchEndEvent event(id);
        eventBus.emit(event);
        
        delete touch;
        map.erase(id);
    }
    
    void TouchSurface::cancelTouch(int id, Zep::Point2D position) {
        Touch* touch = map.find(id)->second;
        touch->setPosition(position);
        
        TouchEndEvent event(id);
        eventBus.emit(event);
    }
    
    Touch& TouchSurface::getTouch(int index) {
        return *map[index];
    }
}
