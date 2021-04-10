#include <fstream> // stream are objects to which we can write data to or read it from
#include <iostream>
// creating files

int main()
{
    std::ofstream outFile; // object used to write on data, and it has some methods associated like: --> (output strema
                           // class) , used to write data on it , data coming from our program
    std::string outputFileName = "text.txt";
    outFile.open(outputFileName);

    /*
    // Genericexample object 'fstream' for reading and writing
    std::fstream genericFile;
    genericFile.open(outputFileName, ios::out);
     */

    // always check if the file was correctly opened
    if(outFile.is_open()) {
        std::cout << "A file with name: " << outputFileName << " was created" << std::endl;

        // we write into the file
        outFile << "Hello there" << std::endl;
        outFile << 122 << std::endl;
        outFile.close(); // we close the file, to assure not adding more date in it

    } else {
        std::cout << "Could not create file: " << outputFileName << std::endl;
    }
    return 0;
}