#include <iostream>
#include <map>
// Maps
// allows us to store "pairs" of 'value' & 'keys' --> (key : value)
// the key is unic!!!, if we add a value with the same key, we will override that value
// always ordered in alphabetic order
int main()
{
    std::map<std::string, int> ages;

    ages["Mike"] = 40; // we store the value '40' under the key 'Mike'
    ages["Raj"] = 20;
    ages["Vicky"] = 30;

    std::cout << ages["Raj"] << std::endl;

    // if we consult the value of a key using the brackets operator, if it doesnt exist, it will added it by anexing a 0
    std::cout << ages["Albert"] << std::endl;

    // as a map is a set of pairs , we can insert directly a new element as a pair --> using the method "insert()"
    std::pair<std::string, int> element_to_add("Albert Costa", 123);
    ages.insert(element_to_add);

    // a cleaner and faster way to add a new pair is by creating a pair using the "make_pair" function
    ages.insert(std::make_pair("Peter 2", 100));

    // the good way to check if a value is in a map..:
    // the method "find()" of the map object returns an iterator at the next position of the last element of the map, if
    // the key was not found / otherwise it returns an iterator
    if(ages.find("Vicky") != ages.end()) {
        std::cout << "Found Vicky" << std::endl;
    } else {
        std::cout << "Key not found" << std::endl;
    }

    // iterate through a map --> using an iterator (like with a list)
    // to set an iterator --> {type it is pointing (it will point each time to an element of that set) } :: iterator
    for(std::map<std::string, int>::iterator it = ages.begin(); it != ages.end(); it++) {
        // view as an object, each element of the map has attributes to refer to the key:
        std::cout << it->first << std::endl;
        // and the the value associated:
        std::cout << it->second << std::endl;
    }

    // iterate using pairs:
    for(std::map<std::string, int>::iterator it = ages.begin(); it != ages.end(); it++) {
        // pair declaration
        std::pair<std::string, int> age = *it; // each element of the map is a pair

        std::cout << age.first << ": " << age.second << std::endl;
        // std::cout << age[0] << ": " << age[1] << std::endl; // --> WRONG --> a pair is accesed using "first" and
        // "second" method! -- > not brackets
    }

    return 0;
}