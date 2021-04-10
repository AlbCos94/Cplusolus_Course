#include <exception>
#include <iostream>
// throw exception of any class

// we create a class with a name related somehow with the error to which is going to be related to
class MyException : public std::exception // we derive it from the standard class of exceptions --> which include //
                                          // virtual method that we will have to include
{
public:
    virtual const char* what() const noexcept
    {
        return "Something bad happened";
    }
};

// random class that does stuff and that we want to test for errors
class Test
{
public:
    void goesWrong()
    {
        throw MyException();
    }
};

int main()
{
    Test test;
    try {
        test.goesWrong();
    } catch(MyException& e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}