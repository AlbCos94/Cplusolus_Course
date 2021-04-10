#include <iostream>
#include <vector>

// Traditional initialization --> C++ 98

int main()
{
    // USE OF CURLY BRACKETS FOR THE INITIALIZATION
    // array
    int values[] = { 1, 4, 5 };
    std::cout << values[0] << std::endl;

    // Class --> by default all the members are private
    class C1
    {
    public:
        std::string text;
        int id;
    };

    C1 object1 = { "hello", 34 };
    std::cout << object1.text << std::endl;

    // Struct --> by default all the members are public
    // "structs" are usually used to keep some data together that have something in common --> " to order and organize
    // data"
    struct S1 {
        std::string text;
        int id;
    };

    S1 object2 = { "goodbye", 34 };
    std::cout << object2.text << std::endl;

    // We can declare variable of the struct inmediately after the struct definition
    struct S2 {
        std::string text;
        int id;
    } object_s2;

    object_s2 = { "casa", 2 };
    std::cout << object_s2.text << std::endl;

    // It is even possible to use anonimoze struc names, when the variable initialization will be only done once after
    // the struct definition
    struct {
        std::string text;
        int id;
    } object_zz_1 = { "mem", 26 }, object_zz_2 = { "memoo", 66 };
    std::cout << object_zz_1.text << std::endl;
    std::cout << object_zz_2.id << std::endl;

    // Vector
    // for Vector the only way to initialize them in c++98 is by using "push_back()".... :-(
    std::vector<std::string> strings;
    strings.push_back("One");
    strings.push_back("Two");

    return 0;
}