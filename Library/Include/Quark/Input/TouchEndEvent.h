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

namespace Quark {
    class TouchEndEvent : public Zep::Event {
        int id;
    public:
        TouchEndEvent(int id);
        int getID() const;
    };
}

#endif
