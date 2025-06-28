#include "smath.hpp"
#include "to_string.hpp"
#include <iostream>

int main() {
    using namespace smath;

    std::cout << "\n VECTOR TESTING: \n";

    vector3 a = {1,2,3};
    vector3 b = {3,2,1};

    std::cout << "a = " << to_string(a) << "\n";
    std::cout << "b = " << to_string(b) << "\n";
    std::cout << "a * b = " << to_string(a*b) << "\n";

    std::cout << "\n";

}