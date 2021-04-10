#include <iostream>

// function that invoques the lamda expression
// output function --> nothing being returned
// input function --> a string
void testGreet(void (*greet)(std::string))
{
    greet("Luisa");
}

// fucntion that gets the "devide function"
void runDivide(double (*divide)(double a, double b))
{
    std::cout << divide(9, 3) << std::endl;
}

// lambda expression --> []( input parameters ) { expression };
int main()
{
    // lambda expression with inputs
    auto pGreet = [](std::string name) {
        std::cout << "Hello " << name << std::endl;
    }; // functor (pointer to a function)

    // call of the lambda function
    pGreet("Albert ");

    // we try the functio that gets the functor
    testGreet(pGreet);

    // lambda expression with output type --> double
    // NO NEEDED TO SPECIFY THE TYPE OF THE LAMBDA EXPRESSION WHEN ONLY ONE TYPE IS RETURNING -->  the compiler can
    // infer the return type y its own
    // But in case more than one type could be return, we have to help the compiler infering the
    // returning type by adding that type with an arrow to the pointer definition
    auto pDivide = [](double a, double b) -> double {
        if(b == 0) {  // as an exception we avoid 0 division
            return 0; // that returns an "int" if we dont specify the returning type!!!!
        }
        return a / b; // that returns a "double"
    };

    std::cout << pDivide(10.0, 5.0) << std::endl;
    std::cout << pDivide(10.0, 0) << std::endl;
    // Using the lamda exoression as a functor:
    runDivide(pDivide);
    return 0;
}