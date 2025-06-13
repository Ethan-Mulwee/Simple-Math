#ifndef SIMPLE_VECTOR
#define SIMPLE_VECTOR

#include <cmath>


namespace smath {
    struct float3 {
        float x,y,z;
    
        inline float length() const {
            return sqrt(x*x+y*y+z*z);
        }
    
        inline float square_length() const {
            return x*x+y*y+z*z;
        }
    
        void normalize() {
            float factor = 1.0f/(*this).length();
            x *= factor; y *= factor; z *= factor;
        }
    };
    
    inline float3 operator+(const float3 &a, const float3 &b) {
        return float3{a.x+b.x, a.y+b.y, a.z+b.z};
    }

    inline float3 operator-(const float3 &a, const float3 &b) {
        return float3{a.x-b.x, a.y-b.y, a.z-b.z};
    }

    // Component-wise multipication of two vectors
    inline float3 operator*(const float3 &a, const float3 &b) {
        return float3{a.x*b.x, a.y*b.y, a.z*b.z};
    }

    // Scale vector by a scalar
    inline float3 operator*(const float3 &v, const float s) {
        return float3{v.x*s, v.y*s, v.z*s};
    }

        // Scale vector by a scalar
    inline float3 operator*(const float s, const float3 &v) {
        return float3{v.x*s, v.y*s, v.z*s};
    }


    inline float3 operator/(const float3 &a, const float3 &b) {
        return float3{a.x/b.x, a.y/b.y, a.z/b.z};
    }

    

    inline float dot(const float3 &a, const float3 &b) {
        return a.x*b.x+a.y*b.y+a.z*b.z;
    }

    inline float3 cross(const float3 &a, const float3 &b) {
        return float3{
            a.y * b.z - a.z * b.y,
            a.z * b.x - a.x * b.z, 
            a.x * b.y - a.y * b.x
        };
    }

    inline float3 project(const float3 &a, const float3 &b) {
        return (dot(a,b)/dot(b,b))*b;
    }
}



#endif