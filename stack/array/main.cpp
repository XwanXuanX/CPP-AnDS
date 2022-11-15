#include "a_stack.cpp"
#include <memory>

int main()
{
    std::unique_ptr<Stack> stack = std::make_unique<Stack>();
    (stack->empty()) ? \
        std::cout << "empty" << "\n" :
        std::cout << "not empty" << "\n";

    stack->pop();
    stack->push(3);
    stack->push(5);
    stack->push(7);
    std::cout << "size: " << stack->size() << "\n";
    std::cout << "top: " << stack->get_top() << "\n";
    stack->pop();
    stack->pop();
    std::cout << "size: " << stack->size() << "\n";
    std::cout << "top: " << stack->get_top() << "\n";
    return 0;
}