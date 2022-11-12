#include <iostream>
#include <cmath>

int JumpSearch(int* Arr, int Arr_len, int x)
{
    // Find the block size to be jumped
    const int step = static_cast<int>(sqrt(Arr_len));

    // Do a gapped linear search, until find an element greater than x, or reach the end of Arr
    int i = 0;
    for(; i < Arr_len; i += step)
    {
        if(Arr[i] >= x)
            break;
        
        // If index reach the end and not found
        if(i == Arr_len - 1)
            return -1;
    }

    // Do a no gapped backward linear search to find the element
    for(; i >= 0; i--)
    {
        // If found then return index
        if(Arr[i] == x)
            return i;
        // If element is smaller than x, not found
        if(Arr[i] < x)
            return -1;
    }
    return -1;
}

int main()
{
    int Arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int Arr_len = sizeof(Arr) / sizeof(Arr[0]);

    // Number to be found
    int x = 7;

    // Call jump search
    int result = JumpSearch(Arr, Arr_len, x);

    (result == -1)
        ? std::cout << "Not found" << std::endl
        : std::cout << "Found at " << result << std::endl;
    return 0;
}