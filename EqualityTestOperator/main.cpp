#include "ComplexV2.hpp"
#include <iostream>
namespace adv_p = advance_programming; // just to not use it we could do --> using  namespace advance_programming

// in this case we want to implement the "==" operator, to compare if two objects can be considered the same
// this overloading operator is returning a "bool" indicating:
//  1: the two objects are equals
//  0: the two objects are not equals

int main()
{
    adv_p::ComplexV2 c1(3, 2);
    adv_p::ComplexV2 c2(3, 2);

    if(c1 == c2) {
        std::cout << "Equal" << std::endl;
    } else {
        std::cout << "Not Equal" << std::endl;
    }

    if(c1 != c2) {
        std::cout << "Not Equal" << std::endl;
    } else {
        std::cout << "Equal" << std::endl;
    }

    return 0;
}