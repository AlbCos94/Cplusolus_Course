#include <iostream>
#include <vector>

int main()
{

    // In C++ 11 using { } we can initializice almost everything

    // normal variables
    int entero{};
    int entero2{ 5 };
    std::string text{ "Hello" };

    std::cout << entero << std::endl;
    std::cout << entero2 << std::endl;

    // initialazion of arrays
    int numbers[]{ 1, 2, 3 };
    std::cout << numbers[1] << std::endl;

    // pointer to an array of ints
    int* pInts = new int[3]{ 1, 2, 3 }; // [number elements] {initilization of the elements}
    std::cout << pInts[1] << std::endl;
    delete pInts;

    // pointer pointing to a variable initilaization ( not forget & to get the address of the variables )
    int* pSomething2{ &entero2 };
    std::cout << *pSomething2 << std::endl;

    // pointer pointing to 0
    int* pSomething{ NULL }; // equivalent to "int *pSomething = nullptr";

    // used in in struct or classe
    struct {
        int value;
        std::string text;
    } s1{ 88, "Hi" };
    std::cout << s1.value << std::endl;

    // initialization of vectors
    std::vector<std::string> vectorS{ "one", "two", "three" };
    std::cout << vectorS[2] << std::endl;

    return 0;
}