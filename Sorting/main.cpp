#include <algorithm> // std::sort
#include <iostream>
#include <vector>

// Example of sorting a vector of customizez objects
// We will see how to use the function 'sort()' and which operators our custome objects have to include to be capable of
// sorting them

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

    // WAY A) TO COMPARE --> we overload the comparison operator to be able to use the sorting method
    /*    bool operator<(const Test& other) const
        {
            // return name < other.name; // when using 'sort' we will comapare the objects Test based on the name
            return id < other.id; // when using 'sort' we will compare the objects Test based on the id
        }*/

    // part of the WAY B)
    friend bool comp(const Test& a,
        const Test&
            b); // functions defined with this signature will be allowed to acces the private members of its class
};

// WAY B) TO COMPARE --> other way to sort the objects inside the vector
// the fucntion should be a friend of the class to acces the private members
bool comp(const Test& a, const Test& b)
{
    return a.name < b.name;
    // return a.id < b.id; // when using 'sort' we will compare the objects Test based on the id
}

int main()
{
    std::vector<Test> tests;

    tests.push_back(Test(5, "Mike"));
    tests.push_back(Test(10, "Sue"));
    tests.push_back(Test(7, "Raj"));
    tests.push_back(Test(3, "Vicky"));

    // use of the sort method
    // mandartory to overload the operator < to use this method
    // WAY A) TO COMPARE --> using the sort method and oerloading the < operator
    // std::sort(tests.begin(), tests.end());
    // WAY B) TO COMPARE --> using a function pointer and making it a friend function of the class 'Test'
    std::sort(tests.begin(), tests.end(),
        comp); // the third argument is a 'function pointer' , the function that we will use to sort the 'Test' objects

    for(int i = 0; i != tests.size(); i++) {
        tests[i].print();
    }
    return 0;
}