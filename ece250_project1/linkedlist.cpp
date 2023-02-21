#include "linkedlist.h"

// create a new linked list to store variables
// -------------------------------------------
// Time complexity:
// - Constant time
LinkedList::LinkedList(std::size_t MAX) noexcept :
    m_phead(nullptr), m_size(0), MAX_VARS(MAX) {}

// deallocate the linked list
// --------------------------
// Time complexity:
// - Constant time (for n = 0)
// - O(n) time (for n >= 1)
LinkedList::~LinkedList() noexcept
{
    if(m_phead == nullptr)
        return;
    ListNode* pnext = m_phead->m_next;
    while(pnext != nullptr)
    {
        delete m_phead;
        m_phead = pnext;
        pnext = pnext->m_next;
    }
    delete m_phead;
    m_phead = nullptr;
    m_size = 0;
}

// helper function to find the middle element
// ------------------------------------------
// Time complexity:
// - Constant time (for n = 0)
// - O(n/2) time (for n >= 1)
ListNode* LinkedList::FindMiddle(ListNode* start, ListNode* end)
{
    // the method of finding the middle ele is fast-slow pointers
    // - fast move 2, slow move 1
    if(start == nullptr) // if the list is empty
        return nullptr;
    ListNode* slow = start;
    ListNode* fast = start->m_next;
    while(fast != end)
    {
        if(fast->m_next != end)
        {
            fast = fast->m_next->m_next;
            slow = slow->m_next;
        }
        else
        {
            fast = fast->m_next;
            break;
        }
    }
    return slow;
}

// Binary search over a linked list with O(logn)
// ---------------------------------------------
// Time complexity:
// - Constant time (for n = 0)
// - O(logn) time (for n >= 1)
ListNode* LinkedList::BinarySearch(const std::string& name) const noexcept
{
    // if the list is empty, no need to search
    if(m_phead == nullptr)
        return nullptr;
    // initialize start and end index
    ListNode* start = m_phead;
    ListNode* end = nullptr;
    // iteration approach to binary search
    while(end != start)
    {
        // find middle
        ListNode* mid = FindMiddle(start, end);
        // if found
        if(mid->m_name == name)
            return mid;
        // if mid is smaller than name
        else if(mid->m_name < name)
            start = mid->m_next;
        // if mid is greater than name
        else
            end = mid;
    }
    // not found
    return nullptr;
}

// Insert new variable name into linked list
// new approach --------------------------------------------------
// instead of do one binary search and do linear search and insert
// we do binary search while find proper location to insert
// ---------------------------------------------------------------
// Time complexity:
// - Constant time (for n = MAX_VARS || n = 0)
// - O(logn) + 2O(n) time (for n >= 1)
bool LinkedList::Insert(const std::string& name, double val)
{
    // if out of space, return false
    if(m_size == MAX_VARS)
        return false;
    // lambda function to create a listnode
    auto CreateNode = [](const std::string& name, double val) -> ListNode*
    {
        return new ListNode{val, name, nullptr};
    };
    // lambda function to push a node to the front
    auto PushFront = [this](ListNode* newnode) -> bool
    {
        newnode->m_next = this->m_phead;
        this->m_phead = newnode;
        ++this->m_size;
        return true;
    };
    // lambda function to insert a node AFTER the other
    auto InsertAfter = [this](ListNode* prevnode, ListNode* newnode) -> bool
    {
        ListNode* temp = prevnode->m_next;
        prevnode->m_next = newnode;
        newnode->m_next = temp;
        ++this->m_size;
        return true;
    };
    // if the list is empty, insert directly and return true
    if(m_phead == nullptr)
    {
        m_phead = CreateNode(name, val);
        ++m_size;
        return true;
    }
    // check if the variable is out of range, treat it seperately
    ListNode* plast = m_phead;
    for(; plast->m_next != nullptr; plast = plast->m_next);
    if(name < m_phead->m_name)
        return PushFront(CreateNode(name, val));
    else if(name > plast->m_name)
        return InsertAfter(plast, CreateNode(name, val));
    // perform modified binary search
    // initialize start and end index
    ListNode* start = m_phead;
    ListNode* end = nullptr;
    // iteration approach to binary search
    while(end != start)
    {
        // find middle
        ListNode* mid = LinkedList::FindMiddle(start, end);
        // if found, return false and do nothing
        if(mid->m_name == name)
            return false;
        // if mid is smaller than name, keep searching
        else if(mid->m_name < name)
            start = mid->m_next;
        // if mid is greater than name, keep searching
        else
            end = mid;
    }
    // if not found, insert the new node after the end/start index
    // make reuse of "end"
    for(end = m_phead; end->m_next != start; end = end->m_next);
    return InsertAfter(end, CreateNode(name, val));
}

// define addition operation
// -------------------------
// Time complexity:
// - Constant time (for all n)
double LinkedList::ADD(double x, double y)
{
    return x + y;
}

// define subtraction operation
// ----------------------------
// Time complexity:
// - Constant time (for all n)
double LinkedList::SUB(double x, double y)
{
    return x - y;
}

// BASE FUNCTION - Perform instructions
// ------------------------------------
// Time complexity:
// - O(n) time (for all n)
bool LinkedList::OP(const std::string& x, const std::string& y, const std::string& z, 
        double(*pfunc)(double, double))
{
    // 3 pointers to store the vars
    ListNode *px, *py, *pz;
    px = py = pz = nullptr;
    // perform linear search on linked list and find three vars at same time
    bool isFoundAll = false;
    for(ListNode* ptemp = m_phead; ptemp != nullptr; ptemp = ptemp->m_next)
    {
        if(ptemp->m_name == x)
            px = ptemp;
        if(ptemp->m_name == y)
            py = ptemp;
        if(ptemp->m_name == z)
            pz = ptemp;
        // if all three vars are found, stop traversing
        if(px != nullptr && py != nullptr && pz != nullptr)
        {
            isFoundAll = true;
            break;
        }
    }
    // if one of the vars are not found, exit with false
    if(!isFoundAll)
        return false;
    // when all vars are found, perform the calculation
    pz->m_val = pfunc(px->m_val, py->m_val);
    return true;
}

// ADD instruction: add x y, put the result to z
// ---------------------------------------------
// Time complexity:
// - O(n) time (for all n)
bool LinkedList::Add(const std::string& x, const std::string& y, const std::string& z)
{
    return OP(x, y, z, LinkedList::ADD);
}

// SUB instruction: subtract y from x, put the result to z
// -------------------------------------------------------
// Time complexity:
// - O(n) time (for all n)
bool LinkedList::Sub(const std::string& x, const std::string& y, const std::string& z)
{
    return OP(x, y, z, LinkedList::SUB);
}

// Print the value of the variable
// -------------------------------
// Time complexity:
// - Constant time (for n = 0)
// - O(logn) time (for n >= 1)
void LinkedList::PRT(const std::string& name) const
{
    ListNode* var = LinkedList::BinarySearch(name);
    if(var == nullptr)
        std::cout << "variable " << name << " not found\n";
    else
        std::cout << var->m_val << '\n';
}

// Remove the variable stored in linked list
// -----------------------------------------
// Time complexity:
// - Constant time (for n = 0)
// - O(logn) + O(n) time (for n >= 1 and worst case)
bool LinkedList::Remove(const std::string& name)
{
    ListNode* var = LinkedList::BinarySearch(name);
    if(var == nullptr)
        return false;
    // remove the variable from the list
    if(var == m_phead)
    {
        ListNode* ptemp = m_phead->m_next;
        delete m_phead;
        m_phead = ptemp;
        --m_size;
        return true;
    }
    ListNode* end = m_phead;
    for(; end->m_next != var; end = end->m_next);
    end->m_next = var->m_next;
    delete var;
    --m_size;
    return true;
}