#ifndef SMATH_EULER_TYPE
#define SMATH_EULER_TYPE

namespace smath {
    enum euler_type{
        XYZ, XZY, YXZ, YZX, ZXY, ZYX
    };

    struct euler_xyz {
        float x, y, z;
    };

    
}

#endif