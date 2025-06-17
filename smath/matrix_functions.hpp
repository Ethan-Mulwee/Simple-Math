#ifndef SIMPLE_MATRIX_FUNCTIONS
#define SIMPLE_MATRIX_FUNCTIONS

#include <cmath>
#include "matrix_types.hpp"
#include "vector_types.hpp"

namespace smath {
    /* -------------------------------------------------------------------------- */
    /*                                  float3x3                                  */
    /* -------------------------------------------------------------------------- */

    // Construct matrix from column vectors
    inline float3x3 float3x3_from_columns(const float3 &x, const float3 &y, const float3 &z) {
        return float3x3 {
            x.x, y.x, z.x,
            x.y, y.y, z.y,
            x.z, y.z, z.z
        };
    }
    
    void operator*=(float3x3 &m, const float s) {
        m[0][0] *= s; m[0][1] *= s; m[0][2] *= s;
        m[1][0] *= s; m[1][1] *= s; m[1][2] *= s;
        m[2][0] *= s; m[2][1] *= s; m[2][2] *= s;
    }
    
    float3x3 operator*(const float3x3 &m, const float s) {
        return {
            m[0][0] * s, m[0][1] * s, m[0][2] * s,
            m[1][0] * s, m[1][1] * s, m[1][2] * s,
            m[2][0] * s, m[2][1] * s, m[2][2] * s
        };
    }
    
    inline float determinant(const float3x3 &m) {
        // a(ei-fh)
        float t1 = m[0][0]*(m[1][1]*m[2][2]-m[1][2]*m[2][1]);
        // b(di-fg)
        float t2 = m[0][1]*(m[1][0]*m[2][2]-m[1][2]*m[2][0]);
        // c(dh-eg)
        float t3 = m[0][2]*(m[1][0]*m[2][1]-m[1][1]*m[2][0]);
        
        return t1-t2-t3;
    }
    
    inline float3x3 inverse(const float3x3 &m) {
        // took this from glm
        float OneOverDeterminant = 1.0f / (
            +m[0][0] * (m[1][1] * m[2][2] - m[2][1] * m[1][2])
            - m[1][0] * (m[0][1] * m[2][2] - m[2][1] * m[0][2])
            + m[2][0] * (m[0][1] * m[1][2] - m[1][1] * m[0][2]));
            
        float3x3 inverse;
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
    inline float3 float3_from_float3x3(const float3x3 &m, const size_t i) {
        return float3{m[0][i], m[1][i], m[2][i]};
    }

    float3 float3x3_transform_float3(const float3x3 &m, const float3 &v) {
        float3 x = v.x*float3_from_float3x3(m,0);
        float3 y = v.y*float3_from_float3x3(m,1);
        float3 z = v.z*float3_from_float3x3(m,2);
        return x+y+z;
    }

    /* -------------------------------------------------------------------------- */
    /*                                  float4x4                                  */
    /* -------------------------------------------------------------------------- */


    inline float4x4 float4x4_from_columns(float4 x, float4 y, float4 z, float4 w) {
        return float4x4 {
            x.x, y.x, z.x, w.x,
            x.y, y.y, z.y, w.y,
            x.z, y.z, z.z, w.z,
            x.w, y.w, z.w, w.w
        };
    }

    inline float determinant(const float4x4 &m) {
        return 
            -m[2][0]*m[1][1]*m[0][2]+
            m[1][0]*m[2][1]*m[0][2]+
            m[2][0]*m[0][1]*m[1][2]-
            m[0][0]*m[2][1]*m[1][2]-
            m[1][0]*m[0][1]*m[2][2]+
            m[0][0]*m[1][1]*m[2][2];
    }    
    
    inline float4x4 inverse(const float4x4 &m) {
        float factor = 1.0f / determinant(m);

        float4 x;
        x.x = (-m[2][1]*m[1][2]+m[1][1]*m[2][2])*factor;
        x.y = (m[2][1]*m[1][2]-m[1][0]*m[2][2])*factor;
        x.z = (-m[2][1]*m[1][1]+m[1][0]*m[2][1])*factor;
        x.w = 0;

        float4 y;
        y.x = (m[2][1]*m[0][2]-m[0][1]*m[2][2])*factor;
        y.y = (-m[2][0]*m[0][2]+m[0][0]*m[2][2])*factor;
        y.z = (m[2][0]*m[0][1]-m[0][0]*m[2][1])*factor;
        y.w = 0;

        float4 z;
        z.x = (-m[1][1]*m[0][2]+m[0][1]*m[1][2])*factor;
        z.y = (m[1][0]*m[0][2]-m[0][0]*m[1][2])*factor;
        z.z = (-m[1][0]*m[0][1]+m[0][0]*m[1][1])*factor;
        z.w = 0;

        float4 w;
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

        return float4x4_from_columns(x,y,z,w);
    }

        // Get column vector
    inline float3 float3_from_float4x4(const float4x4 &m, const size_t i) {
        return float3{m[0][i], m[1][i], m[2][i]};
    }

    inline float3 float4x4_transform_float3(const float4x4 &m, const float3 &v) {
        float3 x = v.x*float3_from_float4x4(m,0);
        float3 y = v.y*float3_from_float4x4(m,1);
        float3 z = v.z*float3_from_float4x4(m,2);
        float3 w = float3_from_float4x4(m,3);

        return x+y+z+w;
    }
}

#endif