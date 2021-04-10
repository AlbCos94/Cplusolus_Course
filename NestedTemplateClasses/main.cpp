#include "ring.hpp"
#include <iostream>
// Nested template Clases
// Class that supports a Range - Base Loop

// Implement Ring/Circular Buffer --> Array of memory that when it arrives to the end, it starts writing to the beginnig
// Implementation of nested classes in order to implement that Circular Buffer
int main()
{

    // Iterator that will be used with out object "ring"
    // typical expressin of an iterator --> |type_its_pointing_to|::iterator it;
    // that means that inside the class of what the iterator is pointing to, we have to implement a new class to use the
    // scope operator --> "::" and then implement there the iterator functionality
    ring::iterator it;
    it.print();

    ring2<std::string>::iterator it2;
    it2.print();

    // implementation using template classes --> shown in the implementation of "ring2"

    /*
    // Iteration through it
    for(int i = 0; i < textring.size(); i++) {
        std::cout << textring.get(i) << std::endl;
    }
     */
    return 0;
}