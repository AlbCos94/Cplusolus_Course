#include <iostream>

// Template classes
// Usually the definition and the implementation of a Template Class is carried out in a .hpp file
// The compiler has to see everything together in the same file
// In this definition & implementation will be done in the 'main()' file

template <class T, class K> // T represents the 'type'
class Test
{
private:
    T obj;
    K num;

public:
    Test(T obj, K num)
    {
        this->obj = obj;
        this->num = num;
    }
    void print()
    {
        std::cout << obj << " with num " << num
                  << std::endl; // all the types that could be used, should support "<<" operator
    }
};
// be carefull always defining methods that can be used for a range of types

int main()
{
    Test<std::string, int> test1("Hello", 4);
    test1.print();

    return 0;
}