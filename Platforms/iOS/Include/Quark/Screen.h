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

#ifdef __OBJC__
@class QuarkView;
typedef QuarkView *QuarkViewPointer;
#else
typedef void *QuarkViewPointer;
#endif


namespace Quark {
    class Screen : public CommonScreen {
    private:
        QuarkViewPointer view;
    public:
        void setView(QuarkViewPointer view);
        void present();
    };
}

#endif
