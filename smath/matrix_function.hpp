#ifndef SMATH_MATRIX_FUNCTION
#define SMATH_MATRIX_FUNCTION

#include <cmath>
#include "matrix_type.hpp"
#include "vector_type.hpp"

namespace smath {
    /* -------------------------------------------------------------------------- */
    /*                                 matrix3x3                                  */
    /* -------------------------------------------------------------------------- */

    // Construct matrix from column vectors
    inline matrix3x3 float3x3_from_columns(const vector3 &x, const vector3 &y, const vector3 &z) {
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
        return {
            m[0][0] * s, m[0][1] * s, m[0][2] * s,
            m[1][0] * s, m[1][1] * s, m[1][2] * s,
            m[2][0] * s, m[2][1] * s, m[2][2] * s
        };
    }
    
    inline float determinant(const matrix3x3 &m) {
        // a(ei-fh)
        float t1 = m[0][0]*(m[1][1]*m[2][2]-m[1][2]*m[2][1]);
        // b(di-fg)
        float t2 = m[0][1]*(m[1][0]*m[2][2]-m[1][2]*m[2][0]);
        // c(dh-eg)
        float t3 = m[0][2]*(m[1][0]*m[2][1]-m[1][1]*m[2][0]);
        
        return t1-t2-t3;
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

    inline vector3 float4x4_transform_float3(const matrix4x4 &m, const vector3 &v) {
        vector3 x = v.x*vector3_from_matrix4x4(m,0);
        vector3 y = v.y*vector3_from_matrix4x4(m,1);
        vector3 z = v.z*vector3_from_matrix4x4(m,2);
        vector3 w = vector3_from_matrix4x4(m,3);

        return x+y+z+w;
    }

    inline matrix4x4 matrix4x4_from_perspective(float fovy, float aspect, float zNear, float zFar) {
        const float tanHalfFovy = tan(fovy/2.0f);

        matrix4x4 m = {0};

        m[0][0] = 1.0f / (aspect * tanHalfFovy);
        m[1][1] = 1.0f / tanHalfFovy;
        m[2][2] = - (zFar + zNear) / (zFar - zNear);
        m[3][2] = 1.0f;
        m[2][3] = (2.0f * zFar * zNear) / (zFar - zNear);
        return m;
    }
}

#endif