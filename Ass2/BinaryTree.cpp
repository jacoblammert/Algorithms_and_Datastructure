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
 * Searches for an int value inside the Binary tree and returns the Pointer to the Node/Part
 *
 * This function is working correctly
 *
 * @param value value it searches for
 * @return pointer to the leaf or nullpointer, if the value is not in the tree
 */
BinaryTree *BinaryTree::search(int value) {

    if (value == value_) {
        //std::cout << "Found value " << value << std::endl;
        return this;
    }

    if (value < value_) {
        if (nullptr != left_)
            return left_->search(value);
    } else {
        if (nullptr != right_)
            return right_->search(value);
    }
    return nullptr;
}

/**
 * Assumes that the binary tree is sorted from left to right to get the minimum recursively
 * The function gives us the pointer to the min value from the top to the bottom
 *
 * This function is working correctly
 *
 * @return Pointer to min of the binary tree
 */
BinaryTree *BinaryTree::minimum() {
    if (nullptr == left_) {
        return this;
    } else {
        left_->minimum();
    }
}

/**
 * Assumes that the binary tree is sorted from left to right to get the maximum recursively
 * The function gives us the pointer to the max value from the top to the bottom
 *
 * This function is working correctly
 *
 * @return Pointer to max of the binary tree
 */
BinaryTree *BinaryTree::maximum() {
    if (nullptr == right_) {
        return this;
    } else {
        right_->maximum();
    }
}

/**
 * Inserts a value into the Binary tree
 * This does not guarantee, that the Binary Tree is balanced.
 * if a sorted list is added one by one, the tree will be extremely unbalanced
 *
 * This function is working correctly
 *
 * @param value added int value
 */
void BinaryTree::insertValue(int value) {
    if (value < value_) {
        if (nullptr != left_) {
            left_->insertValue(value);
        } else {
            left_ = new BinaryTree(value);
            left_->parent_ = this;
        }
    } else {
        if (nullptr != right_) {
            right_->insertValue(value);
        } else {
            right_ = new BinaryTree(value);
            right_->parent_ = this;
        }
    }
}

//TODO Add the delete a value function
void BinaryTree::deleteValue(int value) {

    BinaryTree *pointerToValue = search(value);

    if (nullptr == pointerToValue) {
        std::cout << "The value you want to delete does not exist inside the tree\n";
        return;
    }

    /// Case 1 left and right are empty
    if (nullptr == pointerToValue->left_ && nullptr == pointerToValue->right_) {
        if (nullptr == pointerToValue->parent_) {
            pointerToValue->value_ = 0; /// 0 = value for a reset tree (not really optimal)
        } else {
            if (pointerToValue->parent_->left_ == pointerToValue) {
                pointerToValue->parent_->left_ = nullptr;
                pointerToValue->parent_ = nullptr;
                delete pointerToValue;
            } else {
                pointerToValue->parent_->right_ = nullptr;
                pointerToValue->parent_ = nullptr;
                delete pointerToValue;
            }
        }
        return;
    }

    /// Case 2 left is null, right is not
    if (nullptr == pointerToValue->left_ && nullptr != pointerToValue->right_) {

        pointerToValue->right_->parent_ = pointerToValue->parent_;  // setting the parent of right to the parent of this
        
        if (pointerToValue->parent_->left_ == pointerToValue) {
            delete pointerToValue->parent_->left_;// setting the left of the parent to this right
        } else {
            delete pointerToValue->parent_->right_;  // setting the right of the parent to this right
        }
        return;
    }
        /// Case 3 right is null, left is not
    else if (nullptr == pointerToValue->right_ && nullptr != pointerToValue->left_) {

        pointerToValue->left_->parent_ = pointerToValue->parent_; // setting the parent of left to the parent of this


        if (pointerToValue->parent_->left_ == pointerToValue) {
            pointerToValue->parent_->left_ = pointerToValue->left_; // setting the left of the parent to this left
            delete this;
        } else {
            pointerToValue->parent_->right_ = pointerToValue->left_; // setting the right of the parent to this left
            delete this;
        }
        return;
    }

    /// Case 4 left and right are not null

    if (nullptr != pointerToValue->left_ && nullptr != pointerToValue->right_) {

        BinaryTree *max = left_->maximum();
        pointerToValue->value_ = max->value_; // we got the max value from the smaller tree and can now delete that smaller part

        if (max->parent_->right_ == max) {
            max->parent_->right_ = nullptr;
        } else if (max->parent_->left_ == max) {
            max->parent_->left_ = nullptr;
        }
        delete max;
        return;
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
 * it is not really as efficient as it could be, but since it is only used once or twice, I thought it would do the job
 *
 * This function is working correctly
 *
 * @return
 */
std::string BinaryTree::getInfo() {
    std::string info;
    /*/ // prints the connection from a node to its parent // to uncomment, you can add a *  to the / * / to make it to / * * / (without the spaces)
    if (nullptr != parent_) {
        info += "\"" + std::to_string(value_) + "\" -> \"" + std::to_string(parent_->value_) + "\"\n";
    }/**/

    /// if a number is inside the tree more than once, the tree drawing System is not working correctly even though the tree works correctly and adds the numbers at the right positions
    if (nullptr != left_) {
        info += "\"" + std::to_string(value_) + "\" -> \"" + std::to_string(left_->value_) + "\"\n" + left_->getInfo();
    }
    if (nullptr != right_) {
        info += "\"" + std::to_string(value_) + "\" -> \"" + std::to_string(right_->value_) + "\"\n" +
                right_->getInfo();
    }
    return info;
}




