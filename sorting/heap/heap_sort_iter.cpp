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

void HeapifyIter(int* Arr, int i_start, int i_end)
{
    // initial index of parent and son nodes
    int i_parent = i_start;         // Parent node
    int i_son = i_parent * 2 + 1;   // left son node

    // if left son node does not exceed limit
    while(i_son <= i_end)
    {
        // compare vals of two son nodes
        if((i_son + 1 <= i_end) && (Arr[i_son] < Arr[i_son + 1]))
            i_son++;

        // If parent node is bigger than both son nodes, then exit
        if(Arr[i_parent] > Arr[i_son])
            return;

        // Else swap parent node and the bigger son node, continue
        swap(&Arr[i_parent], &Arr[i_son]);
        i_parent = i_son;
        i_son = i_parent * 2 + 1;
    }
}

void HeapSort(int* Arr, int Arr_len)
{
    // Build max-heap
    // Start from the last parent node: heapify
    for(int i = (Arr_len - 1) / 2; i >= 0; i--)
    {
        HeapifyIter(Arr, i, Arr_len - 1);
    }

    // Swap the first element with the last element, then heapify
    for(int i = Arr_len - 1; i > 0; i--)
    {
        swap(&Arr[0], &Arr[i]);
        HeapifyIter(Arr, 0, i - 1);
    }
}

int main()
{
    int Arr[] = {3, 54, 23, 78, 1, 0, 43, 65, 76, 9};
    int Arr_len = sizeof(Arr) / sizeof(Arr[0]);

    std::cout << "Before sorting: " << std::endl;
    PrintArray(Arr, Arr_len);

    HeapSort(Arr, Arr_len);     // Sort using heap sort

    std::cout << "After sorting: " << std::endl;
    PrintArray(Arr, Arr_len);

    return 0;
}