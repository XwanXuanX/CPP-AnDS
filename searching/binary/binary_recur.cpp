#include <iostream>

int BinarySearch(int* Arr, int left, int right, int x)
{
    // Base case
    if(right >= 1)
    {
        // Find the mid point
        int mid = left + (right - 1) / 2;

        // If the mid element equal x, then return it
        if(Arr[mid] == x)
            return mid;

        // If the mid element is greater than x, then search left
        if(Arr[mid] > x)
            return BinarySearch(Arr, left, mid - 1, x);
        
        // Otherwise, the element is smaller than x
        // Then search right side
        return BinarySearch(Arr, mid + 1, right, x);
    }

    // When it reach here, meaning x is not present in Arr
    return -1;
}

int main()
{
    int Arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int Arr_len = sizeof(Arr) / sizeof(Arr[0]);

    // Number to be found
    int x = 7;

    // Call binary search
    int result = BinarySearch(Arr, 0, Arr_len - 1, x);

    (result == -1)
        ? std::cout << "Not found" << std::endl
        : std::cout << "Found at " << result << std::endl;
    return 0;
}