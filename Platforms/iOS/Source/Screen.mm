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
    void Screen::setView(QuarkViewPointer view) {
        this->view = view;
    }
    
    void Screen::present() {
        [view present];
    }
}
