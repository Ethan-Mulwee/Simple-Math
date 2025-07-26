#include "smath.hpp"
#include "to_string.hpp"
#include <iostream>

int main() {
    using namespace smath;

    /* -------------------------------------------------------------------------- */
    /*                             Quaternion testing                             */
    /* -------------------------------------------------------------------------- */
    std::cout << "\n -------------------------------------------------------------------------- \n "
                 "                           Quaternion Testing:                            \n"
                 " -------------------------------------------------------------------------- \n \n ";

    {
        quaternion q = quaternion_from_axis_angle(vector3{1,0,0}, M_PI/2.0f);
        std::cout << "q: " << to_string(q) << "\n";
        std::cout << "axis: "<< to_string(q.axis()) << "\n";
        std::cout << "angle: " << q.angle() << "\n";
    }

    std::cout << "\n ---------------------------Vector transformation--------------------------- \n \n";

    {
        quaternion q = quaternion_from_axis_angle(vector3{1,0,0}, M_PI/2.0f);
        vector3 v{0.0f, 1.0f, 0.0f};
        std::cout << "quaternion: " << to_string(q) << "\n";
        std::cout << "vector: " << to_string(v) << "\n \n";

        std::cout << "vector transformed by quaternion: " << to_string(quaternion_transform_vector(q, v)) << "\n";
    }

    std::cout << "\n";
}