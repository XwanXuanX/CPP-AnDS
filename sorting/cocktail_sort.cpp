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

void CocktailSort(int* Arr, int Arr_len)
{
    bool swapped = true;
    int start = 0;
    int end = Arr_len - 1;

    while(swapped)
    {
        swapped = false;
        
        // Do a normal forward bubble sort
        for(int i = start; i < end; i++)
        {
            if(Arr[i] > Arr[i + 1])
            {
                swap(&Arr[i], &Arr[i + 1]);
                swapped = true;
            }
        }

        if(!swapped)
            break;
        
        // Reset swap flag
        swapped = false;

        // Dec end index, since the last one is already sorted
        end--;

        // Do a backward bubble sort
        for(int i = end - 1; i >= start; i--)
        {
            if(Arr[i] > Arr[i + 1])
            {
                swap(&Arr[i], &Arr[i + 1]);
                swapped = true;
            }
        }

        // Inc start index, since the first one is already sorted
        start++;
    }
}

int main()
{
    int Arr[] = {3, 54, 23, 78, 1, 0, 43, 65, 76, 9};
    int Arr_len = sizeof(Arr) / sizeof(Arr[0]);

    std::cout << "Before sorting: " << std::endl;
    PrintArray(Arr, Arr_len);

    CocktailSort(Arr, Arr_len);     // Sort using Cocktail Sort

    std::cout << "After sorting: " << std::endl;
    PrintArray(Arr, Arr_len);

    return 0;
}