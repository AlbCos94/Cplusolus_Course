#include <iostream>
#include <map>

// Using a custom class as the keys of a map

// definition of a custom Class
class Person
{
private:
    std::string name;
    int age;

public:
    // when you set your default constructor with default parameters, the standard definition is lost
    // we have to set also a default constructor without parameters to get a good implementation of the objects as a
    // values of the map

    // default constructor
    Person()
        : name("")
        , age(0)
    {
    }

    // constructor that accepts parameters
    Person(std::string name, int age)
        : name(name)
        , age(age)
    {
    }

    // copy constructor
    Person(const Person& other) // a default one wouls do the same...
    {
        std::cout << "Copy constructor running! " << std::endl;
        name = other.name;
        age = other.age;
    }

    // print method to print what it is in the object
    void print() const
    {
        std::cout << name << ": " << age << std::flush;
    }

    // we overlapp operator to use with the 'Person' object
    bool operator<(const Person& other) const
    {
        // const->  (1st const) we dont want to change the input objet and neither our current object (2nd const)
        // & ->for eficiency, we dont want to create a copy of the person

        return name < other.name; // we ordenate them via the name attribute
    }

    bool operator>(const Person& other) const
    {
        // const->  (1st const) we dont want to change the input objet and neither our current object (2nd const)
        // & ->for eficiency, we dont want to create a copy of the person

        return name > other.name; // we ordenate them via the name attribute
    }
};

int main()
{

    // OVERLOADING OPERATORS EXPLANATION --> example with std::string object
    std::string test1 = "Mike";
    std::string test2 = "Bob";
    // when we compare these two objects with the '<' opertor is like:
    bool test = test1 < test2; // --> equivalent --> bool test = test1.lower_than(test2)
    // the operator '<' is behaving such a method of the objest 'test1' and passing as a paramenter the object
    // 'test2' --> this 'method' return True or False if a certain condition between both objects is accomplished

    std::map<Person, int> people; // now the key element is ther custome class 'Person'

    // the map will be always construct the map using the order of the values
    // now we fill the map setting keys as object that are as well initialized in situs
    people[Person("Mike", 40)] = 4;
    people[Person("Sue", 30)] = 3;
    people[Person("Raj", 20)] = 2;

    for(std::map<Person, int>::iterator it = people.begin(); it != people.end(); it++) {
        std::cout << it->second << ": " << std::flush;
        std::cout << it->first.print();
        std::cout << std::endl;
    }

    return 0;
}