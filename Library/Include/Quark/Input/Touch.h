//
//  Touch.h
//  Quark
//
//  Created by Rasmus Rønn Nielsen on 28/01/14.
//  Copyright (c) 2014 Tickleworks. All rights reserved.
//

#ifndef __Quark__Touch__
#define __Quark__Touch__

#include "Zep/Geometry/Point2D.h"

namespace Quark {
    class Touch {
        Zep::Point2D startPosition;
        Zep::Point2D position;
        int id;
    public:
        bool dragging = false;
        Touch(int id, Zep::Point2D position);
        void setPosition(Zep::Point2D position);
        Zep::Point2D getPosition();
        Zep::Point2D getStartPosition();
        float getSquaredDistance();
        int getID();
    };
}

#endif
