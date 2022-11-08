#include <iostream>

int _1to100(int cur)
{
    // Solve problem while going backward
    // Base case
    if(cur >= 100)
        return cur;
    
    return cur + _1to100(cur + 1);
}

int main()
{
    int result = _1to100(1);
    std::cout << result << std::endl;
    return 0;
}