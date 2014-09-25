//
//  TouchEndEvent.h
//  Quark
//
//  Created by Rasmus Rønn Nielsen on 31/08/14.
//  Copyright (c) 2014 Tickleworks. All rights reserved.
//

#ifndef __Quark__TouchEndEvent__
#define __Quark__TouchEndEvent__

#include "Zep/Events/Event.h"
#include "Zep/Geometry/Point2D.h"

namespace Quark {
    class TouchEndEvent : public Zep::Event {
        int id;
        Zep::Point2D position;
    public:
        TouchEndEvent(int id, Zep::Point2D position);
        int getID() const;
        Zep::Point2D getPosition() const;
    };
}

#endif
