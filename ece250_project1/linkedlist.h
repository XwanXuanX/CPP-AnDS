// ------------------
// Single linked list
// ------------------

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

// for std input and output
#include <iostream>

// Node class for single linked list
class ListNode
{
public:
    // data properties
    double m_val;
    std::string m_name;
    // list node property
    ListNode* m_next;
};

// Single linked list class
class LinkedList
{
public:
    // create a new linked list to store variables
    // -------------------------------------------
    LinkedList(std::size_t MAX) noexcept;

    // deallocate the linked list
    // --------------------------
    ~LinkedList() noexcept;

private:
    // helper function to find the middle element
    // ------------------------------------------
    static ListNode* FindMiddle(ListNode* start, ListNode* end);

    // Binary search over a linked list with O(logn)
    // ---------------------------------------------
    ListNode* BinarySearch(const std::string& name) const noexcept;

    // define addition operation
    // -------------------------
    static double ADD(double x, double y);

    // define subtraction operation
    // ----------------------------
    static double SUB(double x, double y);

    // BASE FUNCTION - Perform instructions
    // ------------------------------------
    bool OP(const std::string& x, const std::string& y, const std::string& z, 
            double(*pfunc)(double, double));

public:
    // Insert new variable name into linked list
    // -----------------------------------------
    bool Insert(const std::string& name, double val);

    // ADD instruction: add x y, put the result to z
    // ---------------------------------------------
    bool Add(const std::string& x, const std::string& y, const std::string& z);

    // SUB instruction: subtract y from x, put the result to z
    // -------------------------------------------------------
    bool Sub(const std::string& x, const std::string& y, const std::string& z);

    // Print the value of the variable
    // -------------------------------
    void PRT(const std::string& name) const;

    // Remove the variable stored in linked list
    // -----------------------------------------
    bool Remove(const std::string& name);
    
private:
    ListNode* m_phead;      // the head of the linked list
    std::size_t m_size;     // the current size of linked list
    std::size_t MAX_VARS;   // the max number of vars can be stored
};

#endif