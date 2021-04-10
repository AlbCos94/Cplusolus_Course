#include <algorithm>
#include <iostream>
#include <vector>

// return True if the string is of size 3
bool match(std::string test)
{
    return test.size() == 3;
}

// our own version of "count_if"
int count_strings(std::vector<std::string>& texts, bool (*match)(std::string test))
{
    int c = 0;
    for(const std::string& e : texts) {
        c += match(e); // return 1 if it is True, so it will start increasing
    }
    return c;
}

int main()
{
    std::vector<std::string> texts;
    texts.push_back("one");
    texts.push_back("two");
    texts.push_back("three");
    texts.push_back("two");
    texts.push_back("four");
    texts.push_back("two");
    texts.push_back("three");
    texts.push_back("one");

    // Use of a pointer to a function
    // count_if function from the library ¨algorithm" passes a function AS A POINTER (the name of the function is
    // already a pointer) to a set of elements along which, we can iterate.
    std::cout << std::count_if(texts.begin(), texts.end(), match) << std::endl;

    std::cout << count_strings(texts, match) << std::endl;

    return 0;
}