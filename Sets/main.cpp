#include <iostream>
#include <set>

// SETS
/*
 * only includes unique elements
 * also as in maps we go through the whole set by using an iterator
 * the elements are ordered automatically when inserted
 *
 */

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

    void print() const
    {
        std::cout << id << ": " << name << std::endl;
    }

    // we need to overload an operator '<' to use some method of multimap

    bool operator<(const Test& other) const
    {
        return name < other.name; // when inserting a new object of the class Test, it will compare the name to see if
                                  // that element already it is in the set. So a new object Test with the attribute
                                  // 'name' equal to the one of another element in the set, will overwrite that element
    }

    bool operator!=(const Test& other) const
    {
        return name != other.name;
    }

    friend std::ostream& operator<<(std::ostream& os,
        const Test& a_test); // friend function --> it will be used to overload the operator <<
};

// some overloaded operations have to be implemented as a friend function outside the class ( the operator << is a case)
// :
std::ostream& operator<<(std::ostream& os, const Test& a_test)
{
    os << a_test.id << ": " << a_test.name;
    return os;
}

int main()
{
    std::set<int> numbers;

    numbers.insert(50);
    numbers.insert(10);
    numbers.insert(30);
    numbers.insert(40);
    numbers.insert(25);
    numbers.insert(35);

    for(std::set<int>::iterator it = numbers.begin(); it != numbers.end(); it++) {
        std::cout << *it << std::endl;
    }

    // check if an object is in a set --> using 'find()' method and an iterator

    std::set<int>::iterator itFind = numbers.find(30); // gives the iterator pointing to that element, in case it doesnt
                                                       // exist, it gives an iterator pointing to the end of the set
                                                       // object 'numbers'

    if(itFind != numbers.end()) {
        std::cout << "Found: " << *itFind << std::endl;
    }

    // another way to check if an element it is in a set
    if(numbers.count(30)) {
        std::cout << "Number found " << std::endl;
    }

    // USE OF OBJECTS OF A CUSTOME CLASS IN A SET -->> we will have to overload some operations in that class to manage
    // to use method of the std class 'set'

    std::set<Test> tests;
    tests.insert(Test(10, "Mike"));
    tests.insert(Test(30, "Joe"));
    tests.insert(Test(20, "Sue"));
    tests.insert(Test(20, "Joe"));

    /*
    for(std::set<int>::iterator it = tests.begin(); it != tests.end(); it++) {
        std::cout << *it << std::endl;
    }
    */

    for(auto it = tests.begin(); it != tests.end(); it++) {
        std::cout << *it << std::endl;
    }

    return 0;
}