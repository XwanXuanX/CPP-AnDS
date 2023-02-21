#include "process.h"

// constructor - set assigned page address and ID
// ----------------------------------------------
Process::Process(std::uint64_t ADDR, unsigned int PID) noexcept :
    m_addr(ADDR), m_PID(PID) {}

// getters
// -------
std::uint64_t Process::getAddr() const noexcept
{
    return m_addr;
}

unsigned int Process::getPID() const noexcept
{
    return m_PID;
}

// setters
// -------
void Process::setAddr(std::uint64_t ADDR) noexcept
{
    m_addr = ADDR;
}

void Process::setPID(unsigned int PID) noexcept
{
    m_PID = PID;
}

// write a variable to virtual memory address
// ------------------------------------------
void Process::write(std::uint32_t V_ADDR, int X) const
{
    int* px = reinterpret_cast<int*>(m_addr + V_ADDR * sizeof(int));
    *px = X;
}

// read a variable from the virtual memory address
// -----------------------------------------------
int Process::read(std::uint32_t V_ADDR) const
{
    int* px = reinterpret_cast<int*>(m_addr + V_ADDR * sizeof(int));
    return *px;
}