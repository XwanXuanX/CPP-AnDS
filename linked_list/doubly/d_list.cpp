#include <iostream>
#include <cmath>

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

    void print_forward()
    {
        if(head == nullptr)
        {
            std::cout << "nothing to print..." << std::endl;
            return;
        }
        ListNode* p_head = head;
        while(p_head != nullptr)
        {
            std::cout << std::to_string(p_head->data) << " ";
            p_head = p_head->next;
        }
        std::cout << "\n";
    }

    void print_backward()
    {
        if(head == nullptr)
        {
            std::cout << "nothing to print..." << std::endl;
            return;
        }
        ListNode* p_head = head;
        // move to the last element
        while(p_head->next != nullptr)
            p_head = p_head->next;
        while(p_head != nullptr)
        {
            std::cout << std::to_string(p_head->data) << " ";
            p_head = p_head->prev;
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
            temp->prev = nullptr;
            head = temp;
            return;
        }
        ListNode* p_head = head;
        while(p_head->next != nullptr)
            p_head = p_head->next;
        temp->prev = p_head;
        p_head->next = temp;
    }

    void push_front(const int& val)
    {
        ListNode* temp = new ListNode();
        temp->data = val;
        temp->prev = nullptr;
        // link up head and temp
        head->prev = temp;
        temp->next = head;
        // make temp to be the head
        head = temp;
    }

    void pop_back()
    {
        if(head == nullptr)
            return;
        else if(head->next == nullptr)
        {
            delete head;
            head = nullptr;
            return;
        }
        ListNode* p_head = head;
        while(p_head->next->next != nullptr)
            p_head = p_head->next;
        delete (p_head->next);
        p_head->next = nullptr;    
    }

    void pop_front()
    {
        if(head == nullptr)
            return;
        else if(head->next == nullptr)
        {
            delete head;
            head = nullptr;
            return;
        }
        ListNode* temp = head->next;
        temp->prev = nullptr;
        delete head;
        head = temp;
    }

    int find_linear(const int& val)
    {
        if(head == nullptr)
            return -1;
        unsigned int index = 1;
        ListNode* p_head = head;
        while(p_head != nullptr)
        {
            if(p_head->data == val)
                return index;
            p_head = p_head->next;
            index++;
        }
        return -1;
    }

    int find_jump(const int& val)
    {
        if(head == nullptr)
            return -1;
        int s = size();
        s = static_cast<int>(sqrt(s));
        int index = 1;
        ListNode* p_head = head;
        while(p_head->next != nullptr)
        {
            if(p_head->data >= val)
                break;

            for(int i = 0; i < s; i++)
            {
                p_head = p_head->next;
                index++;
                if(p_head->next == nullptr)
                    break;
            }
        }
        while(p_head != nullptr)
        {
            if(p_head->data == val)
                return index;   
            if(p_head->data < val)
                return -1;
            p_head = p_head->prev;
            index--;
        }
        return -1;
    }

    int size()
    {
        if(head == nullptr)
            return 0;
        u_int s = 0;
        for(ListNode* p_head = head; p_head != nullptr; \
            p_head = p_head->next, s++);
        return s;
    }

    void insert(const int& val, const int& pos)
    {
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
        p_head->prev = temp;
        temp->prev = prev;
        prev->next = temp;
    }

    int front()
    {
        return (head == nullptr) ? \
            0 : (head->data);
    }

    int back()
    {
        if(head == nullptr)
            return 0;
        ListNode* p_head = head;
        for(; p_head->next != nullptr; \
            p_head = p_head->next);
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
            std::cout << "failed to erase..." << std::endl;
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
        // p_head store the address of deleting node
        prev->next = p_head->next;
        p_head->next->prev = prev;
        delete p_head;
    }

    void reverse()
    {
        if(head == nullptr || head->next == nullptr)
        {
            std::cout << "nothing to reverse..." << "\n";
            return;
        }
        while(head->next != nullptr)
        {
            ListNode* temp = head->next;
            head->next = head->prev;
            head->prev = temp;
            head = temp;
        }
        ListNode* temp = head->next;
        head->next = head->prev;
        head->prev = temp;
    }
};