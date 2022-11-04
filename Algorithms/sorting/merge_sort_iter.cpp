#include <iostream>

void PrintArray(int* Arr, int Arr_len)
{
    for(int i = 0; i < Arr_len; i++)
        std::cout << Arr[i] << " ";
    std::cout << std::endl;
}

void merge(int* Arr, int left, int mid, int right)
{
    // sizes of two subarrays
    int subArr1_size = mid - left + 1;
    int subArr2_size = right - mid;

    // dynamically create temp arrays
    int* leftArray = new int[subArr1_size];
    int* rightArray = new int[subArr2_size];

    // copy elements of both arrays into temp arrays
    for(int i = 0; i < subArr1_size; i++)
        leftArray[i] = Arr[left + i];
    for(int i = 0; i < subArr2_size; i++)
        rightArray[i] = Arr[mid + 1 + i];

    // initialize index counters
    int i_left = 0, i_right = 0;
    int i_merged = left;

    // start merging
    while(i_left < subArr1_size && i_right < subArr2_size)
    {
        if(leftArray[i_left] <= rightArray[i_right])
        {
            Arr[i_merged] = leftArray[i_left];
            i_left ++;
        }
        else
        {
            Arr[i_merged] = rightArray[i_right];
            i_right ++;
        }
        i_merged++;
    }

    // Append any remaining elements from leftArr or rightArr
    while(i_left < subArr1_size)
    {
        Arr[i_merged] = leftArray[i_left];
        i_merged ++;
        i_left ++;
    }
    while(i_right < subArr2_size)
    {
        Arr[i_merged] = rightArray[i_right];
        i_merged ++;
        i_right ++;
    }
    
    // Deallocate arrays
    delete[] leftArray;
    delete[] rightArray;
    leftArray = nullptr;
    rightArray = nullptr;
}

int min(int x, int y)
{
    return (x < y) ? x : y;
}

void MergeSortIter(int* Arr, int Arr_len)
{
    for(int cur_size = 1; cur_size < Arr_len; cur_size = 2*cur_size)
    {
        for(int left_start = 0; left_start < Arr_len - 1; left_start += 2*cur_size)
        {
            int mid = min(left_start + cur_size - 1, Arr_len - 1);
            int right_end = min(left_start + 2*cur_size - 1, Arr_len - 1);
            merge(Arr, left_start, mid, right_end);
        }
    }
}

int main()
{
    int Arr[] = {3, 54, 23, 78, 1, 0, 43, 65, 76, 9};
    int Arr_len = sizeof(Arr) / sizeof(Arr[0]);

    std::cout << "Before sorting: " << std::endl;
    PrintArray(Arr, Arr_len);

    MergeSortIter(Arr, Arr_len);     // Sort using Merge Sort Iter

    std::cout << "After sorting: " << std::endl;
    PrintArray(Arr, Arr_len);

    return 0;
}