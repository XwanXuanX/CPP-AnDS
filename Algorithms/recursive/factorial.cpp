#include <iostream>

int factorial(int num)
{
    // Base case
    if(num == 1)
        return 1;
    
    return num * factorial(num - 1);
}

int main()
{
    int num = 5;
    std::cout << "Factorial of " << num << " is " << factorial(num) << std::endl;
    return 0;
}