#include <iostream>
#include <string>
// Exceptions
// to find serios errors or possible errors (not finding a file to open)

// funcrion that could have an error inside
void mightGoWrong()
{
    bool error1 = false; // error happens during the execution of the function so we set that variable to true
    bool error2 = true;
    if(error1) {
        throw 8;
    }

    if(error2) {
        throw std::string("Something go wrong"); // we create a string object
    }

    std::cout << "function still running " << std::endl;
}

int main()
{
    try {
        mightGoWrong();
    }
    // catch the exception that could be thrown bby try
    catch(int e) {
        std::cout << "Error code: " << e << std::endl;
    } catch(const std::string& e) {
        std::cout << "Error code: " << e << std::endl;
    }

    std::cout << "Still running" << std::endl; // although the exception is catch the main will still continue running
                                               // but not the function where the exceotion was taken...

    return 0;
}