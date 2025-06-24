#include "smath.hpp"
#include "to_string.hpp"
#include <iostream>

int main() {

    using namespace smath;

    std::cout << "\n MATRIX TESTING: \n";

    
    std::cout << "Perspective Matrix: FOVY=45 ASPECT=1 NEAR=0.1 FAR=100.0 \n";
    matrix4x4 perspectiveMatrix = matrix4x4_from_perspective(45.0f, 1.0f, 0.1f, 100.0f);
    std::cout << to_string(perspectiveMatrix) << "\n \n";

    std::cout << "Translation Matrix: TRANSLATION=(1,2,3) \n";
    matrix4x4 translationMatrix = matrix4x4_from_translation(vector3{1,2,3});
    std::cout << to_string(translationMatrix) << "\n \n";

}