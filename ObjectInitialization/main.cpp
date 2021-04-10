#include <iostream>

// initialization of objects in C++ 11

class Test
{
    int id{ 3 }; // initialization of the attibutes using { }
    std::string name{ "Mike" };

public:
    // when implementing a customized constructor, we need also always to implement the default constructor!!
    Test() = default;

    // the customized constructor runs after the default initialization of the variables !!!!! --> "id{3}" and
    // "name{"Mike"}" --> SO WHEN WE INDICATE PARAMETERS WHEN INITIALIZATING THAT WILL PREVAIL
    Test(int id)
        : id(id)
    {
    }

    // also define the default copy constructor
    Test(const Test& other) = default;
    // an it is equivalent to say:: (implementation of assignment operator)
    Test& operator=(const Test& other) = default;

    void print()
    {
        std::cout << id << ": " << name << std::endl;
    }
};

// MAKING A CLASS THAT IS NOT COPYABLE
class TestV2
{
    int id{ 3 }; // initialization of the attibutes using { }
    std::string name{ "Mike" };

public:
    // when implementing a customized constructor, we need also always to implement the default constructor!!
    TestV2() = default;

    // the customized constructor runs after the default initialization of the variables !!!!! --> "id{3}" and
    // "name{"Mike"}"
    TestV2(int id)
        : id(id)
    {
    }

    // also define the default copy constructor --> WITH delete WE MAKE IT NO COPYABLE --> we are deleting the default
    // implementation!!
    TestV2(const Test& other) = delete;
    // an it is equivalent to say:: (implementation of assignment operator)
    TestV2& operator=(const Test& other) = delete;

    void print()
    {
        std::cout << id << ": " << name << std::endl;
    }
};

int main()
{
    Test test;
    test.print();

    Test test1(77); // this will be overrate the default initialization of the attributes of "Test"
    test1.print();

    Test test2 = test1; // copy initialization --> that invoques the copy constructor
    test2 = test;       // this is invoking the assignment operator
    test2.print();

    TestV2 test3;
    test3.print();
    TestV2 test4{ 34 };
    TestV2 test5 = test4; // copy constructor invoqued in the initialization // NO DEBERIA FUNCITONAR...
    test3 = test4;
    test3.print();
    return 0;
}