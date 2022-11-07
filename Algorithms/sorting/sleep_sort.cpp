#include <iostream>
#include <Windows.h>
#include <process.h>

// In these threads, we sleep for a particular amount of time;
// when it wakes up, the number is printed
void routine(void* a)
{
    int n = *(int*) a;

    // Sleeping time is proportional to the number
    Sleep(n);

    // Print out the number when wake up
    std::cout << n << " ";
}

void SleepSort(int* Arr, int Arr_len)
{
    // Create len number of thread;
    // one thread for each number in Arr
    HANDLE* threads = new HANDLE[Arr_len];

    // Create a thread for each of the input array element
    for(int i = 0; i < Arr_len; i++)
        threads[i] = (HANDLE)_beginthread(&routine, 0, &Arr[i]);
    
    // Process these threads
    WaitForMultipleObjects(Arr_len, threads, true, INFINITE);
}

int main()
{
    int Arr[] = {20, 40, 50, 30, 70, 10, 60};
    int Arr_len = sizeof(Arr) / sizeof(Arr[0]);

    SleepSort(Arr, Arr_len);

    return 0;
}