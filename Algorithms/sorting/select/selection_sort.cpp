#include <iostream>

void PrintArray(int* Arr, int Arr_len)
{
    for(int i = 0; i < Arr_len; i++)
        std::cout << Arr[i] << " ";
    std::cout << std::endl;
}

void Swap(int* num1, int* num2)
{
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

void SelectionSort(int* Arr, int Arr_len)
{
    for(int i = 0; i < Arr_len - 1; i++)
    {
        int min_index = i;
        for(int j = i + 1; j < Arr_len; j++)
        {
            if(Arr[min_index] > Arr[j])
                min_index = j;
        }
        if(min_index != i)
            Swap(&Arr[i], &Arr[min_index]);
    }
}

int main()
{
    int Arr[] = {3, 54, 23, 78, 1, 0, 43, 65, 76, 9};
    int Arr_len = sizeof(Arr) / sizeof(Arr[0]);

    std::cout << "Before sorting: " << std::endl;
    PrintArray(Arr, Arr_len);

    SelectionSort(Arr, Arr_len);    // Sort using Selection Sort

    std::cout << "After sorting: " << std::endl;
    PrintArray(Arr, Arr_len);

    return 0;
}