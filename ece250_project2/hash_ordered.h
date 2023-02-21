#ifndef HASH_ORDERED_H
#define HASH_ORDERED_H

#include <vector>
#include "process.h"

class HashTable
{
public:
    // constructor
    //  - store N & P & M
    //  - allocate Memory
    //  - set NP = 0
    //  - allocate hashtable with M slots
    // ----------------------------------
    HashTable(std::uint32_t N, std::uint32_t P) noexcept;

    // destructor
    //  - iterate through hashtable, call dtor for vectors
    //  - deallocate hashtable
    //  - deallocate memory
    // ---------------------------------------------------
    ~HashTable() noexcept;

    // insert a process and assign a new page of memory
    // ------------------------------------------------
    bool Insert(unsigned int PID);

    // print the chain of keys in position m in decending order
    // --------------------------------------------------------
    void Print(std::size_t m) const noexcept;

    // search the PID in hashtable
    // ---------------------------
    void Search(unsigned int PID) const noexcept;

    // write the integer x to memory address
    // -------------------------------------
    bool Write(unsigned int PID, unsigned int ADDR, int x) const;

    // read the integer stored in the memory
    // -------------------------------------
    bool Read(unsigned int PID, unsigned int ADDR) const;

    // Delete the key PID from the hash table
    // --------------------------------------
    bool Delete(unsigned int PID);
    
private:
    // alias to std::vector<Process>
    // -----------------------------
    typedef std::vector<Process> HASH;

    // Sub functions: recursively push all usable pages onto vector
    // ------------------------------------------------------------
    void _RECUR_PUSH_PAGES(std::uint32_t mem = 0);

    // Sub function: recursively iterate through vector to find PID
    // ------------------------------------------------------------
    int _RECUR_INSERT_PROC(unsigned int PID, const HASH& list, std::size_t idx);

    // Sub function: recursively traverse through each element
    // -------------------------------------------------------
    void _RECUR_FIND_PRINT(HASH::iterator start, decltype(start) end) const;

    // Sub function: binary search
    // ---------------------------
    int _BINARY_SEARCH(const HASH& list, unsigned int PID, int start, int end) const;

    // primary hash function (h1)
    // --------------------------
    std::uint32_t h1(unsigned int k) const;

private:
    int* m_Mem;           // the address of the entire memory block

    std::uint32_t m_P;    // size per page
    std::uint32_t m_N;    // size of total memory
    std::uint32_t m_M;    // max number of processes can be added
    std::uint32_t m_NP;   // number of current processes

    HASH* hashtable;     // the pointer to the hashtable

    std::vector<unsigned int> m_usableMem;  // the array to track the usable page
};

#endif