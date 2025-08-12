#include "smath.hpp"
#include "smath_iostream.hpp"

int main() {
    using namespace smath;

    std::cout << "\n-------------------------------------------------------------------------- \n"
                 "                              Transform Testing                              \n"
                 "--------------------------------------------------------------------------\n\n";

    transform t = {
        .translation = vector3{1.0f,1.0f,2.0f},
        .rotation = quaternion_from_euler_angles_XYZ(M_PI/2.0f,0.0f,0.0f),
        .scale = vector3{1.0f,1.0f,1.0f}
    };

    transform inverseTransform = inverse(t);

    vector3 v = {0.0f,1.0f,0.0f};

    vector3 transformedVector = transform_transform_vector3(t,v);

    std::cout << "Transform: " << t << "\n";
    std::cout << "Vector: " << v << "\n";

    std::cout << "Transformed Vector: " << transformedVector << "\n\n";

    matrix4x4 transformationMatrix = matrix4x4_from_transform(t);
    
    std::cout << "Transform to Matrix: " << transformationMatrix << "\n";
    std::cout << "Transformed Vector from Matrix: " << matrix4x4_transform_vector3(transformationMatrix, v) << "\n\n";

    std::cout << "Matrix to Transform: " << transform_from_matrix4x4(transformationMatrix) << "\n";

    std::cout << "Inverse Transform: " << inverseTransform << "\n";

    std::cout << "Untransformed Vector: " << transform_transform_vector3(inverseTransform, transformedVector) << "\n";
}