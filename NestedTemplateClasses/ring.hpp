#ifndef RING_HPP
#define RING_HPP

#include <iostream>

// as we are going to use a template Class, we dont need the "cpp" file
// template <class T> //
class ring
{
private:
public:
    // Implementation of the iterator that will work inside an object of the class "ring"
    // We can start the implementation of a new class, whereever we want -->  but better to take the definition of the
    // nested templated class out side the class, so it is more clear to understand --->*1
    class iterator;
    /*
     {
   public:
       void print()
       {
           std::cout << "Hello from iterator" << std::endl;
       }
   }; */
};

// --->*1 ( implementation of the nested class )
// |name_main_class|::|name_nested_class|
class ring::iterator
{
public:
    // we can as well separate the implementation of the methods pf the class
    // --->*2
    void print();
    /*
    {
        std::cout << "Hello from iterator" << std::endl;
    }
     */
};

// ---> *2 implementation of the method outside the class definition
// always using the scope operator from left to right to describe to where the function belongs to
// (type_output_parameters) |class1|::|class2|::|....|::|name_function| ( input parameters )
void ring::iterator::print()
{
    std::cout << "Hello from iterator" << std::endl;
}

// IMPLEMENTATION OF A SIMILAR CLASS TO "RING" BUT IMPLEMENTED AS A TEMPLATE CLASS
template <class T> //
class ring2
{
private:
public:
    class iterator;
};

// we have to specify again a template class every time we are nesting (using the scope operator) from another class
// that was a template class
template <class T> //
class ring2<T>::iterator
{
public:
    void print();
};

template <class T> //
void ring2<T>::iterator::print()
{
    std::cout << "Hello from iterator of template class ring2" << std::endl;
}

#endif // RING_HPP