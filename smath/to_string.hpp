#ifndef SMATH_TO_STRING
#define SMATH_TO_STRING

#include <string>
#include "vector_type.hpp"
#include "matrix_type.hpp"

namespace smath {
    std::string to_string(const vector3 &v) {
        return "(" + std::to_string(v.x) + "," + std::to_string(v.y) + "," + std::to_string(v.z) + ")";
    }

    std::string to_string(const matrix3x3 &m) {
        return 
            "|" + std::to_string(m[0][0]) + ", " + std::to_string(m[0][1]) + ", " + std::to_string(m[0][2]) + "| \n" +
            "|" + std::to_string(m[1][0]) + ", " + std::to_string(m[1][1]) + ", " + std::to_string(m[1][2]) + "| \n" +
            "|" + std::to_string(m[2][0]) + ", " + std::to_string(m[2][1]) + ", " + std::to_string(m[2][2]) + "| \n";
    }

    std::string to_string(const matrix4x4 &m) {
        return
            "|" + std::to_string(m[0][0]) + ", " + std::to_string(m[0][1]) + ", " + std::to_string(m[0][2]) + ", " + std::to_string(m[0][3]) + "| \n" +
            "|" + std::to_string(m[1][0]) + ", " + std::to_string(m[1][1]) + ", " + std::to_string(m[1][2]) + ", " + std::to_string(m[1][3]) + "| \n" +
            "|" + std::to_string(m[2][0]) + ", " + std::to_string(m[2][1]) + ", " + std::to_string(m[2][2]) + ", " + std::to_string(m[2][3]) + "| \n" +
            "|" + std::to_string(m[3][0]) + ", " + std::to_string(m[3][1]) + ", " + std::to_string(m[3][2]) + ", " + std::to_string(m[3][3]) + "| \n";
    }
}

#endif