#include <iostream>
#include "Tree.h"

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
}
