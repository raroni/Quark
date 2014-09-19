//
//  DragStartEvent.h
//  Quark
//
//  Created by Rasmus Rønn Nielsen on 19/09/14.
//  Copyright (c) 2014 Tickleworks. All rights reserved.
//

#ifndef __Input__DragStartEvent__
#define __Input__DragStartEvent__

#include "Zep/Events/Event.h"

namespace Quark {
    class DragStartEvent : public Zep::Event {
        int id;
    public:
        DragStartEvent(int id);
        int getID() const;
    };
}

#endif
