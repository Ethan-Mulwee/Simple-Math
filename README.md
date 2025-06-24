# Simple Math
A C++ math library intended to limit the amount of BS in the code base, no templates, no constructors, no unions, operator overloading is used for obvious operations between types i.e. +-*/, cross, dot, and determinant. Otherwise there are explict functions with a C like naming convention with minimal to no overloading.

# Types
All types are aggregate types intended to be intailized with intializer lists. Type names are treated like primitive types with lowcase names. For simplicity sake all types default to using floating point numbers. There are plans for supporting other types later.
```cpp
vector3 v = {1,2,3};
```

Currently implented types include
- vector2, vector3, vector4
- matrix3x3, matrix4x4
- quaternion

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

# Debugging/Printing
The header "to_string.hpp" is included to add simple functionality for printing
```cpp
    #include <iostream>
    #include "smath/smath.hpp"
    #include "smath/to_string.hpp"

    smath::vector3 v = {1,2,3};

    int main() {
        std::cout << "vector: " << smath::to_string(v) << "\n";
    }

    // outputs: "vector: (1.000000,2.000000,3.000000)"
```


