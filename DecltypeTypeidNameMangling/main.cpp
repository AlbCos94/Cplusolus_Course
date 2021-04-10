#include <iostream>
#include <typeinfo>
// Features only for C++ 11 and above

// Operator of C++11 to know the type
// Decltype --> new C++ 11 Keyword
// Typeid --> it returns information about a certain varible
int main()
{
    // Typeid
    int value;
    std::string value2;
    std::cout << typeid(value).name() << std::endl; // it returns the type of a certain variable
    std::cout << typeid(value2).name()
              << std::endl; // it gives lots more information, inside that info the name of the type can be seen

    // Decltype --> it gets the type of the variable passed as a parameter ("value2") and right after we declare a new
    // varaible of that type
    decltype(value2) name = "Bob";
    std::cout << typeid(name).name() << std::endl;
    std::cout << name << std::endl;
    return 0;
}