#include <iostream>
#include <time.h>

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

bool isSorted(int* Arr, int Arr_len)
{
    for(int i = 1; i < Arr_len; i++)
    {
        if(Arr[i] < Arr[i - 1])
            return false;
    }
    return true;
}

void shuffle(int* Arr, int Arr_len)
{
    for(int i = 0; i < Arr_len; i++)
        swap(&Arr[i], &Arr[rand() % Arr_len]);
}

void BogoSort(int* Arr, int Arr_len)
{
    // If array is not sorted, then shuffle it again
    while(!isSorted(Arr, Arr_len))
        shuffle(Arr, Arr_len);
}

int main()
{
    // random seed
    srand((unsigned int)time(nullptr));

    // Sample size have to be very small
    int Arr[] = {3, 54};
    int Arr_len = sizeof(Arr) / sizeof(Arr[0]);

    std::cout << "Before sorting: " << std::endl;
    PrintArray(Arr, Arr_len);

    BogoSort(Arr, Arr_len);     // Sort using Bogo Sort

    std::cout << "After sorting: " << std::endl;
    PrintArray(Arr, Arr_len);

    return 0;
}