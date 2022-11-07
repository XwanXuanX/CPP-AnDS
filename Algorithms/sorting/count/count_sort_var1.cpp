#include <iostream>

void PrintArray(int* Arr, int Arr_len)
{
    for(int i = 0; i < Arr_len; i++)
        std::cout << Arr[i] << " ";
    std::cout << std::endl;
}

void CountSortVar1(int* Arr, int Arr_len)
{
    if(Arr_len < 2)
        return;
    
    // Get the max element in array
    int max = Arr[0];
    for(int i = 1; i < Arr_len; i++)
    {
        if(Arr[i] > max)
            max = Arr[i];
    }

    // Create count array
    int* count = new int[max + 1];
    for(int i = 0; i < max + 1; i++)
        count[i] = 0;
    
    // Count the occurance of each element in Arr
    for(int i = 0; i < Arr_len; i++)
    {
        int index = Arr[i];
        count[index]++;
    }

    // Put the counted number into original array
    int k = 0;
    for(int i = 0; i < max + 1; i++)
    {
        for(int j = 0; j < count[i]; j++)
        {
            Arr[k] = i;
            k++;
        }
    }
}

int main()
{
    int Arr[] = {3, 9, 3, 7, 1, 0, 4, 0, 7, 9};
    int Arr_len = sizeof(Arr) / sizeof(Arr[0]);

    std::cout << "Before sorting: " << std::endl;
    PrintArray(Arr, Arr_len);

    CountSortVar1(Arr, Arr_len);    // Sort using count sort

    std::cout << "After sorting: " << std::endl;
    PrintArray(Arr, Arr_len);

    return 0;
}