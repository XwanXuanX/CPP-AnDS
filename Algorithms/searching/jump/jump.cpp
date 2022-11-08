#include <iostream>
#include <cmath>

int JumpSearch(int* Arr, int Arr_len, int x)
{
    // Find the step size to be jumped
    int step = static_cast<int>(sqrt(Arr_len));

    // Find the block where x is present
    int prev = 0;
    while(Arr[__min(step, Arr_len) - 1] < x)
    {
        prev = step;
        step += static_cast<int>(sqrt(Arr_len));
        if(prev >= Arr_len)
            return -1;
    }

    // Do a linear search in the block
    while(Arr[prev] < x)
    {
        prev++;

        // If we reach next block or the end of array, not found
        if(prev == __min(step, Arr_len))
            return -1;
    }

    // Check if element is found
    if(Arr[prev] == x)
        return prev;
    
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