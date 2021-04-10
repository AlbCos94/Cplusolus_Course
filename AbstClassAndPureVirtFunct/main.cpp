#include <iostream>

// creating a CLASS HIERARCHY and Virtual Functions

// "Abstract classes" allow us to create a hierarchy and force to implement some methods in other subclasses by defining
// pure virtual functions on this abstract class--> virtual function() = 0 , that will have to be implemented in the
// "child classes" in order to be able to instantiate objects of them. In the same way it is possible to forbid the
// instantiation of objects of the type of to these "Abstract classes"

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

    // other pure virtual function
    virtual void run() = 0;
};

// it does no make sense also to instantiate "Dog", because it has no all the virtual functins implemented of its base
// class
class Dog : public Animal
{
public:
    virtual void speak()
    {
        std::cout << "Woof!" << std::endl;
    }
};

// Now we will implement all the virtual fucntions remaning from the parent classes ( Animal and Dog ), so in that way
// we can instantiate objects of that class
// We will obly implemetn "run()" since "speak()" is already implemented in one of ith parent classes (class Dog)
class Labrador : public Dog
{
public:
    // constructor
    Labrador()
    {
        std::cout << "We have created a Labrador object" << std::endl;
    }
    Labrador(const Labrador&)
    {
        std::cout << "We are doing a copy of Labrador" << std::endl;
    }
    virtual void run()
    {
        std::cout << "Labrador running" << std::endl;
    }
};

// it is possible to create functions that have as a parameters objects of an Abstract Class.
// However, when using these functions, we will have to use as parameters objects of derived classes form this "Abstract
// Class" that are not "Abstract Classes"
// In our example we can define a function of Classs "Animal" as a parameter, but afterwards used as a parameter an
// object of Class "Labrador"
void test(Animal& a)
{
    a.run();
}

int main()
{
    // Animal animal1; // We can NOT instantiate an object of an "Abstract Class"

    // We can't not instantiate "Dog" since, it doest implement all the virtual functions that its "base Class" asks for
    // Dog dog;
    // dog.speak();

    // We can instantiate and object of type "Labrador" since all its virtual functions are implemented
    Labrador lab;
    lab.run();
    lab.speak();

    // Creation  an array of Labrador
    Labrador labrador[5]; // it runs the constructor of "Labrador" 5 times
    // we cant not create an array of "Animals" or "Dogs" since they are Abstract Classes and dont have any
    // constructor.. Dog perros[3]; // that wouldnt work

    // But, WE CAN create an array of pointer ( or just a pointer) to an Abstract Class, which will indicate that this
    // pointer CAN point to an object of any class derived from that Abstract Class and that at the same time is NOT
    // Abstract ( so any Class from which an object can be instantiated --> all the virtual functions have been
    // implemented  )
    Animal* animals[5]; // array of pointers
    Animal* animal_one; // singles pointer
    animals[0] = &lab;  // "lab" is an object of type "Animals", "Dog" and "Labrador" // we are copying the direction of
                        // that object
    animals[0]->speak();
    animals[0]->run();

    // Trying our function Test() with a parameter of an Abstract Class ("Animal"), but used with a paramenter of a
    // Class that can be instantiated ("Labrador")
    test(lab);

    return 0;
}