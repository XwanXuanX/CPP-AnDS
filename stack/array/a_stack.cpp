#include <iostream>

#define MAX 1000

// Array stack struct
class Stack
{
private:
    int top;    // the index of stack top
    int stack[MAX]; // array stack

public:
    Stack() : top(-1) {}

    bool push(const int& val)
    {
        if(top >= (MAX - 1))
        {
            std::cout << "stack overflow..." << std::endl;
            return false;
        }
        top++;
        stack[top] = val;
        std::cout << "pushed " << val << " onto stack!" << "\n";
        return true;
    }

    int pop()
    {
        if(top < 0)
        {
            std::cout << "stack underflow..." << std::endl;
            return 0;
        }
        int val = stack[top];
        top--;
        return val;
    }

    int get_top()
    {
        if(top < 0)
        {
            std::cout << "nothing in stack..." << std::endl;
            return -1;
        }
        return stack[top];
    }

    bool empty()
    {
        return (top < 0);
    }

    int size()
    {
        return (top < 0) ? 0 : (top + 1);
    }  
};