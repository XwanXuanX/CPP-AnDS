#ifndef PROCESS_H
#define PROCESS_H

#include <iostream>

class Process
{
public:
    // constructor - set assigned page address and ID
    // ----------------------------------------------
    Process(std::uint64_t ADDR, unsigned int PID) noexcept;

    // default constructor
    // -------------------
    Process() : m_addr(0), m_PID(0) {}

    // getters
    // -------
    std::uint64_t getAddr() const noexcept;
    unsigned int getPID() const noexcept;

    // setters
    // -------
    void setAddr(std::uint64_t ADDR) noexcept;
    void setPID(unsigned int PID) noexcept;

    // write a variable to virtual memory address
    // ------------------------------------------
    void write(std::uint32_t V_ADDR, int X) const;

    // read a variable from the virtual memory address
    // -----------------------------------------------
    int read(std::uint32_t V_ADDR) const;

private:
    std::uint64_t m_addr;   // the start off memory of the page
    unsigned int m_PID;     // the ID of the process
};

#endif