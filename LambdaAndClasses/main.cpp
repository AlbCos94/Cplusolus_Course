#include <iostream>

// class cretation

class Test
{
private:
    int one{ 1 };
    int two{ 2 };

public:
    void run()
    {
        int three = 3;
        int four = 4;

        // lambda expression // using "this" --> we can capture the instance private variable "one" and "two"
        auto pLamda = [this, three, four]() {
            std::cout << three << std::endl;
            std::cout << four << std::endl;

            std::cout << one << std::endl;
            std::cout << two << std::endl;

        };
        pLamda(); // al final se ejecuta la function lamda
    }
};

int main()
{
    Test test1;
    test1.run();
    return 0;
}