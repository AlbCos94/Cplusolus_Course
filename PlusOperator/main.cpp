#include "Complex.h"
#include <iostream>
namespace adv_p = advance_programming; // just to not use it we could do --> using  namespace advance_programming

// Implementation of everything we have implemented until now inside the class "Complex"
// plus overloading  the 'Plus' operator to that class ( and the "Minus" operator)

// by overloading the + opearator we are not changing the original operands
// in that way we can create a new function
// + operator will retor a new number (not even a reference) --> WE ARE CREATING A NEW OBJECT!!
int main()
{
    adv_p::Complex Complex_num1(1, 2);
    adv_p::Complex Complex_num2 = Complex_num1;
    adv_p::Complex Complex_num3(3, 2);

    // Complex_num2 = Complex_num1;
    std::cout << Complex_num1 << std::endl;
    std::cout << Complex_num2 << std::endl;
    std::cout << Complex_num3 << std::endl;
    std::cout << Complex_num1 + Complex_num3 << std::endl;                // trying the operator +
    std::cout << Complex_num1 + Complex_num2 + Complex_num3 << std::endl; // we can concatenate this operation
    std::cout << Complex_num1 + 2232 << std::endl; // we can use the overloaded + operator to sum double numbers
    std::cout << 223 + Complex_num1
              << std::endl; // thanks we implemented + operator with different order of summands, we can do that
    std::cout << 71 + Complex_num3 - Complex_num2 - 34 + Complex_num1 + 12 << std::endl;
    // std::cout << Complex_num1 - Complex_num3 << std::endl;
    return 0;
}