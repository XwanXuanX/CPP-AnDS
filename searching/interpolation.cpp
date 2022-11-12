#include <iostream>

int InterpolationSearch(int* Arr, int Arr_len, int x)
{
    int left = 0;
    int right = Arr_len - 1;

    while(left <= right && x >= Arr[left] && x <= Arr[right])
    {
        if(left == right)
        {
            if(Arr[left] == x)
                return left;
            return -1;
        }

        // Using interpolation formula
        int pos = left + (((double)(right - left) / (Arr[right] - Arr[left])) * (x - Arr[left]));

        if(Arr[pos] == x)
            return pos;
        else if(Arr[pos] < x)
            left = pos + 1;
        else
            right = pos - 1;
    }
    return -1;
}

int main()
{
    int Arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int Arr_len = sizeof(Arr) / sizeof(Arr[0]);

    // Number to be found
    int x = 7;

    // Call interpolation search
    int result = InterpolationSearch(Arr, Arr_len, x);

    (result == -1)
        ? std::cout << "Not found" << std::endl
        : std::cout << "Found at " << result << std::endl;
    return 0;
}