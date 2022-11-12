#include <iostream>

int BinarySearch(int* Arr, int Arr_len, int x)
{
    int left = 0;
    int right = Arr_len - 1;

    // loop while right > left
    while(right - left > 1)
    {
        int mid = (right + left) / 2;

        if(Arr[mid] == x)
            return mid;
        else if(Arr[mid] < x)
            left = mid + 1;
        else
            right = mid;
    }

    return -1;
}

int main()
{
    int Arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int Arr_len = sizeof(Arr) / sizeof(Arr[0]);

    // Number to be found
    int x = 7;

    // Call binary search
    int result = BinarySearch(Arr, Arr_len, x);

    (result == -1)
        ? std::cout << "Not found" << std::endl
        : std::cout << "Found at " << result << std::endl;
    return 0;
}