#include <iostream>

// Node struct
struct ListNode
{
    int data;
    ListNode* next;
};

// List struct
class LinkList
{
private:
    ListNode* head;

public:
    LinkList() : head(nullptr) {}
    ~LinkList()
    {
        if(head == nullptr)
            return;
        ListNode* p_head = head->next;
        ListNode* prev = head;
        while(p_head != head)
        {
            delete prev;
            prev = p_head;
            p_head = p_head->next;
        }
        delete prev;
        prev = head = nullptr;
    }

    void print()
    {
        if(head == nullptr)
        {
            std::cout << "nothing to print..." << "\n";
            return;
        }
        ListNode* p_head = head->next;
        ListNode* prev = head;
        while(p_head != head)
        {
            std::cout << std::to_string(prev->data) << " ";
            prev = p_head;
            p_head = p_head->next;
        }
        std::cout << std::to_string(prev->data) << "\n";
    }

    void push_back(const int& val)
    {
        ListNode* temp = new ListNode();
        temp->data = val;
        if(head == nullptr)
        {
            head = temp;
            temp->next = head;
            return;
        }
        ListNode* p_head = head->next;
        ListNode* prev = head;
        while(p_head != head)
        {
            prev = p_head;
            p_head = p_head->next;
        }
        prev->next = temp;
        temp->next = head;
    }

    void push_front(const int& val)
    {
        ListNode* temp = new ListNode();
        temp->data = val;
        if(head == nullptr)
        {
            head = temp;
            temp->next = head;
            return;
        }
        ListNode* p_head = head->next;
        ListNode* prev = head;
        while(p_head != head)
        {
            prev = p_head;
            p_head = p_head->next;
        }
        prev->next = temp;
        temp->next = head;
        head = temp;
    }

    void pop_back()
    {
        if(head == nullptr)
            return;
        // if only one node
        if(head->next == head)
        {
            delete head;
            head = nullptr;
            return;
        }
        ListNode* p_head = head->next;
        ListNode* prev = head;
        while(p_head->next != head)
        {
            prev = p_head;
            p_head = p_head->next;
        }
        delete p_head;
        prev->next = head;
    }

    void pop_front()
    {
        if(head == nullptr)
            return;
        // if only one node = pop_back()
        if(head->next == head)
        {
            this->pop_back();
            return;
        }
        ListNode* p_head = head;
        while(p_head->next != head)
            p_head = p_head->next;
        ListNode* temp = head->next;
        delete head;
        p_head->next = temp;
        head = temp;
    }

    int find(const int& val)
    {
        if(head == nullptr)
            return -1;
        unsigned int index = 0;
        ListNode* p_head = head;
        while(p_head->next != head)
        {
            index++;
            if(p_head->data == val)
                return index;
            p_head = p_head->next;
        }
        index++;
        if(p_head->data == val)
            return index;
        return -1;
    }

    int size()
    {
        if(head == nullptr)
            return 0;
        int s = 0;
        for(ListNode* p_head = head; p_head->next != head; \
            p_head = p_head->next, s++);
        s++;
        return s;
    }

    // insert()

    // front()

    // back()

    // empty()

    // clear()

    // erase()

    void merge(LinkList& other)
    {
        ListNode dummy;
        ListNode* tail = &dummy;
        ListNode* p_head = head;
        ListNode* p_other = other.head;
        while(p_head->next != head && p_other->next != other.head)
        {
            if(p_head->data > p_other->data)
            {
                tail->next = p_other;
                p_other = p_other->next;
            }
            else
            {
                tail->next = p_head;
                p_head = p_head->next;
            }
            tail = tail->next;
        }
        while(p_head != head && p_other != other.head)
        {
            // last check for last element        
            if(p_head->data > p_other->data)
            {
                tail->next = p_other;
                p_other = p_other->next;
            }
            else
            {
                tail->next = p_head;
                p_head = p_head->next;
            }
            tail = tail->next;
        }
        // check if list is empty
        // move to the last element
        // (!!! BEWARE of short-hand evaluation)
        if(p_head != head)
        {
            tail->next = p_head;
            while(tail->next != head)
                tail = tail->next;
        }
        else if(p_other != other.head)
        {
            tail->next = p_other;
            while(tail->next != other.head)
                tail = tail->next;    
        }
        tail->next = dummy.next;
        head = dummy.next;
    }

    void reverse()
    {
        if(head == nullptr || head->next == head)
            return;
        ListNode* p_head = head;
        ListNode* next = nullptr;
        ListNode* prev = head;
        // prev stores the address of last element
        while(prev->next != head)
            prev = prev->next;
        while(p_head->next != head)
        {
            next = p_head->next;
            p_head->next = prev;
            prev = p_head;
            p_head = next;
        }
        // swap the last connection
        p_head->next = prev;
        head = p_head;
    }
};