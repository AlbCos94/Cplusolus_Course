#include <iostream>
#include <map>

// Using a custom class as the values of a map

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
    Person()
        : name("")
        , age(0)
    {
    }

    Person(std::string name, int age)
        : name(name)
        , age(age)
    {
    }

    void print() const
    {
        std::cout << name << ": " << age << std::endl;
    }
};

int main()
{
    std::map<int, Person> people;

    // the map will be always construct the map using the order of the values
    people[0] = Person("Mike", 40);
    people[50] = Person("Vicky", 30);
    people[2] = Person("Raj", 50);

    for(std::map<int, Person>::iterator it = people.begin(); it != people.end(); it++) {
        it->second.print();
    }

    return 0;
}