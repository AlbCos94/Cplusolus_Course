#include "ring.h"
#include <iostream>

// Class that supports a Range - Base Loop

// Implement Ring/Circular Buffer --> Array of memory that when it arrives to the end, it starts writing to the beginnig

int main()
{
    ring<std::string> textring(3);
    textring.add("one");
    textring.add("two");
    textring.add("three");
    textring.add("four"); // this one will overwritte the first one
    /* */
    // Iteration through it
    for(int i = 0; i < textring.size(); i++) {
        std::cout << textring.get(i) << std::endl;
    }

    ring<std::string>::iterator it2;
    it2.print();

    return 0;
}