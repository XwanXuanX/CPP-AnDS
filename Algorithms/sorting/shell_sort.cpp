#include <iostream>

void PrintArray(int* Arr, int Arr_len)
{
    for(int i = 0; i < Arr_len; i++)
        std::cout << Arr[i] << " ";
    std::cout << std::endl;
}

void ShellSort(int* Arr, int Arr_len)
{
    // Start with a big gap, then shrink gap size
    for(int gap = Arr_len / 2; gap > 0; gap /= 2)
    {
        // Do gapped insertion sort
        // The first gapped element is already sorted, so skip it
        for(int i = gap; i < Arr_len; i++)
        {
            int key = Arr[i];
            int j = i - gap;
            while(j >= 0 && Arr[j] > key)
            {
                Arr[j + gap] = Arr[j];
                j -= gap;
            }
            Arr[j + gap] = key;
        }
    }
}

int main()
{
    int Arr[] = {3, 54, 23, 78, 1, 0, 43, 65, 76, 9};
    int Arr_len = sizeof(Arr) / sizeof(Arr[0]);

    std::cout << "Before sorting: " << std::endl;
    PrintArray(Arr, Arr_len);

    ShellSort(Arr, Arr_len);    // Sort using shell sort

    std::cout << "After sorting: " << std::endl;
    PrintArray(Arr, Arr_len);

    return 0;
}