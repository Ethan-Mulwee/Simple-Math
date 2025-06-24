# Simple Math
A C++ math library intended to limit the amount of BS in the code base, no templates, no constructors, no unions, operator overloading is used for obvious operations between types i.e. +-*/, cross, dot, and determinant. Otherwise there are explict functions with a C like naming convention with minimal to no overloading.

# Functions
### Conversion/Construction
these functions follow the convention `returntype_from_type(type)` i.e. `vector3_from_vector4(vector4)` or `matrix3x3_from_quaternion(quaternion)`

### Operations
these functions follow the convention `firstArg_operation_secondArg(firstArg, secondArg)` and typically returns `secondArg`. i.e. 
```
vector3 quaternion_transform_vector(const quaternion &q, const vector3 &v)
```
