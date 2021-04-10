#include "ComplexV2.hpp"
#include <iostream>
namespace adv_p = advance_programming; // just to not use it we could do --> using  namespace advance_programming;

//  This project it is focused in the implementation of the "DEREFERENCE Operator" --> *[object]
// we will get the conjugate of objects of the Class "ComplexV2" by using this operator *
// A conjugate number of a complex number is the same number but changing the sign of the imaginary part
// a +bi --> a -bi
// this operator ussualy is used in pointers to get the content (object) it is pointing to

int main()
{
    adv_p::ComplexV2 c1(2, 5);
    std::cout << c1 << std::endl;
    std::cout << *c1 << std::endl;
    std::cout << (*c1) + *adv_p::ComplexV2(122, 5) << std::endl; // be carefull with the orther of execution of the
                                                                 // operatiors, always put parenthesis just in case to
                                                                 // follow the order you want
    return 0;
}