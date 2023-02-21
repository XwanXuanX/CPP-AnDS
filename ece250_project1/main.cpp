#include "linkedlist.h"

int main()
{
    // input commands
    std::string CMD;
    // placeholder
    LinkedList* List = nullptr;
    // test function
    while(std::cin >> CMD)
    {
        if(CMD == "CRT")
        {
            std::size_t N;
            std::cin >> N;
            List = new LinkedList(N);
            std::cout << "success\n";
        }
        else if(CMD == "DEF")
        {
            std::string name;
            double val;
            std::cin >> name;
            std::cin >> val;
            if(List->Insert(name, val))
                std::cout << "success\n";
            else
                std::cout << "failure\n";
        }
        else if(CMD == "ADD")
        {
            std::string x, y, z;
            std::cin >> x >> y >> z;
            if(List->Add(x, y, z))
                std::cout << "success\n";
            else
                std::cout << "failure\n";
        }
        else if(CMD == "SUB")
        {
            std::string x, y, z;
            std::cin >> x >> y >> z;
            if(List->Sub(x, y, z))
                std::cout << "success\n";
            else
                std::cout << "failure\n";
        }
        else if(CMD == "REM")
        {
            std::string name;
            std::cin >> name;
            if(List->Remove(name))
                std::cout << "success\n";
            else
                std::cout << "failure\n";
        }
        else if(CMD == "PRT")
        {
            std::string name;
            std::cin >> name;
            List->PRT(name);          
        }
        else if(CMD == "END")
        {
            delete List;
            return 0;
        }
    }
}