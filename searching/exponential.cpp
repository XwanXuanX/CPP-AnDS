#include <iostream>

int BinarySearch(int* Arr, int left, int right, int x)
{
    if(left <= right)
    {
        int mid = (left + right) / 2;

        if(Arr[mid] == x)
            return mid;
        else if(Arr[mid] > x)
            return BinarySearch(Arr, left, mid - 1, x);
        else
            return BinarySearch(Arr, mid + 1, right, x);
    }
    return -1;
}

int ExponentialSearch(int* Arr, int Arr_len, int x)
{
    // If x is the first one
    if(Arr[0] == x)
        return 0;
    
    // Find range for binary search
    int i = 1;
    for(; i < Arr_len && Arr[i] <= x; i *= 2);

    // Call binary search
    return BinarySearch(Arr, i / 2, __min(i, Arr_len - 1), x);
}

int main()
{
    int Arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int Arr_len = sizeof(Arr) / sizeof(Arr[0]);

    // Number to be found
    int x = 7;

    // Call exponential search
    int result = ExponentialSearch(Arr, Arr_len, x);

    (result == -1)
        ? std::cout << "Not found" << std::endl
        : std::cout << "Found at " << result << std::endl;
    return 0;
}