#include "ring.h"
#include <iostream>

int main()
{

    ring<std::string> textring(3);

    textring.add("one");
    textring.add("two");
    textring.add("three");
    textring.add("four");
    textring.add("five");
    textring.add("six");

    // What we want to implement:
    // Traditional style iteration loop --> C++98
    for(ring<std::string>::iterator it = textring.begin(); it != textring.end(); it++) {
        std::cout << *it << std::endl;
    }

    // in that way we will be able to implemente also:
    // New style iteration loop--> C++11
    for(const std::string value : textring) {
        std::cout << value << std::endl;
    }

    return 0;
}