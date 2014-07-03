//
//  ProjectionFactory.h
//  Quark
//
//  Created by Rasmus Rønn Nielsen on 03/07/14.
//  Copyright (c) 2014 Tickleworks. All rights reserved.
//

#ifndef __Quark__ProjectionFactory__
#define __Quark__ProjectionFactory__

namespace Zep {
    class Matrix4;
}

namespace Quark {
    namespace ProjectionFactory {
        Zep::Matrix4 perspective(float fieldOfView, float aspectRatio, float near, float far);
    }
}

#endif
