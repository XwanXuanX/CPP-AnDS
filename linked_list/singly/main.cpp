#include "s_list.cpp"

int main()
{
    LinkList* list = new LinkList();
    list->push_back(4);
    list->push_back(6);
    list->push_front(1);

    int res = list->find(3);
    (res == -1) ? \
        std::cout << "not found..." << std::endl : \
        std::cout << "found at " << res << std::endl;

    std::cout << list->size() << std::endl;
    list->insert(1, 1);
    std::cout << list->front() << std::endl;
    std::cout << list->back() << std::endl;
    list->erase(2);
    list->print();

    LinkList* list2 = new LinkList();
    list2->push_back(1);
    list2->push_back(5);
    list2->push_back(7);
    list2->push_back(8);
    list->merge(*list2);
    list->print();
    list->reverse();
    list->print();
    return 0;
}