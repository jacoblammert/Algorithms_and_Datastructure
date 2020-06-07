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

    std::cout<<"Min: " << tree.minimum()->value_ << std::endl;
    std::cout<<"Max: " << tree.maximum()->value_ << std::endl;

    tree.maximum()->predecessor();

    tree.search(10);

    //std::cout<<"S1: " << tree.maximum()->predecessor()->predecessor()->value_ << std::endl;
    //std::cout<<"S2: " << tree.minimum()->predecessor()->predecessor()->predecessor()->value_ << std::endl;
    //std::cout<<"S3: " << tree.minimum()->predecessor()->predecessor()->predecessor()->predecessor()->value_ << std::endl;

    tree.PrintBST();

    return 0;
}
