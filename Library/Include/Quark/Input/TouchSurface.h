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
#include <vector>

namespace Zep {
    class Point2D;
}

namespace Quark {
    class Point;
    class Touch;
    
    class TouchSurface {
    private:
        std::map<int, Touch*> map;
        std::vector<Touch*> touches;
        std::vector<Touch*> justUpdatedTouches;
        std::vector<Touch*> endedTouches;
        std::vector<Touch*> newTouches;
        void updateStationary();
        void removeEnded();
    public:
        typedef std::vector<Touch*>::iterator iterator;
        iterator begin() { return touches.begin(); };
        iterator end() { return touches.end(); };
        void cleanUp();
        void registerTouch(int id, Zep::Point2D position);
        void updateTouch(int id, Zep::Point2D position);
        void endTouch(int id, Zep::Point2D position);
        void cancelTouch(int id, Zep::Point2D position);
        std::vector<Touch*> getNewTouches();
    };
}

#endif
