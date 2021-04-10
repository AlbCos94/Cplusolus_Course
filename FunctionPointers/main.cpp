#include <iostream>
#include <string>
// Pointer to a Function
// --> In the same way that we can declare a pointer to a variable, we can also create a pointer to a function

void test() // return type: "void" and no parameters
{
    std::cout << "Hello" << std::endl;
}

void testParameters(int num, std::string name)
{
    std::cout << "The number is " << num << ", and the name is " << name << std::endl;
}

int main()
{
    test();

    // to define a pointer capable to point to the "test()" function, we create a pointer that like the function we want
    // to point, returns "void" and has no parameters

    // a pointer of this type will
    void (*pTest)(); //  --> the deference operator * is applied to the name, before the brackets operator is applied
    void (*p2Test)();
    // pointers of this type will be able to point to functions that don't return anything and that have no
    // parameters

    // we use the "&" (adress operator) plus the name of the funcion to set the pointer previously defined
    pTest = &test;
    // We can miss out '&' and just write the name of the function since the name of the function is in fact a POINTER
    // to that function
    p2Test = test;
    // we call the function being pointed by that pointer, using the deference operator applied to the
    // functions name and afterwards the brackets
    (*pTest)(); // the brackets are used to apply first the operation of deference of the pointer --> *pTest

    // As a name of a function is a pointer to that function, if we define another pointer to that funcition, we can use
    // it in the same way as it was the name of the original function
    p2Test();

    // SUMMARIZING FASTEST WAY TO DECLARE AND USE A POINTER
    void (*p3Test)() = test;
    p3Test();

    // Use a functin with parameters:
    // We have to indicate the types of the parameters in the pointer declaration:
    void (*pTestParam)(int, std::string) = testParameters;
    // During the call of the pointer we have to introduce the parameters
    pTestParam(3, "albert");

    return 0;
}