#include <algorithm> // std::sort
#include <iostream>
#include <vector>

// ASSIGNMENT OPERATOR =
// it is a BINARY operator --> two arguments ( 'this' from the same class object and another argument)
// =operator('this', Class other_object_same_class)

// SHADOW Copy by default!!!
// C++ includes always a default implementation for the assigment operator in custome objects
// in that implementation all the attributes are copied from one object to anothers --> in our case 'id' and 'name' will
// be the same if we do:
// Test test1 (2,"Juan");
// Test test2 (2,"Pepe");
// test2 = test1;

// But sometimes when we use the assigment operator "=" we dont want that all the attributes are copied !!!!
// for example, in that case, maybe we want that the 'id' are different, (we can stablish that all objects muss to have
// different ID), but the name can be copied and be the same --> we have to customize the behavoiur of the assigment
// operator!

// IMPORTANT CASE TO USE IT --> A more critical phenoment happens when there is a pointer as an attribute which alocates
// memory on the heap. If we use assign operator with an object with this pointer, to another object --> THE POINTER OF
// BOTH OBJECTS WILL BE POINTING TO THE SAME PLACE!! --> shadow copy can be produced! --> DANGER IN THE BEHAVIOUR!
// solution --> overload the assignment operator and then use deep copies that don't allow the copy of pointers --> then
// we are doing DEEP copies

// ----- //

// All the methods defined on a Class have an implicid argument that is the own object of the class --> 'this' argument

// -----//

// Copy initialization --> when we initialize an object by using "=" we are NOT USING THE ASSINGMENT OPERATOR
// We are invoquing here the implicit COPY CONSTRUCTOR ( nothing related to the ASSIGMENT OPERATOR!! )
// we should implement a copy constructor to control the behaviour of this action

// --- //
// RULE OF 3 IN C++-->if you define a " Copy constructor" or an "Assignment Operator" or a "Destructor" YOU HAVE TO
// IMPLEMENT THE OTHER 2 --> if not you dont control everything
// the destructor should be use to free up memory used by the possible pointer that the class contains

class Test
{
    int id;
    std::string name;

public:
    Test()
        : id(0)
        , name("")
    {
    }

    Test(int id, std::string name)
        : id(id)
        , name(name)
    {
    }

    void print() const // with that 'const' value we are not allowed to vary the object 'this'
    {
        std::cout << id << ": " << name << std::endl;
    }

    // IMPLEMENTATION OF THE ASSINGMENT OPERATOR
    // we will be returning a reference
    const Test& operator=(const Test& other)
    {
        std::cout << "Assigment running" << std::endl;
        this->id = other.id;
        this->name = other.name;
        return *this; // we return the value where is pointing 'this'
    }

    // IMPLEMENTATION OF THE COPY CONSTRUCTOR
    // to control behaviour '=' when initializing an object
    Test(const Test& other)
    {
        std::cout << "Copy constructor running" << std::endl;
        this->id = other.id;
        this->name = other.name;
        //  *this = other; // we could implement it in that way, since we already implemented the = operator
    }
};

int main()
{
    // default way of assigment operator
    Test test1(10, "Mike");
    test1.print();

    Test test2(20, "Bob");

    // we are copying all the members of test1 to tes2
    // test 1 and test 2 are still two independent objects
    test2 = test1;
    test2.print();

    Test test3;
    // prove that an operator is like a method (possible way to call it ):
    test3.operator=(test2); // equivalen to -> test3=test2
    test3.print();

    // Copy initialization --> when we initialize an object by using "=" we are NOT USING THE ASSINGMENT OPERATOR
    // We are invoquing here the implicit COPY CONSTRUCTOR ( nothing related to the ASSIGMENT OPERATOR!! )
    // we should implement a copy constructor to control the behaviour of this action
    Test test4 = test1;
    test4.print();

    return 0;
}