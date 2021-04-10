#include <iostream>
#include <ostream>
#include <vector>

class Test
{
public:
    Test() // default not parameter constructor
    {
        std::cout << "constructor" << std::endl;
    }
    Test(int i)
    {
        std::cout << "parameterized constructor" << std::endl;
    }

    Test(const Test& other) // copy constructor, which defines how an object is constructed, when it is copied per value
                            // (e.g. -> entra en una funcion como parametro)
    {
        std::cout << "copy Constructor" << std::endl;
    }

    Test& operator=(const Test& other)
    {
        std::cout << "assigment" << std::endl;
        return *this;
    }

    ~Test()
    {
        std::cout << "destructor" << std::endl;
    }

    friend std::ostream& operator<<(std::ostream& out, const Test& test);
};

std::ostream& operator<<(std::ostream& out, const Test& test)
{
    std::cout << "Hello from test";
    return out;
}

// function that returns a new "Test" object
// when a function returns an OBject of a Class, they have to copy that object
// returning an object per value can be very inneficient
Test getTest()
{
    return Test();
}

int main()
{
    Test test1 = getTest(); // copy initialization
    std::cout << test1 << std::endl;
    return 0;
}