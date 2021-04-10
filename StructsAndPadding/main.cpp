#include <fstream>
#include <iostream>

// creation of a 'struct' suitable for writting to a file
// struct are usually for writting to a file

// preprocesor to store each data one after the other directly
/*
 * #pragma pack(instructs the compiler to pack structure members with particular alignment)
 * Most compilers, when you declare a struct, will insert PADDING between members to ensure that they are aligned to
 * appropriate addresses in memory (usually a multiple of the type's size). '#pragma' avoids the performance penalty (or
 * outright error) on some architectures associated with accessing variables that are not aligned properly.
 */
#pragma pack(push, 1) // --> to make the struct 'not padded'

struct Person {
    // string name; --> the 'string' object used a pointer and uses 'new' to allocate memory on the heap (much bigger
    // area of memory than the stack) since it doesnt know how many memory you are going to save
    //, each time a 'string' variable is declared
    // if we used 'string variable' as a member of a struct to write on a file text, what we are writting is a pointer
    // to that file, if we afterwards we want to read that text, that pointer will be pointing somewhere else
    // as well we are using much more memory that the one that we need
    // BETTER USE char[size] array --> we set the maximum of characters that we will used:
    char name[50];
    int age;
    double height;
};
// now a program could read again this struct of data

int main()
{
    std::cout << sizeof(Person) << std::endl; // with pragme we get 62 bytes, without it 64 bytes

    // we fill the struct 'Person' with data
    Person someone = { "Frodo", 220, 0.8 }; // it will respect the order of the struct definition

    // working with binary files --> (name_file).bin
    std::string fileName = "test.bin";

    ////////   WRITE A BINARY FILE //////////
    std::ofstream outputFile; // we declare the object that represents the output file
    outputFile.open(fileName, std::ios::binary);

    if(outputFile.is_open()) {

        // one way to write
        // outputFile.write((char*)&someone, sizeof(Person)); // we have to cast a pointer to a type char of that struct
        // of data

        // better way to do it
        outputFile.write(reinterpret_cast<char*>(&someone),
            sizeof(Person)); // we have to cast a pointer to a type char of that struct of data
        outputFile.close();
    } else {
        std::cout << "Could not create file " + fileName;
    }

    ///// READ A BINARY FILE ///////

    Person someoneElse = {}; // it will respect the order of the struct definition

    std::ifstream inputFile; // we declare the object that represents the input file
    inputFile.open(fileName, std::ios::binary);

    if(inputFile.is_open()) {

        // one way to write
        // we have to cast a pointer to a type char of that struct of data
        // outputFile.write((char*)&someone, sizeof(Person));

        // better way to do it
        // we have to cast a pointer to a type char of that struct of data
        inputFile.read(reinterpret_cast<char*>(&someoneElse), sizeof(Person));

        outputFile.close();
    } else {
        std::cout << "Could not create file " + fileName;
    }

    std::cout << someoneElse.name << ", " << someoneElse.age << ", " << someoneElse.height << std::endl;

    return 0;
}