#include <iostream>

void PrintArray(int* Arr, int Arr_len)
{
    for(int i = 0; i < Arr_len; i++)
        std::cout << Arr[i] << " ";
    std::cout << std::endl;
}

void swap(int* n1, int* n2)
{
    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

void CombSort(int* Arr, int Arr_len)
{
    // Initialize gap
    int gap = Arr_len;

    // Swapped flag
    bool swapped = true;

    // Keep running while gap is more than 1
    while(gap != 1 || swapped)
    {
        // Find next gap
        gap = (gap * 10) / 13;  // gap decreases by a factor of 1.3
        if(gap < 1)
            gap = 1;

        swapped = false;

        // Do a gapped bubble sort
        for(int i = 0; i < Arr_len - gap; i++)
        {
            if(Arr[i] > Arr[i + gap])
            {
                swap(&Arr[i], &Arr[i + gap]);
                swapped = true;
            }
        }
    }
}

int main()
{
    int Arr[] = {3, 54, 23, 78, 1, 0, 43, 65, 76, 9};
    int Arr_len = sizeof(Arr) / sizeof(Arr[0]);

    std::cout << "Before sorting: " << std::endl;
    PrintArray(Arr, Arr_len);

    CombSort(Arr, Arr_len);     // Sort using Comb Sort

    std::cout << "After sorting: " << std::endl;
    PrintArray(Arr, Arr_len);

    return 0;
}