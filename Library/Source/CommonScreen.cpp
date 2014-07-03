//
//  CommonScreen.cpp
//  Quark
//
//  Created by Rasmus Rønn Nielsen on 28/01/14.
//  Copyright (c) 2014 Tickleworks. All rights reserved.
//

#include "Quark/CommonScreen.h"

namespace Quark {
    void CommonScreen::setResolution(Resolution &resolution) {
        this->resolution = resolution;
    }
    
    const Resolution& CommonScreen::getResolution() const {
        return resolution;
    }
    
    float CommonScreen::getAspectRatio() const {
        return static_cast<float>(resolution.width) / static_cast<float>(resolution.height);
    }
}
