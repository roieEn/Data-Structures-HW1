#include <iostream>
#include "Tree.h"
#include "Stack.h"

int main() {
    Tree oak = Tree();
    oak.PrintInOrder(oak.GetRoot());
    std::cout << "test1" << std::endl;
    oak.Add(5);
    oak.PrintInOrder(oak.GetRoot());

    oak.Add(3);
    oak.Add(4);
    oak.Add(7);
    std::cout << "test2" << std::endl;
    oak.PrintInOrder(oak.GetRoot());
    oak.Add(2);
    std::cout << "test3" << std::endl;

    oak.PrintInOrder(oak.GetRoot());
    std::cout << "break" << std::endl;
    oak.PrintPreOrder(oak.GetRoot());
    std::cout << "break, trying to delete" << std::endl;
    oak.Remove(2);
    std::cout << "test 4" << std::endl;
    oak.PrintInOrder(oak.GetRoot());
    std::cout << "test 5" << std::endl;

    oak.Remove(3);
    oak.PrintInOrder(oak.GetRoot());
    std::cout << "test 6" << std::endl;

    oak.Remove(5);
    std::cout << "test 6.5" << std::endl;

    oak.PrintInOrder(oak.GetRoot());
    std::cout << "test 7" << std::endl;

    Stack stack = Stack();
    stack.Push(5);
    stack.Push(3);
    std::cout << stack.Pop() << " " << stack.Pop() << std::endl;


}
