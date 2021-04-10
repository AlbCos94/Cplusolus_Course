#include <iostream>

// Lambda expressions -- C++ 11
// to build a simple function that you want to pars around --> looks like a bracket fest
// Lambda body --> [](){}
// function schematic, with no input parameters --> [](){ expression }
// functor = [](){ expression };

// build of a function that as an inputs takes "another function" ( a pointer to a function )
void test(void (*pFunc)())
{
    pFunc();
}

int main()
{
    auto func = []() {
        std::cout << "Hello" << std::endl;
    }; // function with no name --> functor ( pointer to funciton) // definition / declaration

    auto func222 = []() { std::cout << "Hello 222 " << std::endl; };

    func(); // execution --> () at the end

    // in the next example, by putting brackets at the end , we realize that it acts like a function
    []() { std::cout << "Hello 2" << std::endl; }(); // execution, () at the end

    // passing this lambda expression to a function --> the real purpose of it!!

    // lambda expression are compatible with function pointers --> they are equivalent!!
    // use of a lambda expression as a pointer to a function:
    test(func); // execution through a  function that as an inputs takes "another function" ( a pointer to a function )

    test(func222); // execution through a  function that as an inputs takes "another function" ( a pointer to a function
                   // )

    // it is also possible to use the lambda expression as the input of that function
    test([]() { std::cout << "Hello 3" << std::endl; });
    return 0;
}