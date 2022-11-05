#include <iostream>
#include <stack>    // Quick sort iter is based on stack

void PrintArray(int* Arr, int Arr_len)
{
    for(int i = 0; i < Arr_len; i++)
        std::cout << Arr[i] << " ";
    std::cout << std::endl;
}

void swap(int* num1, int* num2)
{
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

int partition(int* Arr, int i_start, int i_end)
{
    int pivot = Arr[i_end];
    int j = i_start - 1;

    for(int i = i_start; i < i_end; i++)
    {
        if(Arr[i] <= pivot)
        {
            j++;
            swap(&Arr[i], &Arr[j]);
        }
    }
    swap(&Arr[j + 1], &Arr[i_end]);
    return (j + 1);
}

void QuickSortIter(int* Arr, int i_start, int i_end)
{
    std::stack<int> S;
    S.push(i_start);
    S.push(i_end);

    while(!S.empty())
    {
        i_end = S.top();
        S.pop();
        i_start = S.top();
        S.pop();

        int p = partition(Arr, i_start, i_end);

        // If there are elements on the left side
        if(p - 1 > i_start)
        {
            S.push(i_start);    // left bound
            S.push(p - 1);      // right bound
        }
        // If there are elements on the right side
        if(p + 1 < i_end)
        {
            S.push(p + 1);      // left bound
            S.push(i_end);      // right bound
        }
    }
}

int main()
{
    int Arr[] = {3, 54, 23, 78, 1, 0, 43, 65, 76, 9};
    int Arr_len = sizeof(Arr) / sizeof(Arr[0]);

    std::cout << "Before sorting: " << std::endl;
    PrintArray(Arr, Arr_len);

    QuickSortIter(Arr, 0, Arr_len - 1);    // Sort using Quick Sort Iter

    std::cout << "After sorting: " << std::endl;
    PrintArray(Arr, Arr_len);

    return 0;
}