// temporary testing file implement proper testing with cmake later

#include "vector.hpp"
#include "matrix.hpp"
#include "to_string.hpp"
#include <iostream>

int main() {
    using namespace smath;

    float3 a = {1,2,3};
    float3 b = {3,2,1};
    float3 c = a * b;

    // std::cout << to_string(c) << "\n";

    float3x3 m = {
        34,5,0,
        0,2,0,
        0,0,3
    };

    std::cout << to_string(m) << "\n";
    std::cout << det(m) << "\n";
}