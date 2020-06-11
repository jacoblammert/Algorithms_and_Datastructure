//
// Created by Jacob on 07.06.2020.
//

#include <iostream>
#include "BinaryTree.h"

int main(){

    BinaryTree tree(8);
    tree.insertValue(3);
    tree.insertValue(1);
    tree.insertValue(6);
    tree.insertValue(4);
    tree.insertValue(7);
    tree.insertValue(10);
    tree.insertValue(14);
    tree.insertValue(13);

    tree.insertValue(2);
    tree.insertValue(5);
    tree.insertValue(-2);
    tree.insertValue(-1);
    tree.insertValue(0);
    tree.insertValue(9);


    std::cout<<"Min: " << tree.minimum()->value_ << std::endl;
    std::cout<<"Max: " << tree.maximum()->value_ << std::endl;

    tree.search(10);

    std::cout<< "Predecessor: " << tree.search(6)->predecessor()->value_<<std::endl;
    std::cout<< "Successor: " << tree.search(6)->successor()->value_<<std::endl;

    tree.deleteValue(13);

    tree.PrintBST();

    return 0;
}
