#include <iostream>
#include <vector>

void PrintArray(int* Arr, int Arr_len)
{
    for(int i = 0; i < Arr_len; i++)
        std::cout << Arr[i] << " ";
    std::cout << std::endl;
}

void PigeonholeSort(int* Arr, int Arr_len)
{
    // Find max and min
    int max = Arr[0], min = Arr[0];
    for(int i = 1; i < Arr_len; i++)
    {
        if(Arr[i] > max)    max = Arr[i];
        if(Arr[i] < min)    min = Arr[i];
    }

    // Calculate range
    int range = max - min + 1;

    // Create pigeonholes
    std::vector<int>* holes = new std::vector<int>[range];

    // Put element in holes
    for(int i = 0; i < Arr_len; i++)
        holes[Arr[i] - min].push_back(Arr[i]);

    // Put elements back to original array
    int k = 0;
    for(int i = 0; i < range; i++)
    {
        auto iter = holes[i].begin();
        for(; iter != holes[i].end(); iter++)
        {
            Arr[k] = *iter;
            k++;
        }
    }
    
    delete[] holes;
    holes = nullptr;
}

int main()
{
    int Arr[] = {3, 54, 23, 78, 1, 0, 43, 65, 76, 9};
    int Arr_len = sizeof(Arr) / sizeof(Arr[0]);

    std::cout << "Before sorting: " << std::endl;
    PrintArray(Arr, Arr_len);

    PigeonholeSort(Arr, Arr_len);   // Sort using Pigeonhole Sort

    std::cout << "After sorting: " << std::endl;
    PrintArray(Arr, Arr_len);

    return 0;
}