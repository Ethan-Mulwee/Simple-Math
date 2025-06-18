#ifndef SMATH_VECTOR
#define SMATH_VECTOR

#include <cmath>


namespace smath {

    struct vector2 {
        float x,y;
    
        inline float length() const {
            return sqrt(x*x+y*y);
        }
    
        inline float square_length() const {
            return x*x+y*y;
        }
    
        void normalize() {
            float factor = 1.0f/(*this).length();
            x *= factor; y *= factor;
        }
    };
    
    inline vector2 operator+(const vector2 &a, const vector2 &b) {
        return vector2{a.x+b.x, a.y+b.y};
    }

    inline vector2 operator-(const vector2 &a, const vector2 &b) {
        return vector2{a.x-b.x, a.y-b.y};
    }

    // Component-wise multipication of two vectors
    inline vector2 operator*(const vector2 &a, const vector2 &b) {
        return vector2{a.x*b.x, a.y*b.y};
    }

    // Scale vector by a scalar
    inline vector2 operator*(const vector2 &v, const float s) {
        return vector2{v.x*s, v.y*s};
    }

    // Scale vector by a scalar
    inline vector2 operator*(const float s, const vector2 &v) {
        return vector2{v.x*s, v.y*s};
    }


    inline vector2 operator/(const vector2 &a, const vector2 &b) {
        return vector2{a.x/b.x, a.y/b.y};
    }

    inline float dot(const vector2 &a, const vector2 &b) {
        return a.x*b.x+a.y*b.y;
    }

    struct vector3 {
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
    
    inline vector3 operator+(const vector3 &a, const vector3 &b) {
        return vector3{a.x+b.x, a.y+b.y, a.z+b.z};
    }

    inline vector3 operator-(const vector3 &a, const vector3 &b) {
        return vector3{a.x-b.x, a.y-b.y, a.z-b.z};
    }

    // Component-wise multipication of two vectors
    inline vector3 operator*(const vector3 &a, const vector3 &b) {
        return vector3{a.x*b.x, a.y*b.y, a.z*b.z};
    }

    // Scale vector by a scalar
    inline vector3 operator*(const vector3 &v, const float s) {
        return vector3{v.x*s, v.y*s, v.z*s};
    }

    // Scale vector by a scalar
    inline vector3 operator*(const float s, const vector3 &v) {
        return vector3{v.x*s, v.y*s, v.z*s};
    }


    inline vector3 operator/(const vector3 &a, const vector3 &b) {
        return vector3{a.x/b.x, a.y/b.y, a.z/b.z};
    }

    inline float dot(const vector3 &a, const vector3 &b) {
        return a.x*b.x+a.y*b.y+a.z*b.z;
    }

    inline vector3 cross(const vector3 &a, const vector3 &b) {
        return vector3{
            a.y * b.z - a.z * b.y,
            a.z * b.x - a.x * b.z, 
            a.x * b.y - a.y * b.x
        };
    }

    inline vector3 project(const vector3 &a, const vector3 &b) {
        return (dot(a,b)/dot(b,b))*b;
    }

    struct vector4 {
        float x, y, z, w;

        inline float length() const {
            return sqrt(x*x+y*y+z*z+w*w);
        }

        inline float square_length() const {
            return x*x+y*y+z*z+w*w;
        }

        void normalize() {
            float factor = 1.0f/(*this).length();
            x *= factor; y *= factor; z *= factor; w *= factor;
        }
    };

    inline vector4 operator+(const vector4 &a, const vector4 &b) {
        return vector4{a.x+b.x, a.y+b.y, a.z+b.z, a.w+b.w};
    }

    inline vector4 operator-(const vector4 &a, const vector4 &b) {
        return vector4{a.x-b.x, a.y-b.y, a.z-b.z, a.w-b.w};
    }

    // Component-wise multipication of two vectors
    inline vector4 operator*(const vector4 &a, const vector4 &b) {
        return vector4{a.x*b.x, a.y*b.y, a.z*b.z, a.w*b.w};
    }

    // Scale vector by a scalar
    inline vector4 operator*(const vector4 &v, const float s) {
        return vector4{v.x*s, v.y*s, v.z*s, v.w*s};
    }

    // Scale vector by a scalar
    inline vector4 operator*(const float s, const vector4 &v) {
        return vector4{v.x*s, v.y*s, v.z*s, v.w*s};
    }


    inline vector4 operator/(const vector4 &a, const vector4 &b) {
        return vector4{a.x/b.x, a.y/b.y, a.z/b.z, a.w/b.w};
    }

    inline float dot(const vector4 &a, const vector4 &b) {
        return a.x*b.x+a.y*b.y+a.z*b.z+a.w*b.w;
    }

}



#endif