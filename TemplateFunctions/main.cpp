#include <iostream>

// declaration and definitoin of a template function
// also declared and defined in the same file (hpp)
template <class T> // you can also use the nomenclature --> <typename T>
void print(T n)
{
    std::cout << n << std::endl;
}

void print(int value)
{
    std::cout << "Non template veresion: " << value << std::endl;
}

template <class T> // in this case will be necessary to define the type <> in the declaration of the variable
void show()
{
    std::cout << T() << std::endl;
}

int main()
{
    print<int>(5);
    print<char>('s');
    print("Hola me llamo Albert"); // if we dont specify the type, the compiler will deduce it
    print(6);                      // this one will call the Non Template version of the function
    print<>(6);                    // this one calls the tamplate version of the function
    // when two signatures are the same, the fact of writting "<>" will call the template function, otherwise "the non
    // template function"

    show<double>(); // the fact of no indicating the type would mean a compile error in this case, since "show()" has no
                    // type defined in its input parameters

    return 0;
}