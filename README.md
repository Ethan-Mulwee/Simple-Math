# Simple Math
A C++ math library intended to limit the amount complexity in the code base, no templates, no constructors.

# Types
All types are aggregate types intended to be intailized with intializer lists. Type names are treated like primitive types with lowcase names. For simplicity sake all types default to using floating point numbers.
```cpp
vector3 v = {1,2,3};
```

Currently implented types include
- vector2, vector3, vector4
- matrix2x2, matrix3x3, matrix4x4
- quaternion
- transform

# Functions
### Conversion/Construction
these functions follow the convention `returntype_from_type(type)` i.e. 
```cpp
vector3 vector3_from_vector4(const vector3 &a, const vector4 &b)

matrix3x3 matrix3x3_from_quaternion(const quaternion &q)
``` 


### Operations
these functions follow the convention `firstArg_operation_secondArg(firstArg, secondArg)` and typically returns `secondArg`.
```
vector3 quaternion_transform_vector(const quaternion &q, const vector3 &v)
```

# Printing
The header "smath_iostream.hpp" is included to add simple functionality for printing
```cpp
    #include "smath/smath.hpp"
    #include "smath/smath_iostream.hpp"

    smath::vector3 v = {1,2,3};

    int main() {
        std::cout << "vector: " << v << "\n";
    }

    // outputs: "vector: (1.000000, 2.000000, 3.000000)"
```

# Testing
basic tests and examples for all the library functionally are included in `tests/` along with a makefile for every use


