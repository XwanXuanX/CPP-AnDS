#ifndef HASH_OPEN_H
#define HASH_OPEN_H

#include <vector>
#include "process.h"

class OpenTable
{
public:
    // constructor
    //  - store N & P & M
    //  - allocate Memory
    //  - set NP = 0
    //  - allocate hashtable with M nodes
    // ----------------------------------
    OpenTable(std::uint32_t N, std::uint32_t P) noexcept;

    // destructor
    //  - iterate through hashtable, call dtor for vectors
    //  - deallocate hashtable
    //  - deallocate memory
    // ---------------------------------------------------
    ~OpenTable() noexcept;

    // insert a process and assign a new page of memory
    // ------------------------------------------------
    bool Insert(unsigned int PID);

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
    // Sub functions: recursively push all usable pages onto vector
    // ------------------------------------------------------------
    void _RECUR_PUSH_PAGES(std::uint32_t mem = 0);

    // Sub function: recursively check each node and insert to empty node
    // ------------------------------------------------------------------
    bool _RECUR_FIND_INSERT(unsigned int PID, std::size_t collision = 0);

    // Sub function: recursively search for a PID key
    // ----------------------------------------------
    int _RECUR_DOUBLE_SEARCH(unsigned int PID, std::size_t collision = 0) const;

    // secondary hash function h(k, i)
    // -------------------------------
    std::uint32_t h2(unsigned int k, unsigned int i) const;

private:
    int* m_Mem;             // the memory of the entire memory block

    std::uint32_t m_P;    // size per page
    std::uint32_t m_N;    // size of total memory
    std::uint32_t m_M;    // max number of processes can be added
    std::uint32_t m_NP;   // number of current processes

    Process* hashtable;  // the pointer to the hashtable

    std::vector<unsigned int> m_usableMem;  // the array to track the usable page
};

#endif