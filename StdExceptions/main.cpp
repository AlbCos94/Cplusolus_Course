#include <iostream>

class CanGoWrong
{
public:
    CanGoWrong()
    {
        char* pMemory = new char[9999999999]; // allocate some memory on the constructor
        delete[] pMemory;
    }
};

int main()
{
    try {
        CanGoWrong wrong;
    } catch(std::bad_alloc& e) {
        std::cout << "Caught exception " << e.what() << std::endl; // the "what() " virtual method from the standard
                                                                   // exception gives you an exception of what is going
                                                                   // on
    }

    std::cout << "alles gut" << std::endl;
    return 0;
}