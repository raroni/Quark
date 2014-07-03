//
//  ProjectionFactory.cpp
//  Quark
//
//  Created by Rasmus Rønn Nielsen on 03/07/14.
//  Copyright (c) 2014 Tickleworks. All rights reserved.
//

#include <math.h>
#include "Zep/Math/Matrix4.h"
#include "ProjectionFactory.h"

namespace Quark {
    namespace ProjectionFactory {
        Zep::Matrix4 perspective(float fieldOfView, float aspectRatio, float near, float far) {
            Zep::Matrix4 matrix;
            
            float halfFovTangent = tan(fieldOfView/2);
            
            matrix[0] = 1/halfFovTangent;
            matrix[5] = aspectRatio/halfFovTangent;
            matrix[10] = (far + near) / (far - near);
            matrix[11] = 1;
            matrix[14] = -(2*far*near)/(far-near);
            
            return matrix;
        }
    }
}
