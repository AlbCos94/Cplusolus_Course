#include <iostream>

// Functors --> other way of passing blocks of code
// Alternative to "function pointers"

// Functor --> Class or Struct that overloads the brackets operator "( )" / it can also implement other stuff

// We will use a "struct" in this example, since by default everything inside is public

// Abstract Class --> we will derive form it all the subclasses
struct Test {
    virtual bool operator()(std::string& text) = 0;

    virtual ~Test(){};
};

struct MatchTest : public Test {
    // we overload the brackets operator
    bool operator()(std::string& text)
    {
        return (text == "lion");
    }
};

void check(std::string text, Test& test)
{
    if(test(text)) {
        std::cout << "Text matches!" << std::endl;
    } else {
        std::cout << "No match." << std::endl;
    }
}

int main()
{
    MatchTest pred;
    std::string value = "lion";
    std::cout << pred(value) << std::endl;

    MatchTest m;
    // We have to use a derived class that can be instantiated!!
    check("lifsfdfsfon", m);
    return 0;
}