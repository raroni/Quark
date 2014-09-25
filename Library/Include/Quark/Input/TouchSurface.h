//
//  TouchSurface.h
//  Quark
//
//  Created by Rasmus Rønn Nielsen on 28/01/14.
//  Copyright (c) 2014 Tickleworks. All rights reserved.
//

#ifndef __Quark__TouchSurface__
#define __Quark__TouchSurface__

#include <map>

namespace Zep {
    class Point2D;
    class EventBus;
}

namespace Quark {
    class Point;
    class Touch;
    
    class TouchSurface {
    private:
        std::map<int, Touch*> map;
        Zep::EventBus &eventBus;
        static float squaredDragTolerance;
    public:
        TouchSurface(Zep::EventBus &eventBus);
        Zep::EventBus& getEventBus();
        Touch& getTouch(int id);
        void startTouch(int id, Zep::Point2D position);
        void updateTouch(int id, Zep::Point2D position);
        void endTouch(int id, Zep::Point2D position);
        void cancelTouch(int id, Zep::Point2D position);
    };
}

#endif
