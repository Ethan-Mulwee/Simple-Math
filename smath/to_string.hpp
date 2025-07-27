#ifndef SMATH_TO_STRING
#define SMATH_TO_STRING

#include <string>
#include "vector_type.hpp"
#include "matrix_type.hpp"

namespace smath {
    std::string to_string(const vector3 &v) {
        return "(" + std::to_string(v.x) + "," + std::to_string(v.y) + "," + std::to_string(v.z) + ")";
    }

    std::string to_string(const matrix2x2 &m) {
        return
            "|" + std::to_string(m[0][0]) + ", " + std::to_string(m[0][1]) + "| \n" +
            "|" + std::to_string(m[1][0]) + ", " + std::to_string(m[1][1]) + "| \n";
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
            "|" + std::to_string(m[3][0]) + ", " + std::to_string(m[3][1]) + ", " + std::to_string(m[3][2]) + ", " + std::to_string(m[3][3]) + "|";
    }

    std::string to_string_pretty(const matrix4x4 &m) {
        unsigned longest = 0;

        std::string strings[4][4];

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                unsigned length = std::to_string(m[i][j]).length();
                if (length > longest) {
                    longest = length;
                }
            }
        }

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                std::string str = std::to_string(m[i][j]);
                while (str.length() < longest) {
                    str += "0";
                }
                strings[i][j] = str;
            }
        }

        return
            "|" + strings[0][0] + ", " + strings[0][1] + ", " + strings[0][2] + ", " + strings[0][3] + "| \n" +
            "|" + strings[1][0] + ", " + strings[1][1] + ", " + strings[1][2] + ", " + strings[1][3] + "| \n" +
            "|" + strings[2][0] + ", " + strings[2][1] + ", " + strings[2][2] + ", " + strings[2][3] + "| \n" +
            "|" + strings[3][0] + ", " + strings[3][1] + ", " + strings[3][2] + ", " + strings[3][3] + "|";
    }

    std::string to_string(const quaternion &q) {
        return "( x:" + std::to_string(q.x) + ", y:" + std::to_string(q.y) + ", z:" + std::to_string(q.z) + ", w:" + std::to_string(q.w) + ")";
    }
}

#endif