#include <iostream>

// Object slicing

class Parent
{
private:
    int a_value;

public:
    void print()
    {
        std::cout << "parent" << std::endl;
    }

    //  REDIFINED THE DEFAULT CONSTUCTOR (WITH NO PARAMETERS)   , when we add a customizeD "constructor" , " copy
    //  constructor" or " destructor"
    Parent()
        : a_value(0)
    {
    }

    // copy construcotr
    Parent(const Parent& other)
        : a_value(0)
    {
        std::cout << "copy parent" << std::endl;
    }

    // By adding the keyword "virtual", C++ is going to create a table of functions pointers
    // that will point to the proper function depending the right object
    virtual void print2()
    {
        std::cout << "parent" << std::endl;
    }

    // usually we should add a virtual destructor as well
    virtual ~Parent()
    {
    }
};

class Child : public Parent
{
private:
    int b_value;

public:
    void print()
    {
        std::cout << "child" << std::endl;
    }

    // copy construcotr
    // here we can NOT initialize private variable of the Class "Parent" !! --> a_value
    // thats why when you create an object of a subclass first it is called the constructors of all the parent classes!!
    // in orther to initialize the attributes that this "subclass" has no acces to them.
    // But of course we can initialize variables of the subclass --> b_value
    Child()
        : b_value(1)
    {
    }

    // copy construcotr
    Child(const Child& other)
        : b_value(1)
    {
        std::cout << "copy child" << std::endl;
    }

    void print2()
    {
        std::cout << "child" << std::endl;
    }

    // usually we should add a virtual destructor as well
    virtual ~Child()
    {
    }
};

int main()
{
    Child c1;
    c1.print();
    // I can use a reference of type "Parent" to point to an objecet of class "Child",
    // since all the objects of the type "Child" are also of the type "Parent"
    Parent& p1 = c1; // if you have a reference to a parent class, you can assign an object of any class of subclass of
                     // that parent
    p1.print();      // it prints "parent"

    // A pointer defined of type as a parent class, once we refer this pointer to subclasses of this parent class,
    // the functions that have been defined as "virtual" in the parent class, will be accessed by this pointer depending
    // to which subclassed is pointing.
    c1.print2();
    p1.print2();

    // We need also a customized copy contructor to make that an object constructed as one of its subclasses, behaves as
    // that class
    // HERE WE ARE DOING AN OBJECT SLICING --> we are outcasting (marginando) all the info that the subclass gives
    // creamos un objecto de la clase padre " Parent" pero lo adjudicamos a la clase "Child", sin tener la informacion
    // de como se inicializa la clase "Child". De esta manera la parte de la informacion de "Child" la estamos perdiendo
    // WE are changing one type to another
    // thats why the "print2" it is going to act as the function of "parent"
    Parent p2 = Child(); // here we are running the copy constructor of "parent"
    p2.print();
    p2.print2();

    return 0;
}