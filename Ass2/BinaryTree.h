//
// Created by Jacob on 07.06.2020.
//

#ifndef ALGORITHMS_AND_DATASTRUCTURE_BINARYTREE_H
#define ALGORITHMS_AND_DATASTRUCTURE_BINARYTREE_H


struct BinaryTree {
public:


    BinaryTree(int value);


    void PrintBST();

    BinaryTree* search(int value);

    void insertValue(int value);
    void deleteValue(int value); // i could not name the variable delete, therfore I added Value to insert and delete.

    BinaryTree* minimum();
    BinaryTree* maximum();
    BinaryTree* successor();
    BinaryTree* predecessor();


    BinaryTree* left_ = nullptr;
    BinaryTree* right_ = nullptr;
    BinaryTree* parent_ = nullptr;
    int value_;

private:
    std::string getInfo(int counter);
};


#endif //ALGORITHMS_AND_DATASTRUCTURE_BINARYTREE_H
