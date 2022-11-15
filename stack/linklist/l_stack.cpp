#include <iostream>

// Node struct
struct ListNode
{
    int data;
    ListNode* next;
};

// Linklist stack struct
class Stack
{
private:
    ListNode* head;

public:
    Stack() : head(nullptr) {}
    ~Stack()
    {
        if(head == nullptr)
            return;
        ListNode* p_head = head->next;
        ListNode* prev = head;
        while(p_head != nullptr)
        {
            delete prev;
            prev = p_head;
            p_head = p_head->next;
        }
        delete prev;
        prev = head = nullptr;
    }

    bool push(const int& val)
    {
        // No need to do stack full check
        ListNode* temp = new ListNode();
        temp->data = val;
        temp->next = head;
        head = temp;
        std::cout << "pushed " << val << " onto stack" << "\n";
        return true;
    }

    int pop()
    {
        // Do stack underflow check
        if(empty())
        {
            std::cout << "stack underflow..." << std::endl;
            return -1;
        }
        ListNode* temp = head;
        head = head->next;
        int val = temp->data;
        delete temp;
        return val;
    }

    int get_top()
    {
        if(empty())
        {
            std::cout << "nothing in stack..." << std::endl;
            return -1;
        }
        return head->data;
    }

    bool empty()
    {
        return (head == nullptr);
    }

    int size()
    {
        int s = 0;
        for(ListNode* p_head = head; p_head != nullptr; \
            p_head = p_head->next, s++);
        return s;
    }
};