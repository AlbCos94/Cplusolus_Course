#include <iostream>
#include <vector>

int main()
{
    std::vector<double> numbers(20); // vector with a size of 20  and it has probably a capacity of 20 elements

    std::cout << "Size: " << numbers.size() << std::endl;

    int capacity =
        numbers.capacity(); // size of the internal array that the vector reserving to use, not the whole internal size
                            // is necessary occupied
    std::cout << "Capacity: " << capacity << std::endl;

    for(int i = 0; i < 10000; i++) {
        if(numbers.capacity() != capacity) {
            capacity = numbers.capacity();
            // We will display every time when the capacity is changed
            std::cout << "Capacity: " << capacity << std::endl;
            // the capacity changed exponentially regarding the number of elements in the vector
        }
        numbers.push_back(i);
    }

    // changin the size of the vetor (using resize() or clear() ) doesnt mean changing the capacity !!
    // vector.size() != vector.capacity()

    // change size --> vector.resize(new size)
    // change capacity --> vector.capacity(new capacity)

    numbers.reserve(100000); // in order to alreay adjust the minimum capacity we want to have
    std::cout << "Size: " << numbers.size() << std::endl;         // size will be still the same
    std::cout << "Capacity: " << numbers.capacity() << std::endl; // capacity will be adjusted

    return 0;
}