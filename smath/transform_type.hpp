#ifndef SMATH_TRANSFORM_TYPE
#define SMATH_TRANSFORM_TYPE

#include "vector_type.hpp"
#include "quaternion_type.hpp"
#include "matrix_type.hpp"

namespace smath {

    struct transform {
        vector3 translation;
        quaternion rotation;
        vector3 scale;
    };

}
#endif
