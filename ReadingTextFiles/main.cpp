#include <fstream>
#include <iostream>
using namespace std;

int main()
{

    std::string inFileName = "text_to_read.txt";
    std::ifstream inFile;
    // specific kind of object used just to read the content of a file (input stream class) --> it is
    // used as an input to get info for our program
    inFile.open(inFileName);

    if(inFile.is_open()) {

        // we will display via the screen the lines of the text that we are reading
        std::string line;

        // .eof() --> method that indicated 'end of file
        // ALSO a file object has an "overloaded operator" (regarding its value of True or False(at the end) ) to check
        // directly if a file is at the end or not --> so we can also do --> while(!inFile)
        while(!inFile.eof()) {
            // we use the function getline() to actually grap the whole sentence
            std::getline(inFile, line); // the second argument is the element we want to read into
            std::cout << line << std::endl;
        }

        // inFile >> line; // --> in that case we are only getting one world

        inFile.close();

    } else {
        std::cout << "Cannot open file: " << inFileName << std::endl;
    }

    return 0;
}