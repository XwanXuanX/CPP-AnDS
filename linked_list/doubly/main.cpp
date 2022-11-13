#include "d_list.cpp"

int main()
{
    LinkList* list = new LinkList();
    list->push_back(1);
    list->push_back(2);
    list->push_back(4);
    list->push_front(1);

    auto print_result = [](const int* res) {
        (*res == -1) ? \
            std::cout << "not found..." << std::endl : \
            std::cout << "found at " << *res << std::endl;
    };

    int res = list->find_jump(7);
    print_result(&res);

    std::cout << list->size() << "\n";

    list->insert(8, 2);
    list->print_forward();
    list->reverse();
    list->print_backward();
    list->erase(3);
    list->print_backward();

    std::cout << list->front() << "\n";
    std::cout << list->back() << "\n";

    delete list;
    list = nullptr;
    return 0;
}