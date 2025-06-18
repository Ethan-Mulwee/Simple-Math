#ifndef SMATH_MATRIX
#define SMATH_MATRIX

#include <cstddef>

namespace smath {
    struct matrix3x3 {
        float data[3][3];
        
        inline float* operator[](const size_t i) {
            return data[i];
        }

        inline const float* operator[](const size_t i) const {
            return data[i];
        }
    };

    struct matrix4x4 {
        float data[4][4];

        inline float* operator[](const size_t i) {
            return data[i];
        }

        inline const float* operator[](const size_t i) const {
            return data[i];
        }
    };
}
#endif
