#ifndef SMATH_BIVECTOR_FUNCTION
#define SMATH_BIVECTOR_FUNCTION

#include "bivector_type.hpp"

namespace smath {
    inline bivector3 wedge(const bivector3 &a, const bivector3 &b) {
        return {
            .yz = a.xy * b.zx - a.zx * b.xy,
            .zx = a.yz * b.xy - a.xy * b.yz,
            .xy = a.zx * b.yz - a.yz * b.zx
        };
    }
}

#endif