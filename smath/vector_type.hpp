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

    struct vector3 {
        union {
            float data[3];
            struct {
                float x,y,z;
            };
        };
    
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
    
}



#endif