#include <iostream>

void PrintArray(int* Arr, int Arr_len)
{
    for(int i = 0; i < Arr_len; i++)
        std::cout << Arr[i] << " ";
    std::cout << std::endl;
}

void QuickSort(int* Arr, int Arr_len)
{
    // Base case
    if(Arr_len < 2)
        return;

    // Recursive case
    int pivot = Arr[0];
    int left = 0;
    int right = Arr_len - 1;
    int moving = 2; // 1 = moving left; 2 = moving right

    while(left < right)
    {
        if(moving == 2)
        {
            if(Arr[right] >= pivot)
            {
                right--;
                continue;
            }
            Arr[left] = Arr[right];
            left++;
            moving = 1;
            continue;
        }
        else
        {
            if(Arr[left] <= pivot)
            {
                left++;
                continue;
            }
            Arr[right] = Arr[left];
            right--;
            moving = 2;
            continue;
        }
    }
    Arr[left] = pivot;

    QuickSort(Arr, left);   // Sort the left side
    QuickSort(Arr + left + 1, Arr_len - left - 1);  // Sort the right side
}

int main()
{
    int Arr[] = {3, 54, 23, 78, 1, 0, 43, 65, 76, 9};
    int Arr_len = sizeof(Arr) / sizeof(Arr[0]);

    std::cout << "Before sorting: " << std::endl;
    PrintArray(Arr, Arr_len);

    QuickSort(Arr, Arr_len);    // Sort using Quick Sort

    std::cout << "After sorting: " << std::endl;
    PrintArray(Arr, Arr_len);

    return 0;
}