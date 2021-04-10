#include "Complex.hpp"
#include <iostream>
namespace adv_p = advance_programming; // just to not use it we could do --> using  namespace advance_programming

// Implementation of everything we have implemented until now inside the class "Complex"

int main()
{
    adv_p::Complex Complex_num1(1, 2);
    adv_p::Complex Complex_num2 = Complex_num1;

    // Complex_num2 = Complex_num1;
    std::cout << Complex_num1 << std::endl;
    std::cout << Complex_num2 << std::endl;

    return 0;
}