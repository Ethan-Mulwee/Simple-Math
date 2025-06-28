#include "smath.hpp"
#include "to_string.hpp"
#include <iostream>

int main() {

    using namespace smath;

    std::cout << "\n MATRIX TESTING: \n \n";

    std::cout << "-------------------Transformation Matrix Creation----------------------- \n \n";
    
    std::cout << "Perspective Matrix: FOVY=45 ASPECT=1 NEAR=0.1 FAR=100.0 \n";
    matrix4x4 perspectiveMatrix = matrix4x4_from_perspective(45.0f, 1.0f, 0.1f, 100.0f);
    std::cout << to_string(perspectiveMatrix) << "\n \n";

    std::cout << "Translation Matrix: TRANSLATION=(1,2,3) \n";
    matrix4x4 translationMatrix = matrix4x4_from_translation(vector3{1,2,3});
    std::cout << to_string(translationMatrix) << "\n \n";

    std::cout << "-------------------Matrix3x3 Multiplication----------------------- \n \n";

    std::cout << "Matrix3x3 A: \n";
    matrix3x3 matrix3x3A = {
        1, 4, 3,
        4, 5, 6,
        7, 2, 9
    };
    std::cout << to_string(matrix3x3A) << "\n \n";

    std::cout << "Matrix3x3 B: \n";
    matrix3x3 matrix3x3B = {
        1, 4, 7,
        2, 5, 8,
        3, 9, 9
    };
    std::cout << to_string(matrix3x3B) << "\n \n";

    
    std::cout << "Matrix3x3 A * Matrix3x3 B: \n";
    std::cout << to_string(matrix3x3A*matrix3x3B) << "\n \n";
    
    std::cout << "-------------------Matrix2x2 Multiplication----------------------- \n \n";

    std::cout << "Matrix2x2 A: \n";
    matrix2x2 matrix2x2A = {
        1, 2,
        7, 4
    };
    std::cout << to_string(matrix2x2A) << "\n \n";

    std::cout << "Matrix2x2 B: \n";
    matrix2x2 matrix2x2B = {
        1, 1,
        2, 7
    };
    std::cout << to_string(matrix2x2B) << "\n \n";

    
    std::cout << "Matrix2x2 A * Matrix2x2 B: \n";
    std::cout << to_string(matrix2x2A*matrix2x2B) << "\n \n";

    std::cout << "-------------------Matrix2x2 Inverse----------------------- \n \n";

    {
    std::cout << "Matrix2x2 A: \n";
    matrix2x2 matrix2x2A = {
        1, 2,
        7, 4
    };
    std::cout << to_string(matrix2x2A) << "\n \n";
    
    std::cout << "Matrix2x2 A inverse \n";
    std::cout << to_string(inverse(matrix2x2A)) << "\n \n";
    }

    std::cout << "-------------------Matrix2x2 Change of basis----------------------- \n \n";

    std::cout << "Change of basis matrix: \n";
    matrix2x2 changeOfBasisMatrix = {
        2, -1,
        1, 1
    };
    std::cout << to_string(changeOfBasisMatrix) << "\n \n";

    std::cout << "Transformation matrix: \n";
    matrix2x2 transformationMatrix {
        0, -1,
        1, 0
    };
    std::cout << to_string(transformationMatrix) << "\n \n";

    // TODO: this seems to be wrong at the moment
    std::cout << "transformation matrix with changed basis: \n";
    std::cout << to_string(matrix2x2_change_basis(transformationMatrix, changeOfBasisMatrix)) << "\n \n";

    std::cout << "-------------------Matrix4x4 Multiplication----------------------- \n \n";

    std::cout << "Matrix4x4 A: \n";
    matrix4x4 matrix4x4A = {
        1,2,3,4,
        5,6,7,8,
        9,10,11,12,
        13,14,15,16
    };
    std::cout << to_string_pretty(matrix4x4A) << "\n \n";

    std::cout << "Matrix4x4 B: \n";
    matrix4x4 matrix4x4B = {
        1,5,9,13,
        2,6,10,14,
        3,7,11,15,
        4,8,12,16
    };
    std::cout << to_string_pretty(matrix4x4B) << "\n \n";

    std::cout << "Matrix4x4 A * Matrix4x4 B: \n";
    std::cout << to_string_pretty(matrix4x4A*matrix4x4B) << "\n \n";
}