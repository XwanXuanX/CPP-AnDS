#include <iostream>
#include <cmath>    // for pow()
#include <vector>   // buckets for 10 digits

void PrintArray(int* Arr, int Arr_len)
{
    for(int i = 0; i < Arr_len; i++)
        std::cout << Arr[i] << " ";
    std::cout << std::endl;
}

void RadixSortVar2(int* Arr, int Arr_len)
{
    // getting the max element in Arr
    int max = Arr[0];
    for(int i = 1; i < Arr_len; i++)
    {
        if(Arr[i] > max)
            max = Arr[i];
    }

    // getting digits in the max element
    int d = 1;
    if(max >= 10)
    {
        while(max > pow(10, d))
            d++;
    }

    // Create 10 buckets for 10 digits
    std::vector<int> buckets[10];

    // Store array elements into buckets based on digit
    for(int i = 0; i < d; i++)
    {
        for(int j = 0; j < Arr_len; j++)
        {
            int index = (Arr[j] / (int)pow(10, i)) % 10;
            buckets[index].push_back(Arr[j]);
        }

        // write back to the array after each pass
        int k = 0;
        for(int j = 0; j < 10; j++)
        {
            for(int x = 0; x < buckets[j].size(); x++)
            {
                Arr[k] = buckets[j][x];
                k++;
            }

            // Empty buckets
            buckets[j].clear();
        }
    }
}

int main()
{
    int Arr[] = {3, 54, 23, 78, 1, 0, 43, 65, 76, 9};
    int Arr_len = sizeof(Arr) / sizeof(Arr[0]);

    std::cout << "Before sorting: " << std::endl;
    PrintArray(Arr, Arr_len);

    RadixSortVar2(Arr, Arr_len);    // Sort using Radix sort

    std::cout << "After sorting: " << std::endl;
    PrintArray(Arr, Arr_len);

    return 0;
}