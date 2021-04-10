#include <fstream>
#include <iostream>
// read moe complicated formatted data from files

// parsing --> get information out of a string or a file

int main()
{
    std::string filename = "parsing_example.txt"; // remember, string --> " " / character --> ' '
    std::ifstream input;

    input.open(filename);

    if(!input.is_open()) { // por si no se ha podido abrir el archivo
        return 1;
    }

    while(input) {

        std::string line;

        // first we save the number of the country in the 'line' string
        // we know where it ends by using getline() and the delimitator ':'
        std::getline(input, line, ':'); // we set a delimeter to consider when the number comes

        // from the input we get the number as well, by sabving the varible to the integer variable named
        // 'population'
        int population;
        input >> population;

        // we get the next character of this line by:
        input.get();

        std::cout << line << " -- " << population << std::endl;
    }

    return 0;
}