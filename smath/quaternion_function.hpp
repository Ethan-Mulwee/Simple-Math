#ifndef SMATH_QUATERNION_FUNCTION
#define SMATH_QUATERNION_FUNCTION

#include <cmath>

#include "quaternion_type.hpp"
#include "matrix_type.hpp"

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

    inline quaternion normalized(const quaternion &q) {
        float factor = 1.0f/q.length();
        return quaternion{q.x*factor, q.y*factor, q.z*factor, q.w*factor};
    }

    // TODO: Add rotate towards vector orientation? This one is weird 
    inline quaternion quaternion_add_vector(const quaternion &q, const vector3 &v) {
        return normalized(quaternion{
            q.w + 0.5f * (-v.x * q.x - v.y * q.y - v.z * q.z),
            q.x + 0.5f * (v.x * q.w + v.y * q.z - v.z * q.y),
            q.y + 0.5f * (v.y * q.w + v.z * q.x - v.x * q.z),
            q.z * 0.5f * (v.z * q.w + v.x * q.y - v.y * q.x)
        });
    }

    inline vector3 quaternion_rotate_vector(const quaternion &q, const vector3 &v) {
        return vector3{
            v.x*(q.x*q.x-q.y*q.y-q.z*q.z+q.w*q.w)+v.y*(2*q.x*q.y-2*q.w*q.z)+v.z*(2*q.x*q.z+2*q.w*q.y),
            v.x*(2*q.w*q.z+2*q.x*q.y)+v.y*(q.w*q.w-q.x*q.x+q.y*q.y-q.z*q.z)+v.z*(2*q.y*q.z-2*q.w*q.x),
            v.x*(2*q.x*q.z-2*q.w*q.y)+v.y*(2*q.w*q.x+2*q.y*q.z)+v.z*(q.w*q.w-q.x*q.x-q.y*q.y+q.z*q.z)
        };
    }

    inline matrix3x3 matrix3x3_from_quaternion(const quaternion &q) {
        matrix3x3 m;
        // i hat
        m[0][0] = q.x*q.x-q.y*q.y-q.z*q.z+q.w*q.w;
        m[1][0] = 2*q.w*q.z+2*q.x*q.y;
        m[2][0] = 2*q.x*q.z-2*q.w*q.y;
        // j hat
        m[0][1] = 2*q.x*q.y-2*q.w*q.z;
        m[1][1] = q.w*q.w-q.x*q.x+q.y*q.y-q.z*q.z;
        m[2][1] = 2*q.w*q.x+2*q.y*q.z;
        // k hat
        m[0][2] = 2*q.x*q.z+2*q.w*q.y;
        m[1][2] = 2*q.y*q.z-2*q.w*q.x;
        m[2][2] = q.w*q.w-q.x*q.x-q.y*q.y+q.z*q.z;
    
        return m;
    }
}

#endif