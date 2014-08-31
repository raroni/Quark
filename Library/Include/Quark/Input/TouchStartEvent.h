//
//  TouchStartEvent.h
//  Quark
//
//  Created by Rasmus Rønn Nielsen on 31/08/14.
//  Copyright (c) 2014 Tickleworks. All rights reserved.
//

#ifndef __Quark__TouchStartEvent__
#define __Quark__TouchStartEvent__

#include "Zep/Events/Event.h"

namespace Quark {
    class TouchStartEvent : public Zep::Event {
        int id;
    public:
        TouchStartEvent(int id);
        int getID() const;
    };
}

#endif
