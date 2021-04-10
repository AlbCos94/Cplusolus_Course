#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

// function
bool check(std::string& test)
{
    return (test.size() == 3);
}

class Check
{
public:
    bool operator()(std::string& test)
    {
        return (test.size() == 5);
    }

} check1; // we even create already an object that belongs to that class --> check1

// creation of a function that accepts another function as a parameter

void run(std::function<bool(std::string&)> check) // --> means that as an input "run" accepts a functin that returns a
                                                  // "bool" and has as input parametre a string
{
    std::string test = "dog";
    std::cout << check(test) << std::endl;
}

int main()
{
    std::vector<std::string> vec{ "one", "two", "three" };
    int size = 3;
    int size_5 = 5;

    auto lambda = [size](std::string test) { return test.size() == size; };

    // use of "count_if" function:

    // using a lambda expression among a set of elements as the expression
    // we capture variable size as a locar variable
    int count = std::count_if(vec.begin(), vec.end(), [size](std::string test) { return test.size() == size; });
    std::cout << "the number of words of size " << size << " is " << count << std::endl;

    // we use a functor (pointer to a function) as an expression to evaluate the elements
    int count2 = count_if(vec.begin(), vec.end(), check);
    std::cout << "the number of words of size " << size << " is " << count2 << std::endl;

    // we use an object of a created class, that has the operator "( )" defined --> Class Check
    // and simply pass that object as the expresseion
    int count3 = count_if(vec.begin(), vec.end(), check1);
    std::cout << "the number of words of size " << size_5 << " is " << count3 << std::endl;

    run(lambda);
    run(check1);
    return 0;
}