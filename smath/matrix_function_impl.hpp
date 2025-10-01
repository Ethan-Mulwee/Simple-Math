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

    matrix3x3 operator*(const float s, const matrix3x3 &m) {
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
        m[0][0] = q.x*q.x-q.y*q.y-q.z*q.z+q.w*q.w;
        m[1][0] = 2*q.w*q.z+2*q.x*q.y;
        m[2][0] = 2*q.x*q.z-2*q.w*q.y;
        // j hat
        m[0][1] = 2*q.x*q.y-2*q.w*q.z;
        m[1][1] = q.w*q.w-q.x*q.x+q.y*q.y-q.z*q.z;
        m[2][1] = 2*q.w*q.x+2*q.y*q.z;
        // k hat
        m[0][2] = 2*q.x*q.z+2*q.w*q.y;
        m[1][2] = 2*q.y*q.z-2*q.w*q.x;
        m[2][2] = q.w*q.w-q.x*q.x-q.y*q.y+q.z*q.z;
    
        return m;
    }

    matrix3x3 matrix3x3_from_ihat(const vector3 &v) {
        vector3 jhat, khat;

        vector3 ihat = normalized(v);

        if (std::abs(ihat.y) < std::abs(ihat.z)) {
            khat = vector3{-ihat.z, 0, ihat.x};
            jhat = cross(ihat, khat);
        }
        else {
            jhat = vector3{-v.y, v.x, 0};
            khat = cross(ihat, jhat);
        }

        return matrix3x3_from_columns(ihat, jhat, khat);
    }

    matrix3x3 matrix3x3_from_jhat(const vector3 &v) {
        vector3 ihat, khat;

        vector3 jhat = normalized(v);

        if (std::abs(jhat.y) < std::abs(jhat.z)) {
            khat = vector3{-jhat.z, 0, jhat.x};
            ihat = cross(khat, jhat);
        }
        else {
            ihat = vector3{-jhat.y, jhat.x, 0};
            khat = cross(ihat, jhat);
        }

        return matrix3x3_from_columns(ihat, jhat, khat);
    }

    matrix3x3 matrix3x3_from_khat(const vector3 &v) {
        vector3 ihat, jhat;

        vector3 khat = normalized(v);

        if (std::abs(khat.y) < std::abs(khat.z)) {
            jhat = vector3{-khat.z, 0, khat.x};
            ihat = cross(khat, jhat);
        }
        else {
            ihat = vector3{-khat.y, khat.x, 0};
            jhat = cross(khat, ihat);
        }

        return matrix3x3_from_columns(ihat, jhat, khat);
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

    matrix3x3 matrix3x3_normalize_basis(const matrix3x3 &m) {
        vector3 ihat = normalized(vector3_from_matrix3x3(m,0));
        vector3 jhat = normalized(vector3_from_matrix3x3(m,1));
        vector3 khat = normalized(vector3_from_matrix3x3(m,2));
        return matrix3x3_from_columns(ihat, jhat, khat);
    }

    bool matrix3x3_is_inverse(const matrix3x3 inverse, const matrix3x3 matrix, float epsilon) {
        matrix3x3 product = matrix*inverse;
        matrix3x3 identity = matrix3x3_from_identity();

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                bool upperBound = product[i][j] < identity[i][j] + epsilon;
                bool lowerBound = product[i][j] > identity[i][j] - epsilon;

                if (!(upperBound && lowerBound))
                    return false;
            }
        }

        return true;
    }

    bool matrix3x3_is_orthonormal(const matrix3x3 &m, float epsilon) {
        // float epsilon = 0.001f;

        // for (int i = 0; i < 3; i++) {
        //     vector3 basisVector = vector3_from_matrix3x3(m, i);
        //     bool upperBound = basisVector.length() < 1.0f + epsilon;
        //     bool lowerBound = basisVector.length() > 1.0f - epsilon;

        //     if (!(upperBound && lowerBound))
        //         return false;
        // }

        // return true;
        return matrix3x3_is_inverse(transpose(m), m);
    }

    bool matrix3x3_is_orthogonal(const matrix3x3 &m, float epsilon) {
        vector3 i = vector3_from_matrix3x3(m, 0);
        vector3 j = vector3_from_matrix3x3(m, 1);
        vector3 k = vector3_from_matrix3x3(m, 2);

        float ij = dot(i,j);
        float jk = dot(j,k);
        float ik = dot(i,k);

        bool one = (ij < 0.0f + epsilon && ij > 0.0 - epsilon);
        bool two = (jk < 0.0f + epsilon && jk > 0.0 - epsilon);
        bool three = (ik < 0.0f + epsilon && ik > 0.0 - epsilon);

        return one && two && three;
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

    void operator*=(matrix4x4 &m, const float s) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                m[i][j] = m[i][j] * s;
            }
        }
    }

    void operator*=(matrix4x4 &a, const matrix4x4 &b) {
        a = a * b;
    }

    matrix4x4 operator*(const float s, const matrix4x4 &m) {
        matrix4x4 result;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                result[i][j] = m[i][j] * s;
            }
        }

        return result;
    }

    matrix4x4 operator*(const matrix4x4 &m, const float s) {
        matrix4x4 result;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                result[i][j] = m[i][j] * s;
            }
        }

        return result;
    }

    inline matrix4x4 operator*(const matrix4x4 &a, const matrix4x4 &b)
    {
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

    // adapted from https://stackoverflow.com/questions/1148309/inverting-a-4x4-matrix#1148405
    matrix4x4 inverse(const matrix4x4 &m) {
        matrix4x4 inv; 
        matrix4x4 invOut; 
        float det;
        int i;

        inv[0][0] = m[1][1]  * m[2][2] * m[3][3] - 
                m[1][1]  * m[3][2] * m[2][3] - 
                m[1][2]  * m[2][1]  * m[3][3] + 
                m[1][2]  * m[3][1]  * m[2][3] +
                m[1][3] * m[2][1]  * m[3][2] - 
                m[1][3] * m[3][1]  * m[2][2];

        inv[0][1] = -m[0][1]  * m[2][2] * m[3][3] + 
                m[0][1]  * m[3][2] * m[2][3] + 
                m[0][2]  * m[2][1]  * m[3][3] - 
                m[0][2]  * m[3][1]  * m[2][3] - 
                m[0][3] * m[2][1]  * m[3][2] + 
                m[0][3] * m[3][1]  * m[2][2];

        inv[0][2]  = m[0][1]  * m[1][2] * m[3][3] - 
                m[0][1]  * m[3][2] * m[1][3] - 
                m[0][2]  * m[1][1] * m[3][3] + 
                m[0][2]  * m[3][1] * m[1][3] + 
                m[0][3] * m[1][1] * m[3][2] - 
                m[0][3] * m[3][1] * m[1][2] ;

        inv[0][3]  = -m[0][1]  * m[1][2] * m[2][3] + 
                m[0][1]  * m[2][2] * m[1][3] +
                m[0][2]  * m[1][1] * m[2][3] - 
                m[0][2]  * m[2][1] * m[1][3] - 
                m[0][3] * m[1][1] * m[2][2] + 
                m[0][3] * m[2][1] * m[1][2] ;

        inv[1][0] = -m[1][0]  * m[2][2] * m[3][3] + 
                m[1][0]  * m[3][2] * m[2][3] + 
                m[1][2]  * m[2][0] * m[3][3] - 
                m[1][2]  * m[3][0] * m[2][3] - 
                m[1][3] * m[2][0] * m[3][2] + 
                m[1][3] * m[3][0] * m[2][2] ;

        inv[1][1]  = m[0][0]  * m[2][2] * m[3][3] - 
                m[0][0]  * m[3][2] * m[2][3] - 
                m[0][2]  * m[2][0] * m[3][3] + 
                m[0][2]  * m[3][0] * m[2][3] + 
                m[0][3] * m[2][0] * m[3][2] - 
                m[0][3] * m[3][0] * m[2][2] ;

        inv[1][2]  = -m[0][0]  * m[1][2] * m[3][3] + 
                m[0][0]  * m[3][2] * m[1][3] + 
                m[0][2]  * m[1][0] * m[3][3] - 
                m[0][2]  * m[3][0] * m[1][3] - 
                m[0][3] * m[1][0] * m[3][2] + 
                m[0][3] * m[3][0] * m[1][2] ;

        inv[1][3]  = m[0][0]  * m[1][2] * m[2][3] - 
                m[0][0]  * m[2][2] * m[1][3] - 
                m[0][2]  * m[1][0] * m[2][3] + 
                m[0][2]  * m[2][0] * m[1][3] + 
                m[0][3] * m[1][0] * m[2][2] - 
                m[0][3] * m[2][0] * m[1][2] ;

        inv[2][0] = m[1][0]  * m[2][1] * m[3][3] - 
                m[1][0]  * m[3][1] * m[2][3] - 
                m[1][1]  * m[2][0] * m[3][3] + 
                m[1][1]  * m[3][0] * m[2][3] + 
                m[1][3] * m[2][0] * m[3][1] - 
                m[1][3] * m[3][0] * m[2][1] ;

        inv[2][1]  = -m[0][0]  * m[2][1] * m[3][3] + 
                m[0][0]  * m[3][1] * m[2][3] + 
                m[0][1]  * m[2][0] * m[3][3] - 
                m[0][1]  * m[3][0] * m[2][3] - 
                m[0][3] * m[2][0] * m[3][1] + 
                m[0][3] * m[3][0] * m[2][1] ;

        inv[2][2]  = m[0][0]  * m[1][1] * m[3][3] - 
                m[0][0]  * m[3][1] * m[1][3] - 
                m[0][1]  * m[1][0] * m[3][3] + 
                m[0][1]  * m[3][0] * m[1][3] + 
                m[0][3] * m[1][0] * m[3][1] - 
                m[0][3] * m[3][0] * m[1][1] ;

        inv[2][3]  = -m[0][0]  * m[1][1] * m[2][3] + 
                m[0][0]  * m[2][1] * m[1][3] + 
                m[0][1]  * m[1][0] * m[2][3] - 
                m[0][1]  * m[2][0] * m[1][3] - 
                m[0][3] * m[1][0] * m[2][1] + 
                m[0][3] * m[2][0] * m[1][1] ;

        inv[3][0] = -m[1][0] * m[2][1] * m[3][2] + 
                m[1][0] * m[3][1] * m[2][2] + 
                m[1][1] * m[2][0] * m[3][2] - 
                m[1][1] * m[3][0] * m[2][2] - 
                m[1][2] * m[2][0] * m[3][1] + 
                m[1][2] * m[3][0] * m[2][1] ;

        inv[3][1]  = m[0][0] * m[2][1] * m[3][2] - 
                m[0][0] * m[3][1] * m[2][2] - 
                m[0][1] * m[2][0] * m[3][2] + 
                m[0][1] * m[3][0] * m[2][2] + 
                m[0][2] * m[2][0] * m[3][1] - 
                m[0][2] * m[3][0] * m[2][1] ;

        inv[3][2]  = -m[0][0] * m[1][1] * m[3][2] + 
                m[0][0] * m[3][1] * m[1][2] + 
                m[0][1] * m[1][0] * m[3][2] - 
                m[0][1] * m[3][0] * m[1][2] - 
                m[0][2] * m[1][0] * m[3][1] + 
                m[0][2] * m[3][0] * m[1][1] ;

        inv[3][3]  = m[0][0] * m[1][1] * m[2][2] - 
                m[0][0] * m[2][1] * m[1][2] - 
                m[0][1] * m[1][0] * m[2][2] + 
                m[0][1] * m[2][0] * m[1][2] + 
                m[0][2] * m[1][0] * m[2][1] - 
                m[0][2] * m[2][0] * m[1][1] ;

        det = m[0][0] * inv[0][0] + m[1][0] * inv[0][1]  + m[2][0] * inv[0][2]  + m[3][0] * inv[0][3] ;

        det = 1.0 / det;

        for (i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                invOut[i][j] = inv[i][j] * det;

        return invOut;
    }

    inline matrix4x4 invert_transform(const matrix4x4 &m) {
        matrix3x3 rotation = matrix3x3_from_matrix4x4(m);
        matrix3x3 rotationInverse = transpose(rotation);

        vector3 translation = vector3_from_matrix4x4(m, 3);
        vector3 translationInverse = matrix3x3_transform_vector3(-1.0f*rotationInverse, translation);
    
        return matrix4x4_from_transformation(translationInverse, rotationInverse);
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

    matrix4x4 matrix4x4_from_scale(const float s) {
        return matrix4x4{
            s,    0.0f, 0.0f, 0.0f,
            0.0f, s,    0.0f, 0.0f,
            0.0f, 0.0f, s,    0.0f,
            0.0f, 0.0f, 0.0f, 1.0f
        };
    }

    matrix4x4 matrix4x4_from_scale(const vector3 &s)
    {
        return matrix4x4{
            s.x,  0.0f, 0.0f, 0.0f,
            0.0f, s.y,  0.0f, 0.0f,
            0.0f, 0.0f, s.z,  0.0f,
            0.0f, 0.0f, 0.0f, 1.0f
        };
    }

    matrix4x4 matrix4x4_from_rotation(const quaternion &q) {
        return matrix4x4_from_matrix3x3(matrix3x3_from_quaternion(q));
    }

    matrix4x4 matrix4x4_from_transformation(const vector3 &translation, const matrix3x3 &rotation) {
        return matrix4x4 {
            rotation[0][0], rotation[0][1], rotation[0][2], translation.x,
            rotation[1][0], rotation[1][1], rotation[1][2], translation.y,
            rotation[2][0], rotation[2][1], rotation[2][2], translation.z,
            0,              0,              0,              1
        };
    }

    // TODO:
    // matrix4x4 matrix4x4_from_transformation(const vector3 &translation, const matrix3x3 &rotation, const vector3 &scale) {
    //     return matrix4x4 {
    //         rotation[0][0]*scale.x,  
    //     }
    // }

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

    bool matrix4x4_is_inverse(const matrix4x4 inverse, const matrix4x4 matrix, float epsilon) {
        matrix4x4 product = matrix*inverse;
        matrix4x4 identity = matrix4x4_from_identity();

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                bool upperBound = product[i][j] < identity[i][j] + epsilon;
                bool lowerBound = product[i][j] > identity[i][j] - epsilon;

                if (!(upperBound && lowerBound))
                    return false;
            }
        }

        return true;
    }
}

#endif