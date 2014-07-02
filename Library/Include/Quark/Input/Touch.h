//
//  Touch.h
//  Quark
//
//  Created by Rasmus Rønn Nielsen on 28/01/14.
//  Copyright (c) 2014 Tickleworks. All rights reserved.
//

#ifndef __Quark__Touch__
#define __Quark__Touch__

#include "Quark/Point.h"

namespace Quark {
    class Touch {
        Point position;
        int id;
    public:
        enum Status {
            Began,
            Moved,
            Stationary,
            Ended,
            Cancelled
        };
        Touch(int id, Point position);
        void setStatus(Status status);
        Status getStatus();
        void setPosition(Point position);
        Point getPosition();
        int getID();
    private:
        Status status = Began;
    };
}

#endif
