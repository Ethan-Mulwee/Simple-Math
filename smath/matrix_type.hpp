#ifndef SMATH_MATRIX
#define SMATH_MATRIX

#include "vector_type.hpp"
#include <cstddef>

namespace smath {

    struct matrix2x2 {
        union {
            vector2 data[2];
            struct {
                vector2 i, j;
            };
        };

        inline vector2& operator[](const size_t i) {
            return data[i];
        }

        inline const vector2& operator[](const size_t i) const {
            return data[i];
        }
    };
    struct matrix3x3 {
        union {
            vector3 data[3];
            struct {
                vector3 i,j,k;
            };
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
            vector4 data[4];
            struct {
                vector4 i, j, k, l;
            };
        };

        inline vector4& operator[](const size_t i) {
            return data[i];
        }

        inline const vector4& operator[](const size_t i) const {
            return data[i];
        }
    };

}
#endif
