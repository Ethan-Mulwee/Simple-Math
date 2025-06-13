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

    float det(const float3x3 &m) {
        // a(ei-fh)
        float t1 = 
        // b(di-fg)

        // c(dh-eg)

        // t1-t2-t3
        return
    }
}

#endif
