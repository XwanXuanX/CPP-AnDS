#include <iostream>

void PrintArray(int* Arr, int Arr_len)
{
    for(int i = 0; i < Arr_len; i++)
        std::cout << Arr[i] << " ";
    std::cout << std::endl;
}

void InsertionSort(int* Arr, int Arr_len)
{
    for(int i = 1; i < Arr_len; i++)    // Start from 1: Assume 1st element is in order
    {
        int key = Arr[i];
        int j = i - 1;
        for(; j >= 0; j--)
        {
            if(Arr[j] > key)
                Arr[j + 1] = Arr[j];
            else
                break;
        }
        Arr[j + 1] = key;
    }
}

int main()
{
    int Arr[] = {3, 54, 23, 78, 1, 0, 43, 65, 76, 9};
    int Arr_len = sizeof(Arr) / sizeof(Arr[0]);

    std::cout << "Before sorting: " << std::endl;
    PrintArray(Arr, Arr_len);

    InsertionSort(Arr, Arr_len);    // Sort using Insertion Sort

    std::cout << "After sorting: " << std::endl;
    PrintArray(Arr, Arr_len);

    return 0;
}