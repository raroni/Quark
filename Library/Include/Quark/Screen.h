//
//  Screen.h
//  Quark
//
//  Created by Rasmus Rønn Nielsen on 28/01/14.
//  Copyright (c) 2014 Tickleworks. All rights reserved.
//

#ifndef __Quark__Screen__
#define __Quark__Screen__

#include "Quark/Resolution.h"

namespace Quark {
    class Screen {
        Resolution resolution;
    public:
        void setResolution(Resolution &resolution) {
            this->resolution = resolution;
        }
    };
}

#endif
