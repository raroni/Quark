//
//  TouchStartEvent.h
//  Quark
//
//  Created by Rasmus Rønn Nielsen on 31/08/14.
//  Copyright (c) 2014 Tickleworks. All rights reserved.
//

#ifndef __Quark__TouchStartEvent__
#define __Quark__TouchStartEvent__

#include "Zep/Geometry/Point2D.h"
#include "Zep/Events/Event.h"

namespace Quark {
    class TouchStartEvent : public Zep::Event {
        int id;
        Zep::Point2D position;
    public:
        TouchStartEvent(int id, Zep::Point2D position);
        int getID() const;
        Zep::Point2D getPosition() const;
    };
}

#endif
