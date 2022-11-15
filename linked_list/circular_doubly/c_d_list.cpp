#include <iostream>

// Node struct
struct ListNode
{
    int data;
    ListNode* prev;
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

    void print_forward()
    {
        if(head == nullptr)
        {
            std::cout << "nothing to print..." << std::endl;
            return;
        }
        ListNode* p_head = head;
        while(p_head->next != head)
        {
            std::cout << p_head->data << " ";
            p_head = p_head->next;
        }
        std::cout << p_head->data << "\n";
    }

    void print_backward()
    {
        if(head == nullptr)
        {
            std::cout << "nothing to print..." << std::endl;
            return;
        }
        ListNode* p_tail = head;
        while(p_tail->next != head)
            p_tail = p_tail->next;
        while(p_tail != head)
        {
            std::cout << p_tail->data << " ";
            p_tail = p_tail->prev;
        }
        std::cout << p_tail->data << "\n";
    }

    void push_back(const int& val)
    {
        ListNode* temp = new ListNode();
        temp->data = val;
        if(head == nullptr)
        {
            head = temp;
            temp->next = head;
            temp->prev = head;
            return;
        }
        ListNode* p_head = head;
        while(p_head->next != head)
            p_head = p_head->next;
        temp->next = head;
        temp->prev = p_head;
        p_head->next = temp;
    }

    void push_front(const int& val)
    {
        ListNode* temp = new ListNode();
        temp->data = val;
        if(head == nullptr)
        {
            this->push_back(val);
            return;
        }
        ListNode* p_tail = head;
        while(p_tail->next != head)
            p_tail = p_tail->next;
        head->prev = temp;
        temp->next = head;
        temp->prev = p_tail;
        p_tail->next = temp;
        head = temp;
    }

    void pop_back()
    {
        if(head == nullptr)
            return;
        if(head->next == head)
        {
            delete head;
            head = nullptr;
            return;
        }
        ListNode* p_head = head;
        while(p_head->next->next != head)
            p_head = p_head->next;
        delete p_head->next;
        p_head->next = head;
        head->prev = p_head;   
    }

    void pop_front()
    {
        if(head == nullptr)
            return;
        if(head->next == head)
        {
            this->pop_back();
            return;
        }
        ListNode* p_tail = head;
        while(p_tail->next != head)
            p_tail = p_tail->next;
        ListNode* p_head = head->next;
        delete head;
        p_head->prev = p_tail;
        p_tail->next = p_head;
        head = p_head;
    }

    // find()

    // size()

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
        ListNode* p_other = other.head;
        ListNode* p_head = head;
        while(p_head->next != head && p_other->next != other.head)
        {
            if(p_head->data > p_other->data)
            {
                tail->next = p_other;
                p_other->prev = tail;
                p_other = p_other->next;
            }
            else
            {
                tail->next = p_head;
                p_head->prev = tail;
                p_head = p_head->next;
            }
            tail = tail->next;
        }
        while(p_head != head && p_other != other.head)
        {
            if(p_head->data > p_other->data)
            {
                tail->next = p_other;
                p_other->prev = tail;
                p_other = p_other->next;
            }
            else
            {
                tail->next = p_head;
                p_head->prev = tail;
                p_head = p_head->next;
            }
            tail = tail->next;
        }
        if(p_head != head)
        {
            tail->next = p_head;
            p_head->prev = tail;
            while(tail->next != head)
                tail = tail->next;
        }
        else if(p_other != other.head)
        {
            tail->next = p_other;
            p_other->prev = tail;
            while(tail->next != other.head)
                tail = tail->next;
        }
        tail->next = dummy.next;
        dummy.next->prev = tail;
        head = dummy.next;
    }

    // reverse()
};