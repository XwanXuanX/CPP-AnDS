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

void SelectionSortPlus(int* Arr, int Arr_len)
{
    int left = 0;               // point to the left bound
    int right = Arr_len - 1;    // point to the right bound

    while(left < right)
    {
        int min_index = left;
        int max_index = left;
        for(int i = left; i <= right; i++)
        {
            if(Arr[min_index] > Arr[i])
                min_index = i;
            if(Arr[max_index] < Arr[i])
                max_index = i;
        }

        if(min_index != left)   Swap(&Arr[min_index], &Arr[left]);

        if(max_index == left)   max_index = min_index;

        if(max_index != right)  Swap(&Arr[max_index], &Arr[right]);

        left++;
        right--;
    }
}

int main()
{
    int Arr[] = {3, 54, 23, 78, 1, 0, 43, 65, 76, 9};
    int Arr_len = sizeof(Arr) / sizeof(Arr[0]);

    std::cout << "Before sorting: " << std::endl;
    PrintArray(Arr, Arr_len);

    SelectionSortPlus(Arr, Arr_len);    // Sort using Selection Sort Plus

    std::cout << "After sorting: " << std::endl;
    PrintArray(Arr, Arr_len);

    return 0;
}