#include <iostream>

int LinearSearch(int* Arr, int Arr_len, int x)
{
    for(int i = 0; i < Arr_len; i++)
    {
        if(Arr[i] == x)
            return i;
    }
    return -1;
}

int main()
{
    int Arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int Arr_len = sizeof(Arr) / sizeof(Arr[0]);

    // Number to be found
    int x = 7;

    // Call linear search
    int result = LinearSearch(Arr, Arr_len, x);

    (result == -1)
        ? std::cout << "Not found" << std::endl
        : std::cout << "Found at " << result << std::endl;
    return 0;
}