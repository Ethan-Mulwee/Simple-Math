#ifndef SIMPLE_TO_STRING
#define SIMPLE_TO_STRING

#include <string>
#include "vector.hpp"

namespace smath {
    std::string to_string(const float3 &v) {
        return "(" + std::to_string(v.x) + "," + std::to_string(v.y) + "," + std::to_string(v.z) + ")";
    }

    std::string to_string(const float3x3 &m) {
        return 
        "|" + std::to_string(m[0][0]) + ", " + std::to_string(m[0][1]) + ", " + std::to_string(m[0][2]) + "| \n" +
        "|" + std::to_string(m[1][0]) + ", " + std::to_string(m[1][1]) + ", " + std::to_string(m[1][2]) + "| \n" +
        "|" + std::to_string(m[2][0]) + ", " + std::to_string(m[2][1]) + ", " + std::to_string(m[2][2]) + "| \n";
    }
}

#endif