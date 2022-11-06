#include <iostream>

void PrintArray(int* Arr, int Arr_len)
{
    for(int i = 0; i < Arr_len; i++)
        std::cout << Arr[i] << " ";
    std::cout << std::endl;
}

void CountSortVar2(int* Arr, int Arr_len)
{
    if(Arr_len < 2)
        return;

    // Get the min and max element in the array
    int min = Arr[0];
    int max = Arr[0];
    for(int i = 0; i < Arr_len; i++)
    {
        if(Arr[i] > max)
            max = Arr[i];
        if(Arr[i] < min)
            min = Arr[i];
    }

    // Creat count array
    int* count = new int[max - min + 1];
    for(int i = 0; i < max - min + 1; i++)
        count[i] = 0;

    // Count the occurance of each element in Arr
    for(int i = 0; i < Arr_len; i++)
    {
        int index = Arr[i] - min;
        count[index]++;
    }

    // Put the counted number into original array
    int k = 0;
    for(int i = 0; i < max - min + 1; i++)
    {
        for(int j = 0; j < count[i]; j++)
        {
            Arr[k] = i + min;
            k++;
        }
    }
}

int main()
{
    int Arr[] = {30, 90, 30, 70, 10, 10, 40, 10, 70, 90};
    int Arr_len = sizeof(Arr) / sizeof(Arr[0]);

    std::cout << "Before sorting: " << std::endl;
    PrintArray(Arr, Arr_len);

    CountSortVar2(Arr, Arr_len);    // Sort using count sort

    std::cout << "After sorting: " << std::endl;
    PrintArray(Arr, Arr_len);

    return 0;
}