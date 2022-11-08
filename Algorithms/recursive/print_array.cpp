#include <iostream>

void PrintArray(int* Arr, int Arr_len, int index)
{   
    // Base case
    if(index >= Arr_len)
        return;
    
    std::cout << Arr[index] << " ";
    PrintArray(Arr, Arr_len, index + 1);
}

int main()
{
    int Arr[] = {1, 2, 3, 4, 5};
    int Arr_len = sizeof(Arr) / sizeof(Arr[0]);
    PrintArray(Arr, Arr_len, 0);
    return 0;
}