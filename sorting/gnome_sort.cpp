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

void GnomeSort(int* Arr, int Arr_len)
{
    int index = 0;

    while(index < Arr_len)
    {
        if(index == 0)
            index++;
        if(Arr[index] >= Arr[index - 1])
            index++;
        else
        {
            swap(&Arr[index], &Arr[index - 1]);
            index--;
        }
    }
}

int main()
{
    int Arr[] = {3, 54, 23, 78, 1, 0, 43, 65, 76, 9};
    int Arr_len = sizeof(Arr) / sizeof(Arr[0]);

    std::cout << "Before sorting: " << std::endl;
    PrintArray(Arr, Arr_len);

    GnomeSort(Arr, Arr_len);    // Sort using Gnome Sort

    std::cout << "After sorting: " << std::endl;
    PrintArray(Arr, Arr_len);

    return 0;
}