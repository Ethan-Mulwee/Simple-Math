#ifndef SMATH_MATRIX
#define SMATH_MATRIX

#include "vector_type.hpp"
#include <cstddef>

namespace smath {

    struct matrix2x2 {
        float data[2][2];

        inline float* operator[](const size_t i) {
            return data[i];
        }

        inline const float* operator[](const size_t i) const {
            return data[i];
        }
    };
    struct matrix3x3 {
        union {
            struct {
                vector3 i,j,k;
            };
            vector3 data[3];
        };
        
        inline vector3& operator[](const size_t i) {
            return data[i];
        }

        inline const vector3& operator[](const size_t i) const {
            return data[i];
        }
    };

    struct matrix4x4 {
        union {
            struct {
                vector4 i, j, k, l;
            };
            float data[4][4];
        };

        inline float* operator[](const size_t i) {
            return data[i];
        }

        inline const float* operator[](const size_t i) const {
            return data[i];
        }
    };

}
#endif
