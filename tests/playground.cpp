#include "smath.hpp"
#include "smath_iostream.hpp"

int main() {
    using namespace smath;

    std::cout << "\n-------------------------------------------------------------------------- \n"
                 "                             Playground Testing                             \n"
                 "--------------------------------------------------------------------------\n\n";

    transform transformation = {
        .translation = vector3{1.0f,1.0f,2.0f},
        .rotation = quaternion_from_euler_angles_XYZ(M_PI/2.0f,M_PI/3.0f,M_PI/3.0f),
        .scale = vector3{1.0f,2.0f,1.0f}
    };

    vector3 testVector = {1.5f, 1.2f, 0.3f};

    std::cout << "Vector: " << testVector << "\n";

    // matrix4x4 transformationMatrix = matrix4x4_from_transform(transformation);
    // matrix4x4 inverseTransformationMatrix = inverse(transformationMatrix);

    // std::cout << transformationMatrix << "\n";
    // std::cout << matrix3x3_from_matrix4x4(transformationMatrix) << "\n";
    // std::cout << matrix3x3_is_orthogonal(matrix3x3_from_matrix4x4(transformationMatrix)) << "\n";

    // std::cout << inverseTransformationMatrix << "\n";
    // std::cout << matrix3x3_from_matrix4x4(inverseTransformationMatrix) << "\n";
    // std::cout << matrix3x3_is_orthogonal(matrix3x3_from_matrix4x4(inverseTransformationMatrix)) << "\n\n";

    // std::cout << testVector << "\n";
    // std::cout << "Transformed: " << matrix4x4_transform_vector3(transformationMatrix, testVector) << "\n";
    std::cout << "Transformed: " << transform_transform_vector3(transformation, testVector) << "\n";
    std::cout << "Untransformed: " << transform_inverse_transform_vector3(transformation, transform_transform_vector3(transformation, testVector)) << "\n";

    // matrix3x3 m = matrix3x3_from_quaternion(quaternion_from_euler_angles_XYZ(M_PI/2.0f,M_PI/2.3f,0.0f));
    // matrix3x3 s {
    //     2.0f,0.0f,0.0f,
    //     0.0f,3.0f,0.0f,
    //     0.0f,0.0f,1.0f
    // };
    // std::cout << m*s << "\n";
    // std::cout << matrix3x3_is_orthogonal(m*s) << "\n";
    // std::cout << inverse(m*s) << "\n";
    // std::cout << matrix3x3_is_orthogonal(inverse(m*s)) << "\n";
}