#include "c_list.cpp"

int main()
{
    LinkList* list = new LinkList();
    list->push_back(1);
    list->push_back(3);
    list->push_back(4);
    list->push_front(2);
    list->push_back(1);
    list->print();
    list->pop_back();
    list->pop_front();
    list->print();

    int res = list->find(3);
    (res == -1) ? \
        std::cout << "not found..." << std::endl : \
        std::cout << "found at " << res << std::endl;

    std::cout << list->size() << "\n";

    LinkList* list2 = new LinkList();
    list2->push_back(2);
    list2->push_back(4);
    list2->push_back(7);
    std::cout << "list1: "; list->print();
    std::cout << "list2: "; list2->print();
    list->merge(*list2);
    list->print();

    list->reverse();
    list->print();

    delete list, list2;
    list = list2 = nullptr;
    return 0;
}