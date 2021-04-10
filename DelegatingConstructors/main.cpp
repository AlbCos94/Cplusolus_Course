#include <iostream>

class Parent
{
    int dogs;
    std::string text;

public:
    /* */
    Parent()
    {
        dogs = 5;
        std::cout << " No parameter parert constructor" << std::endl;
    }
    
    Parent(std::string text)
    {
        dogs = 5;
        this->text = text;
        std::cout << "string parent constructor" << std::endl;
    }
};

class Child : public Parent
{
public:
    Child()
        : Parent("hello") // that means that the Child constructor that doesnt take any parameter will be initialized in
                          // the parent class with the constructor that takes an string
    {
    }
};

int main()
{
    Parent parent(
        "Hello"); // first we have to initialize the upper class, to initialize stuff that will content the child class
    Child child;
    return 0;
}