//
//  Exception.h
//  Zep
//
//  Created by Rasmus Rønn Nielsen on 29/01/14.
//  Copyright (c) 2014 Tickleworks. All rights reserved.
//

#ifndef __Zep__Exception__
#define __Zep__Exception__

#include <stdexcept>
#include <string>

namespace Quark {
    class Exception : public std::runtime_error {
    public:
        Exception(std::string const &message);
    };
}

#endif
