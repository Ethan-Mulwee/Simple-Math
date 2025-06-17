#ifndef SIMPLE_VECTOR
#define SIMPLE_VECTOR

#include <cmath>


namespace smath {

    struct float2 {
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
    
    inline float2 operator+(const float2 &a, const float2 &b) {
        return float2{a.x+b.x, a.y+b.y};
    }

    inline float2 operator-(const float2 &a, const float2 &b) {
        return float2{a.x-b.x, a.y-b.y};
    }

    // Component-wise multipication of two vectors
    inline float2 operator*(const float2 &a, const float2 &b) {
        return float2{a.x*b.x, a.y*b.y};
    }

    // Scale vector by a scalar
    inline float2 operator*(const float2 &v, const float s) {
        return float2{v.x*s, v.y*s};
    }

    // Scale vector by a scalar
    inline float2 operator*(const float s, const float2 &v) {
        return float2{v.x*s, v.y*s};
    }


    inline float2 operator/(const float2 &a, const float2 &b) {
        return float2{a.x/b.x, a.y/b.y};
    }

    inline float dot(const float2 &a, const float2 &b) {
        return a.x*b.x+a.y*b.y;
    }

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

    struct float4 {
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

    inline float4 operator+(const float4 &a, const float4 &b) {
        return float4{a.x+b.x, a.y+b.y, a.z+b.z, a.w+b.w};
    }

    inline float4 operator-(const float4 &a, const float4 &b) {
        return float4{a.x-b.x, a.y-b.y, a.z-b.z, a.w-b.w};
    }

    // Component-wise multipication of two vectors
    inline float4 operator*(const float4 &a, const float4 &b) {
        return float4{a.x*b.x, a.y*b.y, a.z*b.z, a.w*b.w};
    }

    // Scale vector by a scalar
    inline float4 operator*(const float4 &v, const float s) {
        return float4{v.x*s, v.y*s, v.z*s, v.w*s};
    }

    // Scale vector by a scalar
    inline float4 operator*(const float s, const float4 &v) {
        return float4{v.x*s, v.y*s, v.z*s, v.w*s};
    }


    inline float4 operator/(const float4 &a, const float4 &b) {
        return float4{a.x/b.x, a.y/b.y, a.z/b.z, a.w/b.w};
    }

    inline float dot(const float4 &a, const float4 &b) {
        return a.x*b.x+a.y*b.y+a.z*b.z+a.w*b.w;
    }

}



#endif