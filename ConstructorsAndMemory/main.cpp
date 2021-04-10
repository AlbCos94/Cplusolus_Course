#include <iostream>
#include <memory.h>
#include <ostream>
#include <vector>

class Test
{
private:
    static const int SIZE = 100; // number of "ints" in our Buffer
    int* m_pBuffer; // "int Pointer" --> pointer that points to an inter and it is a member of the class Test

public:
    Test() // default not parameter constructor
    {
        std::cout << "constructor" << std::endl;
        m_pBuffer = new int[SIZE]{}; // allocate memory for our "Buffer", "{}" --> to alocate all 0s in that buffer
        // initialize the buffer to all the values as 0, to avoid bugs in the future.. and random values content.
        // way 1
        // memset(m_pBufferm, 0, sizeof(int) * SIZE); // --> you add 100 times the size of a "int" as a memory
    }
    Test(int i)
    {
        std::cout << "parameterized constructor" << std::endl;
        m_pBuffer = new int[SIZE]{};

        for(int i = 0; i < SIZE; i++) {
            m_pBuffer[i] = 7 * i;
        }
    }

    Test(const Test& other) // copy constructor, which defines how an object is constructed, when it is copied per value
                            // (e.g. -> entra en una funcion como parametro)
    {
        std::cout << "copy Constructor" << std::endl;
        m_pBuffer = new int[SIZE]{};
        // " we need to copy the bytes of the object passed "other" to our new object
        memcpy(m_pBuffer, other.m_pBuffer, SIZE * sizeof(int)); // (to what I want to copy, what I want to copy,
                                                                // how many bytes I want to topy - sizeof() gives the
                                                                // number of bytes of a type)
    }

    Test& operator=(const Test& other)
    {
        std::cout << "assigment" << std::endl;
        return *this;
    }

    ~Test()
    {
        std::cout << "destructor" << std::endl;
        delete[] m_pBuffer; // when the object is destructed, we need to remember deleting the memory pointing from
                            // that object, so we avoid memory leaks
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

// init "method" --> method that ist called in each constructor to initalize the members

int main()
{
    Test test1 = getTest(); // copy initialization
    std::cout << test1 << std::endl;
    return 0;
}