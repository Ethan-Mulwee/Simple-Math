#ifndef SMATH_TRANSFORM_FUNCTION
#define SMATH_TRANSFORM_FUNCTION

#include "transform_type.hpp"
#include "vector_function.hpp"
#include "quaternion_function.hpp"

namespace smath {

    // TODO: correctly invert scale
    inline transform inverse(const transform &t) {
        transform inverseTransform;
        inverseTransform.scale = 1.0f / t.scale;
        inverseTransform.rotation = inverse(t.rotation);
        // inverseTransform.translation = -1.0f * quaternion_transform_vector(inverseTransform.rotation, inverseTransform.scale * t.translation);
        inverseTransform.translation = -1.0f * quaternion_transform_vector(inverseTransform.rotation, t.translation);

        return inverseTransform;
    }

    inline vector3 transform_transform_vector3(const transform &t, const vector3 &v) {
        vector3 transformedVector = v;
        transformedVector = transformedVector * t.scale;
        transformedVector = quaternion_transform_vector(t.rotation, transformedVector);
        transformedVector = transformedVector + t.translation;

        return transformedVector;
    }

    inline matrix4x4 matrix4x4_from_transform(const transform &t) {
        matrix3x3 rotationMatrix = matrix3x3_from_quaternion(t.rotation);
        matrix3x3 scaleMatrix = {
            t.scale.x, 0.0f, 0.0f,
            0.0f, t.scale.y, 0.0f,
            0.0f, 0.0f, t.scale.z
        };

        matrix4x4 transformMatrix = matrix4x4_from_matrix3x3(rotationMatrix*scaleMatrix);
        transformMatrix[0][3] = t.translation.x;
        transformMatrix[1][3] = t.translation.y;
        transformMatrix[2][3] = t.translation.z;

        return transformMatrix;
    }

}

#endif