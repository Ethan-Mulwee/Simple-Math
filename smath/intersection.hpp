#ifndef SMATH_INTERSECTION
#define SMATH_INTERSECTION

#include "matrix_type.hpp"
#include "vector_function.hpp"
#include "matrix_function_impl.hpp"

// TODO: contains complex ray primitive intersection functions see: https://www.realtimerendering.com/intersections.html
namespace smath {
    // adapted from https://www.opengl-tutorial.org/miscellaneous/clicking-on-objects/picking-with-custom-ray-obb-function/
    inline bool ray_intersection_obb(vector3 ray_origin, vector3 ray_direction, vector3 aabb_min, vector3 aabb_max, matrix4x4 transform, float& intersection_distance) {
        float t_min = 0.0f;
        float t_max = 100000.0f;

        vector3 obb_position = {transform[0][3], transform[1][3], transform[2][3]};

        vector3 delta = obb_position - ray_origin;

        {
            vector3 x_axis{transform[0][0], transform[1][0], transform[2][0]};
            float e = dot(x_axis, delta);
            float f = dot(ray_direction, x_axis);

            if (fabs(f) > 0.001f) {
                float t1 = (e+aabb_min.x)/f;
                float t2 = (e+aabb_max.x)/f;

                if (t1>t2){
                    float w=t1;t1=t2;t2=w;
                }

                if (t2 < t_max)
                    t_max = t2;
                if (t1 > t_min)
                    t_min = t1;

                if (t_max < t_min)
                    return false;
            } else {
                if(-e+aabb_min.x > 0.0f || -e+aabb_max.x < 0.0f)
                    return false;
            }
        }

        {
            vector3 y_axis{transform[0][1], transform[1][1], transform[2][1]};
            float e = dot(y_axis, delta);
            float f = dot(ray_direction, y_axis);

            if (fabs(f) > 0.001f) {
                float t1 = (e+aabb_min.y)/f;
                float t2 = (e+aabb_max.y)/f;

                if (t1>t2) {float w=t1;t1=t2;t2=w;}

                if (t2 < t_max)
                    t_max = t2;
                if (t1 > t_min)
                    t_min = t1;
                if (t_max < t_min)
                    return false;
            } else {
                if(-e+aabb_min.y > 0.0f || -e+aabb_max.y < 0.0f)
                    return false;
            }  
        }

        {
            vector3 z_axis{transform[0][2], transform[1][2], transform[2][2]};
            float e = dot(z_axis, delta);
            float f = dot(ray_direction, z_axis);

            if (fabs(f) > 0.001f) {
                float t1 = (e+aabb_min.z)/f;
                float t2 = (e+aabb_max.z)/f;

                if (t1>t2) {float w=t1;t1=t2;t2=w;}

                if (t2 < t_max)
                    t_max = t2;
                if (t1 > t_min)
                    t_min = t1;
                if (t_max < t_min)
                    return false;
            } else {
                if(-e+aabb_min.z > 0.0f || -e+aabb_max.z < 0.0f)
                    return false;
            }    
        }

        intersection_distance = t_min;
        return true;

    }
}

#endif