#ifndef SMATH_MATRIX_FUNCTION
#define SMATH_MATRIX_FUNCTION

#include <cmath>
#include "smath_types.hpp"
#include "vector_function.hpp"

namespace smath {

    /* -------------------------------------------------------------------------- */
    /*                                  matrix2x2                                 */
    /* -------------------------------------------------------------------------- */

    inline matrix2x2 matrix2x2_from_columns(const vector2 &x, const vector2 &y);

    inline void operator*=(matrix2x2 &m, const float s);

    inline matrix2x2 operator*(const matrix2x2 &m, const float s);

    inline matrix2x2 operator*(const float s, const matrix2x2 &m);

    inline matrix2x2 operator*(const matrix2x2 &a, const matrix2x2 &b);
    
    inline float determinant(const matrix2x2 &m);

    inline matrix2x2 transpose(const matrix2x2 &m);

    inline matrix2x2 inverse(const matrix2x2 &m);

    inline vector2 vector2_from_matrix2x2(const matrix2x2 &m, const size_t i);

    inline vector2 matrix2x2_transform_vector2(const matrix2x2 &m, const vector2 &v);

    inline matrix2x2 matrix2x2_change_basis(const matrix2x2 &m, const matrix2x2 &b);

    inline matrix2x2 matrix2x2_from_matrix2x2(const matrix2x2 &m);

    /* -------------------------------------------------------------------------- */
    /*                                 matrix3x3                                  */
    /* -------------------------------------------------------------------------- */

    // Construct matrix from column vectors
    inline matrix3x3 matrix3x3_from_columns(const vector3 &x, const vector3 &y, const vector3 &z);
    
    inline void operator*=(matrix3x3 &m, const float s);
    
    inline matrix3x3 operator*(const matrix3x3 &m, const float s);

    inline matrix3x3 operator*(const matrix3x3 &a, const matrix3x3 &b);
    
    inline float determinant(const matrix3x3 &m);

    inline matrix3x3 transpose(const matrix3x3 &m);
    
    inline matrix3x3 inverse(const matrix3x3 &m);

    // Get column vector
    inline vector3 vector3_from_matrix3x3(const matrix3x3 &m, const size_t i);

    inline vector3 matrix3x3_transform_vector3(const matrix3x3 &m, const vector3 &v);

    inline matrix3x3 matrix3x3_from_quaternion(const quaternion &q);

    inline matrix3x3 matrix3x3_from_euler(const euler_xyz &e);

    // Simple change of basis function, NOTE: this uses a inverse which could be optimzied away as a tranpose in the case of a rotation matrix
    inline matrix3x3 matrix3x3_change_basis(const matrix3x3 &matrix, const matrix3x3 &changeOfBasisMatrix);

    // for change of basis when the basis is a rotation matrix and so the inverse can be optimized to isntead be a simple tranpose
    inline matrix3x3 matrix3x3_change_basis_rotation(const matrix3x3 &m, const matrix3x3 &b);

    inline matrix3x3 matrix3x3_from_matrix4x4(const matrix4x4 &m);

    inline matrix3x3 matrix3x3_from_identity();

    inline matrix3x3 matrix3x3_from_diagonal(const float s);

    /* -------------------------------------------------------------------------- */
    /*                                 matrix4x4                                  */
    /* -------------------------------------------------------------------------- */


    inline matrix4x4 matrix4x4_from_columns(vector4 x, vector4 y, vector4 z, vector4 w);

    inline matrix4x4 operator*(const matrix4x4 &a, const matrix4x4 &b);

    inline float determinant(const matrix4x4 &m);   

    inline matrix4x4 transpose(const matrix4x4 &m);
    
    // this assumes the bottom row is 0, 0, 0, 1
    // check if in the case that you have a 3x3 rot mat and a position that inverting is not much faster via transpose?
    inline matrix4x4 invert_transform(const matrix4x4 &m);

    // Get column vector
    inline vector3 vector3_from_matrix4x4(const matrix4x4 &m, const size_t i);

    inline vector4 vector4_from_matrix4x4(const matrix4x4 &m, const size_t i);

    inline vector3 matrix4x4_transform_vector3(const matrix4x4 &m, const vector3 &v);

    inline vector4 matrix4x4_transform_vector4(const matrix4x4 &m, const vector4 &v);

    inline matrix4x4 matrix4x4_from_perspective(float fovy, float aspect, float zNear, float zFar);

    inline matrix4x4 matrix4x4_from_translation(const vector3 &v);

    inline matrix4x4 matrix4x4_from_matrix3x3(const matrix3x3 &m);

    inline matrix4x4 matrix4x4_from_identity();

    inline matrix4x4 matrix4x4_from_diagonal(const float s);

    // TODO:
    // inline matrix4x4 matrix4x4_from_quaternion(const quaternion &q) {

    // }
}

#endif