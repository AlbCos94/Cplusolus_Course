#include <iostream>
#include <vector>

int main()
{

    // Way to loop through a set of elements in a really clean way

    // ARRAY
    // char text[] = {"one", "two", "three"};
    auto texts = { "one", "two", "three" }; // equivalent as what there is above
    for(auto text : texts) {
        // the for loop initialize each time one of the elements of the array we are iterating through
        std::cout << text << std::endl;
    }

    // VECTOR
    std::vector<int> numbers;
    numbers.push_back(5);
    numbers.push_back(7);
    numbers.push_back(9);
    numbers.push_back(11);

    for(auto number : numbers) {
        std::cout << number << std::endl;
    }

    // STRING
    std::string palabra = "hello";
    for(auto c : palabra) {
        std::cout << c << std::endl;
    }
    return 0;
}