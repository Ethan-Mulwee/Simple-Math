#ifndef SMATH_QUATERNION_FUNCTION
#define SMATH_QUATERNION_FUNCTION

#include <cmath>

#include "quaternion_type.hpp"

namespace smath{
    // Multiply quaternions
    inline quaternion operator*(const quaternion &q, const quaternion &p) {
        return quaternion{
            q.w*p.w-q.x*p.x-q.y*p.y-q.z*p.z,
            q.w*p.x+q.x*p.w+q.y*p.z-q.z*p.y,
            q.w*p.y-q.x*p.z+q.y*p.w+q.z*p.x,
            q.w*p.z+q.x*p.y-q.y*p.x+q.z*p.w
        };
    }

    // Multiply quaternion by scalar
    inline quaternion operator*(const quaternion &q, const float s) {
        return quaternion{q.x*s, q.y*s, q.z*s, q.w*s};
    }

    // Add rotation of a vector interpreted as a rotation
    inline quaternion quaternion_add_vector() {
        
    }
}

#endif