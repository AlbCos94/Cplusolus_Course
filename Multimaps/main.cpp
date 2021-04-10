#include <iostream>
#include <map>

// multimaps --> we can store different elements with the same key

int main()
{
    std::multimap<int, std::string> lookup;
    lookup.insert(std::make_pair(30, "Mike"));
    lookup.insert(std::make_pair(10, "Vicky"));
    lookup.insert(std::make_pair(30, "Raj")); // in a normal map, this element would have overriten the first element
    lookup.insert(std::make_pair(20, "Bob"));

    for(std::multimap<int, std::string>::iterator it = lookup.begin(); it != lookup.end(); it++) {
        std::cout << it->first << ": " << it->second << std::endl;
    }

    std::cout << std::endl;

    // GET ONLY THE ELEMENTS OF A CERTAIN 'key' ( in an efficient way)

    // Using the method 'equal_range(20)' we get a pair with the first iterator and the iterator after the last
    // iterator.
    // The set of iterators represented by this pair, represents the whole amount of iterators pointing to
    // elements  with the same key
    std::pair<std::multimap<int, std::string>::iterator, std::multimap<int, std::string>::iterator> its =
        lookup.equal_range(30); // we set a bunch of iterators

    for(std::multimap<int, std::string>::iterator it = its.first; it != its.second; it++) {
        std::cout << it->first << ": " << it->second << std::endl;
    }

    return 0;
}