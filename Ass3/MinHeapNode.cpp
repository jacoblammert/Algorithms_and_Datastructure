
#include "MinHeapNode.h"

/**
 * Constuctor to generate Heap Nodes
 * @param nodes takes an Node array
 * @param parent and gets a parent
 */
MinHeapNode::MinHeapNode(std::vector<Node *> nodes, MinHeapNode *parent) {

    this->parent = parent;

    if (!nodes.empty()) {
        node = nodes[0];
        int minNode = node->getMinDist();

        std::vector<Node *> leftNodes;
        std::vector<Node *> rightNodes;

        for (int i = 1; i < nodes.size(); ++i) {
            if (minNode < nodes[i]->getMinDist()) {
                rightNodes.push_back(nodes[i]);
            } else {
                leftNodes.push_back(nodes[i]);
            }
        }
        if (!leftNodes.empty()) {
            left = new MinHeapNode{leftNodes, this};
        }
        if (!rightNodes.empty()) {
            right = new MinHeapNode{rightNodes, this};
        }
    }
}


/**
 * returns all nodes including its own back
 * @return
 */
std::vector<Node *> MinHeapNode::getNodes() {
    std::vector<Node *> vector;
    if(nullptr != node) {
        vector.push_back(node);
    } else{
        return{};
    }

    std::vector<Node *> newNodes;

    if (nullptr != left) {
        newNodes = left->getNodes();
        vector.insert(vector.end(), newNodes.begin(), newNodes.end());
    }
    if (nullptr != right) {

        newNodes = right->getNodes();
        vector.insert(vector.end(), newNodes.begin(), newNodes.end());
    }

    return vector;
}

/**
 * returns true, if the MinHeapNode is empty
 * @return
 */
bool MinHeapNode::isEmpty() {
    return nullptr == node && nullptr == left && nullptr == right;
}

/**
 * Destructor deletes the left and right element first to prevent memory leaks
 */
MinHeapNode::~MinHeapNode() {
    while (nullptr != left) {
        delete left;
    }
    while (nullptr != right) {
        delete right;
    }
    node = nullptr;
}

/**
 * returns a pointer to the smallest element from the heap
 * @return
 */
Node *MinHeapNode::extractSmallest() {

    if (nullptr != left) {
        return left->extractSmallest();
    }
    return node;
}

/**
 * This method is not used, because I had a problem returning the node pointer in the extract function
 *
 * Deletes the smallest element from the heap
 * and stitches the other HeapNodes back together
 */
void MinHeapNode::deleteSmallest() {
    if (nullptr == left && nullptr == right){
        if (nullptr != parent ) {
            if (parent->left == this) {
                parent->left = nullptr;
            } else {
                parent->right = nullptr;
            }
        }
        delete this;
        return;
    }

    if (nullptr == left && nullptr != right){
        if(nullptr != parent){
            if (parent->left == this) {
                parent->left = right;
                right->parent = parent;
                delete this;
            } else {
                parent->right = right;
                right->parent = parent;
            }
        } else{
            right = right->right;
            left = right->left;
            node = right->node;
            right->parent = nullptr;
            delete right;
            return;;
        }
    }

    left->deleteSmallest();
}

/**
 * returns its own Node to use it in different methods
 * @return
 */
Node *MinHeapNode::getNode() {
    return node;
}

