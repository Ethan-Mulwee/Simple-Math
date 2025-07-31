#include "smath.hpp"
#include "to_string.hpp"
#include <iostream>

int main() {
    using namespace smath;

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

    std::cout << "\n ---------------------------Quaterion from Euler--------------------------- \n \n";

    {
        vector3 euler = vector3{M_PI/2.0f, M_PI/2.0f, 0.0f};
        quaternion q = quaternion_from_euler_angles_XYZ(euler.x, euler.y, euler.z);
        std::cout << "Euler (XYZ): " << to_string(euler) << "\n";
        std::cout << "Quaternion from euler" << to_string(q) << "\n"; 
        std::cout << "Axis: " << to_string(q.axis()) << "\n";
        std::cout << "Angle: " << q.angle() << "\n";
    }

    std::cout << "\n ---------------------------Quaternion multiplcation--------------------------- \n \n";

    {
        quaternion q = quaternion_from_axis_angle(vector3{1.0f,0.0f,0.0f}, M_PI/2.0f);
        quaternion p = quaternion_from_axis_angle(vector3{0.0f,1.0f,0.5f}, M_PI/2.0f);
        std::cout << "q: " << to_string(q) << "\n";
        std::cout << "p: " << to_string(p) << "\n\n";

        std::cout << "q*p: " << to_string(q*p) << "\n";
        std::cout << "length: " << (q*p).length() << "\n";
    }

    std::cout << "\n";
}