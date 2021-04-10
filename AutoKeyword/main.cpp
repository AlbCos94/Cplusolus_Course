#include <iostream>

// auto --> allow us omiting writting the type of the variable we are defining, by looking at the right value with
// which we initialized it. Not recommendable in the case we want to use an specific type, e.g. -> float value = 9;

// Use of 'auto' in functions --> we cant not just write 'auto' as the output of the function
// using "->" we have to indicate the type being returned
// no le veo mucho el sentido.. para eso ya pones "int" al inicio..
auto test1() -> int
{
    return 100;
}
// pero puede ser util para "template functions"

// USE OF "auto" + "decltype()" IN TEMPLATE FUNCTIONS TO KNOW WHICH IS THE TYPE THAT WE ARE RETURNING!!
// We use "Decltype" to enquire about the type that it is passed
// In the next function we are saying that the type that we are passing as an input arguments it is the same type as the
// output
template <class T> //
auto test2(T value) -> decltype(value)
{
    return value;
}

// We can even use an expression to say which is the type of the value we want to return
template <class T, class S> //
auto test3(T value1, S value2) -> decltype(value1 + value2)
{
    return (value1 + value2); // we should pass things that we can add together
}

// USE OF "auto" + "decltype()" + functions
int get()
{
    return 999;
}
// Use of "decltype" to get the type that a function returns
auto test4() -> decltype(get())
{
    return get();
}

int main()
{
    // auto --> allow us to omit writting the type of the variable we are defining, by looking at the right value with
    // which we initialized it , not recommendable in the case we want to write an specific type
    auto value = 7; // this will be an inter
    auto text = "Hello";
    // really usefull fot really long declarations
    // like iterators...
    std::cout << value << std::endl;
    std::cout << text << std::endl;
    // using functions with 'auto'
    std::cout << test1() << std::endl;
    // usign a template function with auto
    std::cout << test2("hola caracola") << std::endl;
    // usign a template function with  and expressions
    std::cout << test3(3, 5) << std::endl;
    // using "decltype" with another function
    std::cout << test4() << std::endl;
    return 0;
}