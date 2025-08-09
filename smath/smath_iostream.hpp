#ifndef SMATH_IOSTREAM
#define SMATH_IOSTREAM

#include <iostream>
#include <sstream>

#include <string>
#include "smath_types.hpp"

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

namespace smath {
    std::ostream &operator <<(std::ostream &os, const vector3 &v) {
        os << "vector3(" 
        ANSI_COLOR_RED + std::to_string(v.x) + ANSI_COLOR_RESET "," 
        ANSI_COLOR_GREEN + std::to_string(v.y) + ANSI_COLOR_RESET "," 
        ANSI_COLOR_BLUE + std::to_string(v.z) + ANSI_COLOR_RESET
        ")";
        return os;
    }
}

#endif