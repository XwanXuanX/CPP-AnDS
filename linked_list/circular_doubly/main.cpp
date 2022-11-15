#include "c_d_list.cpp"

int main()
{
    LinkList* list = new LinkList();
    list->push_back(1);
    list->push_back(3);
    list->push_back(5);
    list->push_back(7);
    list->push_front(1);
    list->pop_back();
    list->pop_front();
    list->print_forward();

    LinkList* list2 = new LinkList();
    list2->push_back(1);
    list2->push_back(1);
    list2->push_back(3);
    list2->push_back(5);
    list2->push_back(6);
    list2->print_forward();

    // merge
    list->merge(*list2);
    list->print_forward();
    list->print_backward();

    delete list, list2;
    list = list2 = nullptr;
    return 0;
}
