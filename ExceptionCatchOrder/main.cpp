#include <exception>
#include <iostream>

void goesWrong()
{
    bool error1Detected = true;
    bool error2Detected = false;

    if(error1Detected) {
        throw std::bad_alloc(); // error related to not enough memory
    }

    if(error2Detected) {
        throw std::exception(); // generic error
    }
}

int main()
{

    // wrong way:
    // ->regarding the polymorphis of the class Exception and it derived classes we have to consider the order of the
    // catching of the exeptions
    // -> Next example (commented) shows a wrong way of using catching exceptions. In the first condition a parent class
    // is expected (std::exception) , the first catch block is expecting something of type "exception", and "bad_aloc"
    // is a sub class of that exception class. Because of the polymorfism an error of that subclass will fit also in the
    // places of errors of the parent class (since an object of the type of that subclass is also an object of type of
    // the parent class)
    // -> Therefore in the following example an exception of class "bad_alloc" will be caught by the balock of
    // "exception",
    // -> to solve this issue, all subclasses should be defined before than the respective classes and then all the
    // exceptions will be able to be caught in its specific blocks
    // CATCH in a wrong order: (commented)
    /*
    try {
        goesWrong();
    } catch(std::exception& e) { // first the parent class --> WRONG!!
        std::cout << "Catching exception: " << e.what() << std::endl;
    } catch(std::bad_alloc& e) {
        std::cout << "Catching bad_alloc: " << e.what() << std::endl;
    }
    */

    // CATCH in the correct order
    try {
        goesWrong();
    } catch(std::bad_alloc& e) { // first the subclass --> CORRECT!
        std::cout << "Catching bad_alloc exception: " << e.what() << std::endl;
    } catch(std::exception& e) {
        std::cout << "Catching generic exception: " << e.what() << std::endl;
    }
    // ALWAYS PUT THE SUBCLASSES OF THE EXCEPTIONS BEFORE THE PARENT CLASSES IN THE CATCHING BLOCKS!!
    // so we get the correct exception for each one!!
    return 0;
}