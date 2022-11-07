#include <iostream>

void PrintArray(int* Arr, int Arr_len)
{
    for(int i = 0; i < Arr_len; i++)
        std::cout << Arr[i] << " ";
    std::cout << std::endl;
}

void InsertionSortRecur(int* Arr, int Arr_len)
{
    // Base case
    if(Arr_len <= 1)
        return;

    // Recursive call
    InsertionSortRecur(Arr, Arr_len - 1);
    
    // Recursive case
    int key = Arr[Arr_len - 1];
    int j = Arr_len - 2;
    for(; j >= 0; j--)
    {
        if(Arr[j] > key)
            Arr[j + 1] = Arr[j];
        else
            break;
    }
    Arr[j + 1] = key;
}

int main()
{
    int Arr[] = {3, 54, 23, 78, 1, 0, 43, 65, 76, 9};
    int Arr_len = sizeof(Arr) / sizeof(Arr[0]);

    std::cout << "Before sorting: " << std::endl;
    PrintArray(Arr, Arr_len);

    InsertionSortRecur(Arr, Arr_len);    // Sort using Insertion Sort Recur

    std::cout << "After sorting: " << std::endl;
    PrintArray(Arr, Arr_len);

    return 0;
}