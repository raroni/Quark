//
//  Screen.h
//  Quark
//
//  Created by Rasmus Rønn Nielsen on 02/07/14.
//  Copyright (c) 2014 Tickleworks. All rights reserved.
//

#ifndef __Quark__Screen__
#define __Quark__Screen__

#include "Quark/CommonScreen.h"

namespace Quark {
    class Screen : public CommonScreen {
        void *view;
    public:
        void setView(void *view);
        void present();
    };
}

#endif
