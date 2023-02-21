#include "hash_open.h"

void TestOpen()
{
    // input commands
    std::string CMD;
    // placeholder
    OpenTable* table = nullptr;
    // test function
    while(std::cin >> CMD)
    {
        if(CMD == "M")
        {
            unsigned int N, P;
            std::cin >> N;
            std::cin >> P;
            table = new OpenTable(N, P);
            std::cout << "success\n";
        }
        else if(CMD == "INSERT")
        {
            unsigned int PID;
            std::cin >> PID;
            if(table->Insert(PID))
                std::cout << "success\n";
            else
                std::cout << "failure\n";
        }
        else if(CMD == "SEARCH")
        {
            unsigned int PID;
            std::cin >> PID;
            table->Search(PID);
        }
        else if(CMD == "WRITE")
        {
            unsigned int PID, ADDR;
            int x;
            std::cin >> PID;
            std::cin >> ADDR;
            std::cin >> x;
            if(table->Write(PID, ADDR, x))
                std::cout << "success\n";
            else
                std::cout << "failure\n";
        }
        else if(CMD == "READ")
        {
            unsigned int PID, ADDR;
            std::cin >> PID;
            std::cin >> ADDR;
            if(!table->Read(PID, ADDR))
                std::cout << "failure\n";
        }
        else if(CMD == "DELETE")
        {
            unsigned int PID;
            std::cin >> PID;
            if(table->Delete(PID))
                std::cout << "success\n";
            else
                std::cout << "failure\n";
        }
        else if(CMD == "END")
        {
            delete table;
            return;
        }
    }
    return;
}