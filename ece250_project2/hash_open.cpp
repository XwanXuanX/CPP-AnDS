#include "hash_open.h"

// Sub functions: recursively push all usable pages onto vector
// ------------------------------------------------------------
void OpenTable::_RECUR_PUSH_PAGES(std::uint32_t mem)
{
    if(mem >= m_N)
        return;
    // push usable page address to vec
    m_usableMem.push_back(mem);
    _RECUR_PUSH_PAGES(mem + this->m_P);
}

// constructor
//  - store N & P & M
//  - allocate Memory
//  - set NP = 0
//  - allocate hashtable with M nodes
// ----------------------------------
OpenTable::OpenTable(std::uint32_t N, std::uint32_t P) noexcept :
    m_N(N), m_P(P), m_M(N / P), m_NP(0), m_Mem(new int[N]), hashtable(new Process[N / P])
{
    // useable pages should equal to max processes
    m_usableMem.reserve(m_M);
    // initialize all usable memory
    _RECUR_PUSH_PAGES();
}

// destructor
//  - iterate through hashtable, call dtor for vectors
//  - deallocate hashtable
//  - deallocate memory
// ---------------------------------------------------
OpenTable::~OpenTable() noexcept
{
    delete[] hashtable;
    delete[] m_Mem;
}

// secondary hash function h(k, i)
// -------------------------------
std::uint32_t OpenTable::h2(unsigned int k, unsigned int i) const
{
    // primary hash function
    auto h1 = [this](unsigned int k) -> std::uint32_t {
        return k % this->m_M;
    };
    // secondary hash function
    auto h2 = [this](unsigned int k) -> std::uint32_t {
        int t = (k / this->m_M) % this->m_M;
        return (t % 2 == 0) ? t + 1 : t;
    };
    // combine together
    return (h1(k) + i * h2(k)) % m_M;
}

// Sub function: recursively check each node and insert to empty node
// ------------------------------------------------------------------
bool OpenTable::_RECUR_FIND_INSERT(unsigned int PID, std::size_t collision)
{
    // lambda function to get the usable address
    auto AssignPage = [this]() -> std::uint64_t
    {
        std::uint64_t addr = *this->m_usableMem.rbegin() * sizeof(int) + \
            reinterpret_cast<std::uint64_t>(this->m_Mem);
        this->m_usableMem.pop_back();
        return addr;
    };
    // if collision is greater than m - 1, return false
    if(collision > m_M - 1)
        return false;
    // calculate next position
    std::uint32_t hash = h2(PID, collision);
    // termination condition / when meet an empty slot
    if(hashtable[hash].getPID() == 0)
    {
        hashtable[hash].setPID(PID);          // set process PID
        hashtable[hash].setAddr(AssignPage());// assign valid address
        ++m_NP;
        return true;
    }
    // terminate condition / when find existing PID
    if(hashtable[hash].getPID() == PID)
        return false;
    // recursively call the function
    return OpenTable::_RECUR_FIND_INSERT(PID, collision + 1);
}

// insert a process and assign a new page of memory
// ------------------------------------------------
bool OpenTable::Insert(unsigned int PID)
{
    // if all pages are used, then false
    if(m_NP >= m_M)
        return false;
    // make sure the PID is not present
    if(_RECUR_DOUBLE_SEARCH(PID) == -1)
        return _RECUR_FIND_INSERT(PID);
    else
        return false;
}

// Sub function: recursively search for a PID key
// ----------------------------------------------
int OpenTable::_RECUR_DOUBLE_SEARCH(unsigned int PID, std::size_t collision) const
{
    // if collision is greater than m - 1
    if(collision > m_M - 1)
        return -1;
    // calculate next position
    std::uint32_t hash = h2(PID, collision);
    // if found the PID
    if(hashtable[hash].getPID() == PID)
        return hash;
    return OpenTable::_RECUR_DOUBLE_SEARCH(PID, collision + 1);
}

// search the PID in hashtable
// ---------------------------
void OpenTable::Search(unsigned int PID) const noexcept
{
    int f = _RECUR_DOUBLE_SEARCH(PID);
    if(f == -1)
        std::cout << "not found\n";
    else
        std::cout << "found " << PID << " in " << f << '\n';
}

// write the integer x to memory address
// -------------------------------------
bool OpenTable::Write(unsigned int PID, unsigned int ADDR, int x) const
{
    // if the address is larger than the page, then false
    if(ADDR > this->m_P - 1)
        return false;
    // otherwise...
    int idx = _RECUR_DOUBLE_SEARCH(PID);
    // if not found, then false
    if(idx == -1)
        return false;
    hashtable[idx].write(ADDR, x);
    return true;
}

// read the integer stored in the memory
// -------------------------------------
bool OpenTable::Read(unsigned int PID, unsigned int ADDR) const
{
    if(ADDR > this->m_P - 1)
        return false;
    // otherwise...
    int idx = _RECUR_DOUBLE_SEARCH(PID);
    if(idx == -1)
        return false;
    std::cout << ADDR << ' ' << hashtable[idx].read(ADDR) << '\n';
    return true;
}

// Delete the key PID from the hash table
// --------------------------------------
bool OpenTable::Delete(unsigned int PID)
{
    int idx = _RECUR_DOUBLE_SEARCH(PID);
    // if not found
    if(idx == -1)
        return false;
    // otherwise, recollect the page memory
    unsigned int t = (hashtable[idx].getAddr() - reinterpret_cast<std::uint64_t>(m_Mem)) / sizeof(int);
    this->m_usableMem.push_back(t);
    // delete the process
    hashtable[idx].setAddr(0);
    hashtable[idx].setPID(0);
    --m_NP;
    return true;
}