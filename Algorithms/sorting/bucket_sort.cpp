#include <iostream>
#include <algorithm>    // Sort individual bucket
#include <vector>       // bucket containner

void PrintArray(int* Arr, int Arr_len)
{
    for(int i = 0; i < Arr_len; i++)
        std::cout << Arr[i] << " ";
    std::cout << std::endl;
}

void BucketSort(int* Arr, int Arr_len, int NumOfBuckets)
{
    // Max and min element in array
    int max = Arr[0];
    int min = Arr[0];
    for(int i = 0; i < Arr_len; i++)
    {
        if(Arr[i] > max)
            max = Arr[i];
        if(Arr[i] < min)
            min = Arr[i];
    }

    // Range of the array
    float range = (float)((max - min) / NumOfBuckets);

    // Create buckets: dynamically allocation
    std::vector<int>* buckets = new std::vector<int>[NumOfBuckets];

    // Scatter array elements in buckets
    for(int i = 0; i < Arr_len; i++)
    {
        int index = (int)((Arr[i] - min) / range);
        buckets[index].push_back(Arr[i]);
    }

    // Sort each bucket
    for(int i = 0; i < NumOfBuckets; i++)
    {
        std::sort(buckets[i].begin(), buckets[i].end());
    }

    // Concatenate all buckets into Arr
    int k = 0;
    for(int i = 0; i < NumOfBuckets; i++)
    {
        for(int j = 0; j < buckets[i].size(); j++)
        {
            Arr[k] = buckets[i][j];
            k++;
        }
    }

    delete[] buckets;
    buckets = nullptr;
}

int main()
{
    int Arr[] = {3, 54, 23, 78, 1, 0, 43, 65, 76, 9};
    int Arr_len = sizeof(Arr) / sizeof(Arr[0]);

    std::cout << "Before sorting: " << std::endl;
    PrintArray(Arr, Arr_len);

    BucketSort(Arr, Arr_len, 5);    // Sort using bucket sort

    std::cout << "After sorting: " << std::endl;
    PrintArray(Arr, Arr_len);

    return 0;
}