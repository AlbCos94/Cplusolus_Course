#include <iostream>

// creating a CLASS HIERARCHY

// base Class --> we will derive its 'elements' to other subclasses, but never will make sense to instantiate from this
// example: class Animal --> derived --> class Dog, Cat, Monkey, Snake...

// Base Class
// it does NOT make sense to instantiate "Animal"
class Animal
{
    // Abstract Class --> Class that contains Pure Virtual Functions
    // In the "base Class" we implement the "Pure Virtual Functions"
    // We can NOT instantiate Abstract Classes

public:
    // We will make that all the classes derived from the class "Animal",  "must to speak", so the function "speak()"
    // has to be implemented Doing
    // By "virtual function=0" we are indicating that there is no implementation of the function in the base
    // class and additionally that this is a Pure Virtual Function
    virtual void speak() = 0;
};

// it does make sense to instantiate "Dog"
class Dog : public Animal
{
public:
    virtual void speak()
    {
        std::cout << "Woof" << std::endl;
    }
};

int main()
{
    Dog dog;
    dog.speak();
    return 0;
}