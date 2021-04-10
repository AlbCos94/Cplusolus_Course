#include <iostream>

int main()
{

    // lambda expression --> [](){}();
    //      [] --> kind  to represent the name of the function ( since they dont have a name )
    //      () --> brackets where we put the arguments to the function
    //      {} --> curly parentesis, palce where we put the code inside
    //      () --> we add () at the end, in case we want to call the function automatically

    int one = 1;
    int two = 2;
    int three = 3;

    []() {}(); // -> valid but useless lambda expression

    []() { std::cout << "Hello" << std::endl; }(); // without arguments

    [one, two]() {
        std::cout << one << " and " << two << std::endl;
    }(); // to caputure some local variables --> passed by value

    // to capture all the local variables by value --> [=]
    [=]() {
        std::cout << one << " and " << two << " and " << three << std::endl;
    }(); // to caputure some local variables --> passed by value

    // capture some values by value and others by reference
    // example with
    //  one, two --> by value --> Pass by value means that a copy of the actual parameter's value is made in memory,
    //                                           i.e. the caller and callee have two independent variables with the same
    //                                           value. A copy of the data is sent to the
    //                                             callee. ... Changes made to the passed variable do not affect the
    //                                             actual value.
    //
    // three --> by reference --> Passing by reference means that the memory address of the variable (a pointer to the
    //                                          memory location) is passed to the function. --> Notice that you can
    //                                          modify that original variable/object inside that function.
    //
    // Passing a complex object by reference is almost 40% faster than passing by value. Only ints and smaller objects
    // should be passed by value, because it's cheaper to copy them than to take the dereferencing hit within the
    // function.

    // Example of "default capture" all local variables by value, but we capture "three" by reference
    [=, &three]() {
        // one = 111; // cant not be assigend as it is a "read-only variable" --> ( cannot assign to a variable campured
        // --> labmdas are IMMUTABLE --> *2 by copy in a non-mutable lambda two = 222;
        three = 333;
        std::cout << one << ", " << two << " and " << three << std::endl;
    }();

    // CASE where Lambdas are Mutable -->*2 --> by addind mutable, so we can modify variable passed by value
    int cats = 5;
    [cats]() mutable {
        cats = 8;
        std::cout << "we have " << cats << " cats" << std::endl;
    }();

    // if we plot again those variable, we will notice that "three" did change its original value, since it was
    // passed by reference to that lambda expression ;)
    std::cout << one << std::endl;
    std::cout << two << std::endl;
    std::cout << three << std::endl; // --> 333

    // Example of "default capture" all local variables by reference
    [&]() {
        one = 111;
        two = 222;
        three = 444;
        std::cout << one << ", " << two << " and " << three << std::endl;
    }();

    // all the original variables have changed its value, since they were passed by reference and modified in that lamda
    // expressin
    std::cout << one << std::endl;   // --> 111
    std::cout << two << std::endl;   // --> 222
    std::cout << three << std::endl; // --> 444

    // Example of "default capture" all local variables by reference, except from "one
    [&, one]() {
        // one = 111;
        two = 2323;
        three = 545454;
        std::cout << one << ", " << two << " and " << three << std::endl;
    }();

    // Summary
    // [=, exceptions by reference] --> passed by value, and those exceptions of local variables by reference
    // [&, exceptions by value] --> passed by reference, and some exceptions of local variables by value

    return 0;
}