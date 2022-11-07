#include <iostream>

void PrintArray(int* Arr, int Arr_len)
{
    for(int i = 0; i < Arr_len; i++)
        std::cout << Arr[i] << " ";
    std::cout << std::endl;
}

void CountSort(int* Arr, int Arr_len, int exp)
{
    int* output = new int[Arr_len]; // output array
    int count[10] = {0};    // 10 different digits

    // count the occurance of each digits
    for(int i = 0; i < Arr_len; i++)
        count[(Arr[i] / exp) % 10]++;
    
    // Change count[i] so that count[i] represent the actual position of this digit in output[]
    for(int i = 1; i < 10; i++)
        count[i] += count[i - 1];
    
    // Build output array
    for(int i = Arr_len - 1; i >= 0; i--)
    {
        output[count[(Arr[i] / exp) % 10] - 1] = Arr[i];
        count[(Arr[i] / exp) % 10]--;
    }

    // Copy the output array to the original array
    for(int i = 0; i < Arr_len; i++)
        Arr[i] = output[i];

    // Deallocate
    delete[] output;
    output = nullptr;
}

void RadixSortVar1(int* Arr, int Arr_len)
{
    // Find the max element in Arr
    int max = Arr[0];
    for(int i = 1; i < Arr_len; i++)
    {
        if(Arr[i] > max)
            max = Arr[i];
    }

    // Do count sort for every digit
    for(int exp = 1; max / exp > 0; exp *= 10)
        CountSort(Arr, Arr_len, exp);
}

int main()
{
    int Arr[] = {3, 54, 23, 78, 1, 0, 43, 65, 76, 9};
    int Arr_len = sizeof(Arr) / sizeof(Arr[0]);

    std::cout << "Before sorting: " << std::endl;
    PrintArray(Arr, Arr_len);

    RadixSortVar1(Arr, Arr_len);    // Sort using Radix sort

    std::cout << "After sorting: " << std::endl;
    PrintArray(Arr, Arr_len);

    return 0;
}