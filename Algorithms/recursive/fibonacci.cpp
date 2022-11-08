#include <iostream>

int fib(int num)
{
    // Base case
    if(num <= 1)
        return num;
    
    return (fib(num - 1) + fib(num - 2));
}

int main()
{
    int num = 9;
    std::cout << fib(num) << std::endl;
    return 0;
}