#include "hash_ordered.h"

// Sub functions: recursively push all usable pages onto vector
// ------------------------------------------------------------
void HashTable::_RECUR_PUSH_PAGES(std::uint32_t mem)
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
//  - allocate hashtable with M slots
// ----------------------------------
HashTable::HashTable(std::uint32_t N, std::uint32_t P) noexcept :
    m_N(N), m_P(P), m_M(N / P), m_NP(0), m_Mem(new int[N]), hashtable(new HASH[N / P])
{
    // useable pages should equal to max processes
    m_usableMem.reserve(m_M);
    // initialize all usable memory
    _RECUR_PUSH_PAGES();
}

// destructor
//  - iterate through hashtable, call dtor vectors
//  - deallocate hashtable
//  - deallocate memory
// ---------------------------------------------------
HashTable::~HashTable() noexcept
{
    delete[] hashtable;
    delete[] m_Mem;
}

// primary hash function (h1)
// --------------------------
std::uint32_t HashTable::h1(unsigned int k) const
{
    return k % m_M;
}

// Sub function: recursively iterate through vector to find PID
// ------------------------------------------------------------
int HashTable::_RECUR_INSERT_PROC(unsigned int PID, const HASH& list, std::size_t idx)
{
    // if found already existing PID, return -1
    if(list[idx].getPID() == PID)
        return -1;
    // if found element with lower PID, return idx
    if(list[idx].getPID() < PID)
        return idx;
    // recursive call with idx inc
    return _RECUR_INSERT_PROC(PID, list, idx + 1);
}

// insert a process and assign a new page of memory
// ------------------------------------------------
bool HashTable::Insert(unsigned int PID)
{
    // if all pages are use, false
    if(m_NP >= m_M || PID <= 0)
        return false;
    // lambda function to assign pages to processes
    auto AssignPage = [this](unsigned int PID) -> Process
    {
        std::uint64_t addr = *this->m_usableMem.rbegin() * sizeof(int) + \
            reinterpret_cast<std::uint64_t>(this->m_Mem);
        this->m_usableMem.pop_back();
        return Process(addr, PID);
    };
    // get into the bucket
    HASH& list = this->hashtable[h1(PID)];
    // take care of edge cases
    if(list.size() == 0)
    {
        list.push_back(AssignPage(PID));
        ++m_NP;
        return true;
    }
    if(list.begin()->getPID() < PID)
    {
        list.insert(list.begin(), AssignPage(PID));
        ++m_NP;
        return true;
    }
    if(list.rbegin()->getPID() > PID)
    {
        list.push_back(AssignPage(PID));
        ++m_NP;
        return true;
    }
    // assert(PID should be in range of {max, min})
    int idx = _RECUR_INSERT_PROC(PID, list, 0);
    if(idx == -1)
        return false;
    list.insert(list.begin() + idx, AssignPage(PID));
    ++m_NP;
    return true;
}

// Sub function: recursively traverse through each element
// -------------------------------------------------------
void HashTable::_RECUR_FIND_PRINT(HASH::iterator start, decltype(start) end) const
{
    if(start == end)
        return;
    std::cout << start->getPID() << ' ';
    _RECUR_FIND_PRINT(start + 1, end);
}

// print the chain of keys in position m in decending order
// --------------------------------------------------------
void HashTable::Print(std::size_t m) const noexcept
{
    // if the array is empty
    if(hashtable[m].size() == 0)
    {
        std::cout << "chain is empty\n";
        return;
    }
    // otherwise, recursively print out the elements
    _RECUR_FIND_PRINT(hashtable[m].begin(), hashtable[m].end());
    std::cout << '\n';
}

// Sub function: binary search
// ---------------------------
int HashTable::_BINARY_SEARCH(const HASH& list, unsigned int PID, int start, int end) const
{
    if(start > end)
        return -1;
    // find middle
    std::size_t mid = (end + start) / 2;
    // if found
    if(list[mid].getPID() == PID)
        return mid;
    else if(list[mid].getPID() > PID)
        return _BINARY_SEARCH(list, PID, mid + 1, end);
    else
        return _BINARY_SEARCH(list, PID, start, mid - 1);
}

// search the PID in hashtable
// ---------------------------
void HashTable::Search(unsigned int PID) const noexcept
{
    std::size_t hash = h1(PID);
    if(_BINARY_SEARCH(hashtable[hash], PID, 0, hashtable[hash].size() - 1) != -1)
        std::cout << "found " << PID << " in " << hash << '\n';
    else
        std::cout << "not found\n";
}

// write the integer x to memory address
// -------------------------------------
bool HashTable::Write(unsigned int PID, unsigned int ADDR, int x) const
{
    // if the address is larger than the page, then false
    if(ADDR > this->m_P - 1)
        return false;
    // otherwise...
    std::size_t hash = h1(PID);
    int idx = _BINARY_SEARCH(hashtable[hash], PID, 0, hashtable[hash].size() - 1);
    // if not found, then false
    if(idx == -1)
        return false;
    hashtable[hash][idx].write(ADDR, x);
    return true;
}

// read the integer stored in the memory
// -------------------------------------
bool HashTable::Read(unsigned int PID, unsigned int ADDR) const
{
    if(ADDR > this->m_P - 1)
        return false;
    // otherwise...
    std::size_t hash = h1(PID);
    int idx = _BINARY_SEARCH(hashtable[hash], PID, 0, hashtable[hash].size() - 1);
    if(idx == -1)
        return false;
    std::cout << ADDR << ' ' << hashtable[hash][idx].read(ADDR) << '\n';
    return true;
}

// Delete the key PID from the hash table
// --------------------------------------
bool HashTable::Delete(unsigned int PID)
{
    std::size_t hash = h1(PID);
    int idx = _BINARY_SEARCH(hashtable[hash], PID, 0, hashtable[hash].size() - 1);
    // if not found
    if(idx == -1)
        return false;
    // otherwise, recollect the page memory
    unsigned int t = (hashtable[hash][idx].getAddr() - reinterpret_cast<std::uint64_t>(m_Mem)) / sizeof(int);
    this->m_usableMem.push_back(t);
    // delete the process
    hashtable[hash].erase(hashtable[hash].begin() + idx);
    --m_NP;
    return true;
}