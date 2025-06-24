#ifndef SMATH_AXIS_ANGLE_TYPE
#define SMATH_AXIS_ANGLE_TYPE

#include "vector_type.hpp"

namespace smath {
    struct axis_angle {
        float angle;
        vector3 axis;
    };
}

#endif