//
// Created by Jacob on 07.06.2020.
//


#include <fstream>
#include <string>
#include <iostream>
#include "BinaryTree.h"

/**
 * Initializes the binary tree with an int value
 * @param value
 */
BinaryTree::BinaryTree(int value) :
        value_(value) {}


void BinaryTree::PrintBST() {
    std::ofstream textfile("../Ass2/example.txt");
    textfile << "strict digraph {\n" + getInfo() + "}";
}

/**
 * Searches for an int value inside the Binary tree
 * @param value value it searches for
 * @return pointer to the leaf or nullpointer, if the value is not in the tree
 */
BinaryTree *BinaryTree::search(int value) {

    if (value == value_) {
        std::cout << "Found value " << value << std::endl;
        return this;
    }

    if (value < value_) {
        if (nullptr != left_)
            left_->search(value);
    } else {
        if (nullptr != right_)
            right_->search(value);
    }
    return nullptr;
}

/**
 * Assumes that the binary tree is sorted from left to right to get the minimum recursively
 * @return Pointer to min of the binary tree
 */
BinaryTree *BinaryTree::minimum() {
    if (nullptr == left_) {
        //std::cout << "Min:" << value_ << std::endl;
        return this;
    } else {
        left_->minimum();
    }
}

/**
 * Assumes that the binary tree is sorted from left to right to get the maximum recursively
 * @return Pointer to max of the binary tree
 */
BinaryTree *BinaryTree::maximum() {
    if (nullptr == right_) {
        //std::cout << "Max:" << value_ << std::endl;
        return this;
    } else {
        right_->maximum();
    }
}

/**
 * Inserts a value into the Binary tree
 * This does not guarantee, that the Binary Tree is balanced.
 * if a sorted list is added one by one, the tree will be extremely unbalanced
 * @param value added int value
 */
void BinaryTree::insertValue(int value) {
    if (value < value_) {
        if (nullptr != left_) {
            left_->insertValue(value);
        } else {
            left_ = new BinaryTree(value);
        }
    } else {
        if (nullptr != right_) {
            right_->insertValue(value);
        } else {
            right_ = new BinaryTree(value);
        }
    }
}

void BinaryTree::deleteValue(int value) {
    BinaryTree *pointerToValue = search(value);
    if (nullptr == pointerToValue) {
        return;
    }

    if (nullptr == left_ && nullptr == right_) {

    }


}

/**
 * returns the Node with the next biggest part of the tree
 * @return pointer to the part of the binary tree
 */
BinaryTree *BinaryTree::successor() {

    if (nullptr != right_) {
        return right_->minimum();
    }


    if (nullptr != parent_) {
        BinaryTree *bottom = this;
        BinaryTree *top = parent_;
        while (top->right_ == bottom) {
            bottom = top;
            if (nullptr != top->parent_) {
                top = top->parent_;
            } else {
                return nullptr;
            }
        }
        if (nullptr != top->right_) {
            return top->right_->minimum();
        }
    }
    return nullptr;

}

/**
 * returns the Node with the next smallest part of the tree
 * @return pointer to the part of the binary tree
 */
BinaryTree *BinaryTree::predecessor() {
    if (nullptr != left_) {
        return left_->maximum();
    }
    if (nullptr != parent_) {
        BinaryTree *bottom = this;
        BinaryTree *top = parent_;

        while (top->left_ == bottom) {
            bottom = top;
            if (nullptr != top->parent_) {
                top = top->parent_;
            } else {
                return nullptr;
            }
        }
        if (nullptr != top->left_) {
            return top->left_->maximum();
        }
    }
    return nullptr;

}

/**
 * Returns a big Sting with all the Information about the binary tree
 * @return
 */
std::string BinaryTree::getInfo() {
    std::string info;
    if (nullptr != left_) {
        info += "\"" + std::to_string(value_) + "\" -> \"" + std::to_string(left_->value_) + "\"\n" + info += left_->getInfo();
    }
    if (nullptr != right_) {
        info += "\"" + std::to_string(value_) + "\" -> \"" + std::to_string(right_->value_) + "\"\n" + right_->getInfo();
    }
    return info;
}




