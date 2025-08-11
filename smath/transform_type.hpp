#ifndef SMATH_TRANSFORM
#define SMATH_TRANSFORM

#include "vector_type.hpp"
#include "quaternion_type.hpp"

#include <cstddef>

namespace smath {

    struct transform {
        vector3 position;
        quaternion rotation;
        vector3 scale;
    };

}
#endif
