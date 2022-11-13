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
        
        ListNode* prev = head;
        head = head->next;
        while(head != nullptr)
        {
            delete prev;
            prev = head;
            head = head->next;
        }
        delete prev;
        prev = head = nullptr;
    }

    void print()
    {
        if(head == nullptr)
            return;
        ListNode* p_head = head;
        while(p_head != nullptr)
        {
            std::cout << std::to_string(p_head->data) << " ";
            p_head = p_head->next;
        }
        std::cout << "\n";
    }

    void push_back(const int& val)
    {
        ListNode* temp = new ListNode();
        temp->data = val;
        temp->next = nullptr;

        if(head == nullptr)
        {
            head = temp;
            return;
        }
        ListNode* p_head = head;
        while(p_head->next != nullptr)
            p_head = p_head->next;
        p_head->next = temp;
    }

    void push_front(const int& val)
    {
        ListNode* temp = new ListNode();
        temp->data = val;
        temp->next = head;
        head = temp;
    }

    void pop_back()
    {
        if(head == nullptr)
            return;
        if(head->next == nullptr)
        {
            delete head;
            head = nullptr;
            return;
        }

        ListNode* p_head = head;
        while(p_head->next->next != nullptr)
            p_head = p_head->next;
        delete p_head->next;
        p_head->next = nullptr;
    }

    void pop_front()
    {
        if(head == nullptr)
            return;
        ListNode* temp = head->next;
        delete head;
        head = temp;
    }

    int find(const int& val)
    {
        if(head == nullptr)
            return -1;
        unsigned int index = 0;
        ListNode* p_head = head;
        while(p_head != nullptr)
        {
            index++;
            if(p_head->data == val)
                return index;
            p_head = p_head->next;
        }
        return -1;
    }

    int size()
    {
        if(head == nullptr)
            return 0;
        unsigned int s = 0;
        ListNode* p_head = head;
        for(; p_head != nullptr; s++, p_head = p_head->next);
        return s;
    }

    void insert(const int& val, const int& pos)
    {
        // pos = insert AFTER the POSth element
        // Error handling
        int s = size();
        if(pos < 0 || pos > s)
        {
            std::cout << "failed to insert..." << std::endl;
            return;
        }

        if(pos == 0)
        {
            push_front(val);
            return;
        }
        else if(pos == s)
        {
            push_back(val);
            return;
        }
        ListNode* p_head = head->next;
        ListNode* prev = head;
        for(int i = 1; i < pos; i++)
        {
            prev = p_head;
            p_head = p_head->next;
        }
        ListNode* temp = new ListNode();
        temp->data = val;
        temp->next = p_head;
        prev->next = temp;
    }

    int front()
    {
        return ((head == nullptr) ? \
            0 : head->data);
    }

    int back()
    {
        if(head == nullptr)
            return 0;
        ListNode* p_head = head;
        while(p_head->next != nullptr)
            p_head = p_head->next;
        return p_head->data;
    }

    bool empty()
    {
        return (head == nullptr);
    }

    void clear()
    {
        this->~LinkList();
    }

    void erase(const int& pos)
    {
        // Error handling
        int s = size();
        if(pos < 1 || pos > s)
        {
            std::cout << "Nothing to erase..." << std::endl;
            return;
        }

        if(pos == 1)
        {
            pop_front();
            return;
        }
        else if(pos == s)
        {
            pop_back();
            return;
        }
        ListNode* p_head = head->next;
        ListNode* prev = head;
        for(int i = 2; i < pos; i++)
        {
            prev = p_head;
            p_head = p_head->next;
        }
        prev->next = p_head->next;
        delete p_head;
    }

    void merge(LinkList& other)
    {
        // merge two sorted lists
        ListNode dummy;
        ListNode* tail = &dummy;
        // temp list head
        ListNode* p_other = other.head;
        while(head != nullptr && p_other != nullptr)
        {
            if(head->data > p_other->data)
            {
                tail->next = p_other;
                p_other = p_other->next;
            }
            else
            {
                tail->next = head;
                head = head->next;
            }
            tail = tail->next;
        }
        if(head != nullptr)
            tail->next = head;
        else if(p_other != nullptr)
            tail->next = p_other;
        head = dummy.next;
    }

    void reverse()
    {
        if(head == nullptr || head->next == nullptr)
            return;
        
        ListNode* p_head = head;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        while(p_head != nullptr)
        {
            next = p_head->next;
            // reverse connection
            p_head->next = prev;

            prev = p_head;
            p_head = next;
        }
        head = prev;
    }
};