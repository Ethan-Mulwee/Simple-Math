#ifndef SIMPLE_MATRIX
#define SIMPLE_MATRIX

#include <cmath>

namespace smath {
    struct float3x3 {
        float data[3][3];
    
        inline float* operator[](const size_t i) {
            return data[i];
        }

        inline const float* operator[](const size_t i) const {
            return data[i];
        }
    };

    inline float det(const float3x3 &m) {
        // a(ei-fh)
        float t1 = m[0][0]*(m[1][1]*m[2][2]-m[1][2]*m[2][1]);
        // b(di-fg)
        float t2 = m[0][1]*(m[1][0]*m[2][2]-m[1][2]*m[2][0]);
        // c(dh-eg)
        float t3 = m[0][2]*(m[1][0]*m[2][1]-m[1][1]*m[2][0]);
        
        return t1-t2-t3;
    }

    inline float3x3 inverse(const float3x3 &m) {

    }
}

#endif
