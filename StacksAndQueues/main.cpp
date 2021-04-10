#include <iostream>
#include <queue> // queue --> first in, first out structure FIFO (cola super)
#include <stack> // stack --> last in, first out LIFO ( pila de platos para fregar)

class Test
{
private:
    std::string name;

public:
    Test(std::string name)
        : name(name)
    {
    }

    ~Test()
    {
        std::cout << "Object destroyed" << std::endl;
    }

    void print()
    {
        std::cout << name << std::endl;
    }
};

int main()
{

    // STACKS --> FIFO
    std::stack<Test> testStack;

    // add elements to the stack using 'push()'
    testStack.push(Test("Mike")); // to copy in that way an object, we are destroying the original
    testStack.push(Test("John"));
    testStack.push(Test("Sue"));

    // check the first element of the stack (the one of the top):
    // Test test1 = testStack.top(); // last element we introduced to the stack-->  DOING A SHALLOW COPY
    // test1.print();

    /*
     * This is invalid code! Object is destroyed --> better to do a shallow copy
     *
    Test& test1 = testStack.top(); // last element we introduced to the stack--> we get it as the reference
    std::cout << "Referenceia al objeto que se esta destruyendo: " << std::endl;
    testStack.pop(); // we are destroying the first element of the stack from 'testStack' and also the 'test1' object
                     // --> the destructor is only activated once, since we are talking about the first object
    std::cout << "Se ha acabado de destruir el objeto " << std::endl;
    // test1.print(); // REFERENCE REFERS TO DESTROYED OBJECTS --> once it is destroy not to use anymore its methods
     *
     *
     */

    // remove the top elements of the stach
    testStack.pop();
    Test test2 = testStack.top(); // we check which is the top element of the stack --> we do a shallow copy
    test2.print();

    // way to go through the whole stack and display its members
    while(testStack.size() > 0) {
        Test& test = testStack.top();
        test.print();
        testStack.pop();
    }

    std::cout << "Hello World" << std::endl;
    return 0;
}