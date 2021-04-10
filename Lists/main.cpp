#include <iostream>
#include <list>
// list
//  possible to insert items at the beginning or at the middleand at the ends
// a list is a bunch of nodes, each node has a pointer to the previous and the next node

int main()
{
    std::list<int> numbers;
    numbers.push_back(1); // adding elements in the front
    numbers.push_back(2);
    numbers.push_back(3);
    numbers.push_front(21); // adding elements at the back

    // with list we need to use an interator, the indexes dont work:
    // std::cout << numbers[1] << std::endl; //--> ERROR

    // insert an element into a certain position, always using the predefined methods and an iterator
    std::list<int>::iterator it = numbers.begin();
    it++;                    // to pass to the following element
    numbers.insert(it, 100); // we insert the number 100 to that position
    std::cout << "Element: " << *it << std::endl;

    // erase an element
    std::list<int>::iterator eraseIt = numbers.begin();
    eraseIt++;
    eraseIt = numbers.erase(eraseIt);
    std::cout << "Element: " << *eraseIt << std::endl;

    // so using an iterator we can iterate through it:
    for(std::list<int>::iterator it = numbers.begin(); it != numbers.end(); it++) {
        std::cout << *it << std::endl;
    }

    //// insert element before a certain value or erase a certain velue
    for(std::list<int>::iterator it = numbers.begin(); it != numbers.end();) {
        if(*it == 2) {
            numbers.insert(it, 1234);
        }

        if(*it == 1) {
            it = numbers.erase(it); // doing that the iterator will removed that value and it will go to the following
                                    // one --> no need to do "it++"
        } else {
            it++;
        }
    }

    // loop just to go trough the whole list
    for(std::list<int>::iterator it = numbers.begin(); it != numbers.end(); it++) {
        std::cout << *it << std::endl;
    }

    return 0;
}