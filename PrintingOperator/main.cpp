#include <algorithm> // std::sort
#include <iostream>
#include <vector>

// PRINTING operator -- Overloading Left Bit Shift <<
// std::cout << test1 << std::endl;
// operator with 2 arguments:
//      cout --> object of the class "ostream"
//      object of the class that we are defining ( the custome class ) --> Test Class
// "<<" has left - rigtht associativity --> first it is done "std::cout << test1" and afterwards <<"std::enld"

// IMPORTANT: because of the first argument (cout) is not of type of the class we are defining (class Test), but it
// belongs to another class ( it is of type "ostream"), we CAN'T IMPLEMENT IT AS A METHOD of the class that we are
// defining!! --> We have to keep the associative propierty of left-right associativity!!! Therefore we have to
// implement it as a funtion that overloads the meaning of "<<" --> we will have to make that function a "friend
// function" of the class "Test" --> we can see the implementation at the end of the class definition

class Test
{
    int id;
    std::string name;

public:
    // DEFAULT CONSTRUCTOR
    Test()
        : id(0)
        , name("")
    {
    }

    // CONSTRUCTOR 2 PARAMETERS
    Test(int id, std::string name)
        : id(id)
        , name(name)
    {
    }

    // WE DONT NEED THE PRINT METHOD ANYMORE, SINCE WE IMPLEMENTED THE << OPERATOR
    /*    void print() const // with that 'const' value we are not allowed to vary the object 'this'
        {
            std::cout << id << ": " << name << std::endl;
        }*/

    // IMPLEMENTATION OF THE ASSINGMENT OPERATOR
    const Test& operator=(const Test& other)
    {
        std::cout << "Assigment running" << std::endl;
        this->id = other.id;
        this->name = other.name;
        return *this; // we return the value where is pointing 'this'
    }

    // IMPLEMENTATION OF THE COPY CONSTRUCTOR
    Test(const Test& other)
    {
        std::cout << "Copy constructor running" << std::endl;
        this->id = other.id;
        this->name = other.name;
        //  *this = other; // we could implement it in that way, since we already implemented the = operator
    }

    // DECLARATION of Left Bit Shift << (Printing) --> we create it as a friend function (it would be in a header
    // file in a real project), to be defined afterwards (in a .cpp file)
    // first argument --> std::cout (class ostream)
    // second argument --> object of that class. As it is defined as a friend function, it will be possible to acces the
    // private attrubutes of that class
    friend std::ostream& operator<<(std::ostream& out,
        const Test& test); // this implementation would be  in a header file ( with the whole class definition)
};

// IMPLEMENTATION of Left Bit Shift << (Printing) -
std::ostream& operator<<(std::ostream& out, const Test& test) // this implementation would be in a cpp file
{
    out << "Id: " << test.id << ", Nombre: " << test.name;
    return out;
}

int main()
{
    Test test1(14, "Juan");
    std::cout << test1 << std::endl;

    Test test2(23, "Pepe");
    std::cout << test1 << test2 << std::endl; // it still works, it is doing associative property
    return 0;
}