//
//  CommonScreen.h
//  Quark
//
//  Created by Rasmus Rønn Nielsen on 28/01/14.
//  Copyright (c) 2014 Tickleworks. All rights reserved.
//

#ifndef __Quark__CommonScreen__
#define __Quark__CommonScreen__

#include "Quark/Resolution.h"

namespace Quark {
    class CommonScreen {
        Resolution resolution;
    public:
        void setResolution(Resolution &resolution) {
            this->resolution = resolution;
        }
    };
}

#endif
