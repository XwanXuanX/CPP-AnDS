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

void BubbleSortRecur(int* Arr, int Arr_len)
{
    // Base case: when only one element, no need to reverse
    if(Arr_len == 1)
        return;

    // Recursive case: one pass of bubble sort
    for(int i = 0; i < Arr_len - 1; i++)
    {
        if(Arr[i] > Arr[i + 1])
            Swap(&Arr[i], &Arr[i + 1]);
    }

    // Recursive call
    BubbleSortRecur(Arr, Arr_len - 1);
}

int main()
{
    int Arr[] = {3, 54, 23, 78, 1, 0, 43, 65, 76, 9};
    int Arr_len = sizeof(Arr) / sizeof(Arr[0]);

    std::cout << "Before sorting: " << std::endl;
    PrintArray(Arr, Arr_len);

    BubbleSortRecur(Arr, Arr_len);    // Sorted used Bubble Sort Recur

    std::cout << "After sorting: " << std::endl;
    PrintArray(Arr, Arr_len);

    return 0;
}