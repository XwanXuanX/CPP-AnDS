#include <iostream>

// declarations of two driver functions
void TestOrdered();
void TestOpen();

int main()
{
    std::string T;
    std::cin >> T;
    if(T == "OPEN")
        TestOpen();
    else if(T == "ORDERED")
        TestOrdered();
    return 0;
}