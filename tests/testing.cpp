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

    std::cout << to_string(c) << "\n";

    float3x3 m = {
        1,1,0,
        0,1,0,
        0,0,1
    };

    std::cout << to_string(m) << "\n";
}