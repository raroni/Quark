//
//  Screen.cpp
//  Quark
//
//  Created by Rasmus Rønn Nielsen on 02/07/14.
//  Copyright (c) 2014 Tickleworks. All rights reserved.
//

#include "Quark/Screen.h"
#include "Quark/iOS/View.h"

namespace Quark {
    void Screen::setView(void *view) {
        this->view = view;
    }
    
    void Screen::present() {
        [((__bridge QuarkView*)view) present];
    }
}
