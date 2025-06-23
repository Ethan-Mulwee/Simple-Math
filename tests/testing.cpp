// temporary testing file implement proper testing with cmake later

#include "smath.hpp"
#include "to_string.hpp"
#include <iostream>

int main() {
    using namespace smath;

    vector3 a = {1,2,3};
    vector3 b = {3,2,1};
    vector3 c = a * b;

    // std::cout << to_string(c) << "\n";

    matrix4x4 m = {
        34,5,0,1,
        0,2,0,2,
        0,0,3,3,
        0,0,0,1
    };


    std::cout << to_string(m) << "\n";
    std::cout << to_string(transpose(m)) << "\n";

}