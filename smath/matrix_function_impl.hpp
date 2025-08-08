#ifndef SMATH_MATRIX_FUNCTION_IMPL
#define SMATH_MATRIX_FUNCTION_IMPL

#include <cmath>

#include "smath_types.hpp"
#include "matrix_function.hpp"
#include "vector_function.hpp"

namespace smath {

    /* -------------------------------------------------------------------------- */
    /*                                  matrix2x2                                 */
    /* -------------------------------------------------------------------------- */

    matrix2x2 matrix2x2_from_columns(const vector2 &x, const vector2 &y) {
        return matrix2x2{
            x.x, y.x,
            x.y, y.y
        };
    }

    void operator*=(matrix2x2 &m, const float s) {
        m[0][0] *= s; m[0][1] *= s;
        m[1][0] *= s; m[1][1] *= s;
    }

    matrix2x2 operator*(const matrix2x2 &m, const float s) {
        return matrix2x2{
            m[0][0] * s, m[0][1] * s,
            m[1][0] * s, m[1][1] * s
        };
    }

    matrix2x2 operator*(const float s, const matrix2x2 &m) {
        return matrix2x2{
            m[0][0] * s, m[0][1] * s,
            m[1][0] * s, m[1][1] * s
        };
    }

    matrix2x2 operator*(const matrix2x2 &a, const matrix2x2 &b) {
        vector2 ihat = vector2_from_matrix2x2(b, 0);
        vector2 jhat = vector2_from_matrix2x2(b, 1);

        ihat = matrix2x2_transform_vector2(a, ihat);
        jhat = matrix2x2_transform_vector2(a, jhat);

        return matrix2x2_from_columns(ihat, jhat);
    }

    matrix2x2 inverse(const matrix2x2 &m) {
        float factor = 1.0f/(m[0][0]*m[1][1]-m[0][1]*m[1][0]);

        return factor * matrix2x2{
            m[1][1], -m[0][1],
            -m[1][0], m[0][0]
        };
    }

    vector2 vector2_from_matrix2x2(const matrix2x2 &m, const size_t i)
    {
        return vector2{m[0][i], m[1][i]};
    }

    vector2 matrix2x2_transform_vector2(const matrix2x2 &m, const vector2 &v) {
        vector2 x = v.x * vector2_from_matrix2x2(m,0);
        vector2 y = v.y * vector2_from_matrix2x2(m,1);

        return x + y;
    }

    matrix2x2 matrix2x2_change_basis(const matrix2x2 &m, const matrix2x2 &b) {
        return inverse(b)*m*b;
    }

    /* -------------------------------------------------------------------------- */
    /*                                 matrix3x3                                  */
    /* -------------------------------------------------------------------------- */

    // Construct matrix from column vectors
    inline matrix3x3 matrix3x3_from_columns(const vector3 &x, const vector3 &y, const vector3 &z) {
        return matrix3x3 {
            x.x, y.x, z.x,
            x.y, y.y, z.y,
            x.z, y.z, z.z
        };
    }
    
    inline void operator*=(matrix3x3 &m, const float s) {
        m[0][0] *= s; m[0][1] *= s; m[0][2] *= s;
        m[1][0] *= s; m[1][1] *= s; m[1][2] *= s;
        m[2][0] *= s; m[2][1] *= s; m[2][2] *= s;
    }
    
    inline matrix3x3 operator*(const matrix3x3 &m, const float s) {
        return matrix3x3{
            m[0][0] * s, m[0][1] * s, m[0][2] * s,
            m[1][0] * s, m[1][1] * s, m[1][2] * s,
            m[2][0] * s, m[2][1] * s, m[2][2] * s
        };
    }

    inline matrix3x3 operator*(const matrix3x3 &a, const matrix3x3 &b) {
        vector3 ihat = vector3_from_matrix3x3(b, 0);
        vector3 jhat = vector3_from_matrix3x3(b, 1);
        vector3 khat = vector3_from_matrix3x3(b, 2);

        ihat = matrix3x3_transform_vector3(a, ihat);
        jhat = matrix3x3_transform_vector3(a, jhat);
        khat = matrix3x3_transform_vector3(a, khat);

        return matrix3x3_from_columns(ihat, jhat, khat);
    }
    
    inline float determinant(const matrix3x3 &m) {
        // a(ei-fh)
        float t1 = m[0][0]*(m[1][1]*m[2][2]-m[1][2]*m[2][1]);
        // b(di-fg)
        float t2 = m[0][1]*(m[1][0]*m[2][2]-m[1][2]*m[2][0]);
        // c(dh-eg)
        float t3 = m[0][2]*(m[1][0]*m[2][1]-m[1][1]*m[2][0]);
        
        return t1-t2+t3;
    }

    inline matrix3x3 transpose(const matrix3x3 &m) {
        return {
            m[0][0], m[1][0], m[2][0],
            m[0][1], m[1][1], m[2][1],
            m[0][2], m[1][2], m[2][2],
        };
    }
    
    inline matrix3x3 inverse(const matrix3x3 &m) {
        // took this from glm
        float OneOverDeterminant = 1.0f / (
            +m[0][0] * (m[1][1] * m[2][2] - m[2][1] * m[1][2])
            - m[1][0] * (m[0][1] * m[2][2] - m[2][1] * m[0][2])
            + m[2][0] * (m[0][1] * m[1][2] - m[1][1] * m[0][2])
        );
            
        matrix3x3 inverse;
        inverse[0][0] = +(m[1][1] * m[2][2] - m[2][1] * m[1][2]);
        inverse[1][0] = -(m[1][0] * m[2][2] - m[2][0] * m[1][2]);
        inverse[2][0] = +(m[1][0] * m[2][1] - m[2][0] * m[1][1]);
        inverse[0][1] = -(m[0][1] * m[2][2] - m[2][1] * m[0][2]);
        inverse[1][1] = +(m[0][0] * m[2][2] - m[2][0] * m[0][2]);
        inverse[2][1] = -(m[0][0] * m[2][1] - m[2][0] * m[0][1]);
        inverse[0][2] = +(m[0][1] * m[1][2] - m[1][1] * m[0][2]);
        inverse[1][2] = -(m[0][0] * m[1][2] - m[1][0] * m[0][2]);
        inverse[2][2] = +(m[0][0] * m[1][1] - m[1][0] * m[0][1]);
        
        inverse *= OneOverDeterminant;
        return inverse;
    }

    // Get column vector
    inline vector3 vector3_from_matrix3x3(const matrix3x3 &m, const size_t i) {
        return vector3{m[0][i], m[1][i], m[2][i]};
    }

    inline vector3 matrix3x3_transform_vector3(const matrix3x3 &m, const vector3 &v) {
        vector3 x = v.x*vector3_from_matrix3x3(m,0);
        vector3 y = v.y*vector3_from_matrix3x3(m,1);
        vector3 z = v.z*vector3_from_matrix3x3(m,2);
        return x+y+z;
    }

    inline matrix3x3 matrix3x3_from_quaternion(const quaternion &q) {
        matrix3x3 m;

        // i hat
        m[0][0] = 2.0f * (q.x*q.x + q.y*q.y)-1.0f;
        m[1][0] = 2.0f * (q.y*q.z + q.x*q.w);
        m[2][0] = 2.0f * (q.y*q.w - q.x*q.z);
        // j hat
        m[0][1] = 2.0f * (q.y*q.z - q.x*q.w);
        m[1][1] = 2.0f * (q.x*q.x + q.z*q.z) - 1.0f;
        m[2][1] = 2.0f * (q.z*q.w + q.x*q.y);
        // k hat
        m[0][2] = 2.0f * (q.y*q.w + q.x*q.z);
        m[1][2] = 2.0f * (q.z*q.w - q.x*q.y);
        m[2][2] = 2.0f * (q.x*q.x + q.w*q.w) - 1.0f;
    
        return m;
    }

    // TODO:
    // inline matrix3x3 matrix3x3_from_euler(const euler_xyz &e) {

    // }

    // returns matrix in a different basis
    matrix3x3 matrix3x3_change_basis(const matrix3x3 &matrix, const matrix3x3 &changeOfBasisMatrix) {
        return inverse(changeOfBasisMatrix)*matrix*changeOfBasisMatrix;
    }

    matrix3x3 matrix3x3_change_basis_rotation(const matrix3x3 &m, const matrix3x3 &b) {
        return transpose(b)*m*b;
    }

    inline matrix3x3 matrix3x3_from_matrix4x4(const matrix4x4 &m) {
        return matrix3x3{
            m[0][0], m[0][1], m[0][2],
            m[1][0], m[1][1], m[1][2],
            m[2][0], m[2][1], m[2][2]
        };
    }

    matrix3x3 matrix3x3_from_identity() {
        return matrix3x3{
            1.0f, 0.0f, 0.0f,
            0.0f, 1.0f, 0.0f,
            0.0f, 0.0f, 1.0f
        };
    }

    matrix3x3 matrix3x3_from_diagonal(const float s) {
        return matrix3x3{
            s, 0.0f, 0.0f,
            0.0f, s, 0.0f,
            0.0f, 0.0f, s
        };
    }

    /* -------------------------------------------------------------------------- */
    /*                                 matrix4x4                                  */
    /* -------------------------------------------------------------------------- */


    inline matrix4x4 matrix4x4_from_columns(vector4 x, vector4 y, vector4 z, vector4 w) {
        return matrix4x4 {
            x.x, y.x, z.x, w.x,
            x.y, y.y, z.y, w.y,
            x.z, y.z, z.z, w.z,
            x.w, y.w, z.w, w.w
        };
    }

    inline matrix4x4 operator*(const matrix4x4 &a, const matrix4x4 &b) {
        vector4 ihat = vector4_from_matrix4x4(b, 0);
        vector4 jhat = vector4_from_matrix4x4(b, 1);
        vector4 khat = vector4_from_matrix4x4(b, 2);
        vector4 lhat = vector4_from_matrix4x4(b, 3);

        ihat = matrix4x4_transform_vector4(a, ihat);
        jhat = matrix4x4_transform_vector4(a, jhat);
        khat = matrix4x4_transform_vector4(a, khat);
        lhat = matrix4x4_transform_vector4(a, lhat);

        return matrix4x4_from_columns(ihat, jhat, khat, lhat);
    }

    inline float determinant(const matrix4x4 &m) {
        return 
            -m[2][0]*m[1][1]*m[0][2]+
            m[1][0]*m[2][1]*m[0][2]+
            m[2][0]*m[0][1]*m[1][2]-
            m[0][0]*m[2][1]*m[1][2]-
            m[1][0]*m[0][1]*m[2][2]+
            m[0][0]*m[1][1]*m[2][2];
    }    

    inline matrix4x4 transpose(const matrix4x4 &m) {
        return {
            m[0][0], m[1][0], m[2][0], m[3][0],
            m[0][1], m[1][1], m[2][1], m[3][1],
            m[0][2], m[1][2], m[2][2], m[3][2],
            m[0][3], m[1][3], m[2][3], m[3][3],
        };
    }
    
    // this assumes the bottom row is 0, 0, 0, 1
    inline matrix4x4 invert_transform(const matrix4x4 &m) {
        float factor = 1.0f / determinant(m);

        vector4 x;
        x.x = (-m[2][1]*m[1][2]+m[1][1]*m[2][2])*factor;
        x.y = (m[2][1]*m[1][2]-m[1][0]*m[2][2])*factor;
        x.z = (-m[2][1]*m[1][1]+m[1][0]*m[2][1])*factor;
        x.w = 0;

        vector4 y;
        y.x = (m[2][1]*m[0][2]-m[0][1]*m[2][2])*factor;
        y.y = (-m[2][0]*m[0][2]+m[0][0]*m[2][2])*factor;
        y.z = (m[2][0]*m[0][1]-m[0][0]*m[2][1])*factor;
        y.w = 0;

        vector4 z;
        z.x = (-m[1][1]*m[0][2]+m[0][1]*m[1][2])*factor;
        z.y = (m[1][0]*m[0][2]-m[0][0]*m[1][2])*factor;
        z.z = (-m[1][0]*m[0][1]+m[0][0]*m[1][1])*factor;
        z.w = 0;

        vector4 w;
        w.x = (
            m[2][1]*m[1][2]*m[0][3] -
            m[1][1]*m[2][2]*m[0][3] -
            m[2][1]*m[0][2]*m[1][3] +
            m[0][1]*m[2][2]*m[1][3] +
            m[1][1]*m[0][2]*m[2][3] -
            m[0][1]*m[1][2]*m[2][3]
        ) * factor;
        w.y = (
            -m[2][0]*m[1][2]*m[0][3]
            +m[1][0]*m[2][2]*m[0][3]
            +m[2][0]*m[0][2]*m[1][3]
            -m[0][0]*m[2][2]*m[1][3]
            -m[1][0]*m[0][2]*m[2][3]
            +m[0][0]*m[1][2]*m[2][3]
        ) * factor;
        w.z = (
            m[2][0]*m[1][1]*m[0][3] -
            m[1][0]*m[2][1]*m[0][3] -
            m[2][0]*m[0][1]*m[1][3] +
            m[0][0]*m[2][1]*m[1][3] +
            m[1][0]*m[0][1]*m[2][3] -
            m[0][0]*m[1][1]*m[2][3]
        ) * factor;
        w.w = 1;

        return matrix4x4_from_columns(x,y,z,w);
    }

    // Get column vector
    inline vector3 vector3_from_matrix4x4(const matrix4x4 &m, const size_t i) {
        return vector3{m[0][i], m[1][i], m[2][i]};
    }

    inline vector4 vector4_from_matrix4x4(const matrix4x4 &m, const size_t i) {
        
        return vector4{m[0][i], m[1][i], m[2][i], m[3][i]};
    }

    inline vector3 matrix4x4_transform_vector3(const matrix4x4 &m, const vector3 &v) {
        vector3 x = v.x*vector3_from_matrix4x4(m,0);
        vector3 y = v.y*vector3_from_matrix4x4(m,1);
        vector3 z = v.z*vector3_from_matrix4x4(m,2);
        vector3 w = vector3_from_matrix4x4(m,3);

        return x+y+z+w;
    }

    inline vector4 matrix4x4_transform_vector4(const matrix4x4 &m, const vector4 &v) {
        vector4 x = v.x*vector4_from_matrix4x4(m,0);
        vector4 y = v.y*vector4_from_matrix4x4(m,1);
        vector4 z = v.z*vector4_from_matrix4x4(m,2);
        vector4 w = v.w*vector4_from_matrix4x4(m,3);

        return x+y+z+w;
    }

    inline matrix4x4 matrix4x4_from_perspective(float fovy, float aspect, float zNear, float zFar) {
        const float tanHalfFovy = tan(fovy/2.0f);

        matrix4x4 m = {0};

        m[0][0] = 1.0f / (aspect * tanHalfFovy);
        m[1][1] = 1.0f / tanHalfFovy;
        m[2][2] = - (zFar + zNear) / (zFar - zNear);
        m[3][2] = -1.0f;
        m[2][3] = (-2.0f * zFar * zNear) / (zFar - zNear);
        return m;
    }

    inline matrix4x4 matrix4x4_from_translation(const vector3 &v) {
        return matrix4x4{
            1, 0, 0, v.x,
            0, 1, 0, v.y,
            0, 0, 1, v.z,
            0, 0, 0, 1
        };
    }

    matrix4x4 matrix4x4_from_matrix3x3(const matrix3x3 &m) {
        return matrix4x4{
            m[0][0], m[0][1], m[0][2], 0,
            m[1][0], m[1][1], m[1][2], 0,
            m[2][0], m[2][1], m[2][2], 0,
                  0,       0,       0, 1
        };
    }

    matrix4x4 matrix4x4_from_identity() {
        return matrix4x4{
            1, 0, 0, 0,
            0, 1, 0, 0,
            0, 0, 1, 0,
            0, 0, 0, 1
        };
    }

    matrix4x4 matrix4x4_from_diagonal(const float s) {
        return matrix4x4{
            s, 0, 0, 0,
            0, s, 0, 0,
            0, 0, s, 0,
            0, 0, 0, s
        };
    }

    // TODO:
    // inline matrix4x4 matrix4x4_from_quaternion(const quaternion &q) {

    // }
}

#endif