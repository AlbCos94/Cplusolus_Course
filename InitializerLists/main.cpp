#include <initializer_list>
#include <iostream>
#include <vector>

// initializer_list --> in order to use { } as a way to initialize a list or to introduce an array of values as an input
// without declaring it first
class Test
{
public:
    Test(std::initializer_list<std::string> texts)
    {
        for(auto value : texts) {
            std::cout << value << std::endl;
        }
    }

    // passing an array to a  funciton without having to declare it before!!
    // texts is a list of elements of type "string"
    void print(std::initializer_list<std::string> texts)
    {
        for(auto value : texts) {
            std::cout << value << std::endl;
        }
    }
};

int main()
{
    std::vector<int> numbers{ 1, 2, 3, 4, 6 };
    std::cout << numbers[3] << std::endl;

    Test test{ "apple", "orange", "banana" };
    // passing an array to a  funciton without having to declare it before!!
    test.print({ "albert", "costa", "ruiz" });
    return 0;
}