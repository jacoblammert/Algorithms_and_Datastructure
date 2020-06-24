

#include "MinHeap.h"

#include <utility>

/**
 * rebuilds the Minheap by getting all the elements out first and rebuilding it afterwards
 */
void MinHeap::restructure() {

    std::vector<Node *> OldNodes = root->getNodes();
    root = new MinHeapNode{OldNodes, nullptr};

}


/**
 * function to get the pointer to the element with the smallest connection to another element
 * @return the Node
 */
Node *MinHeap::extractMin() {

    Node *minHeapNode = root->extractSmallest();
    //root->deleteSmallest();
    return minHeapNode;
}

/**
 * Constructor takes a Node array
 * @param vec Nodes
 */
MinHeap::MinHeap(std::vector<Node *> vec) {
    root = new MinHeapNode{vec, nullptr};
}

/**
 * true, if the Heap is empty
 * @return
 */
bool MinHeap::isEmpty() {
    return root->isEmpty();
}

/**
 * Chacks, if a Node has the same name as a Node inside the Heap
 * @param node node to check for
 * @return is in/ is not inside the graph
 */
bool MinHeap::isIn(Node * node) {
    std::vector<Node*> nodes = root->getNodes();

    for (int i = 0; i < nodes.size(); ++i) {
        if (node->getLabel() == nodes[i]->getLabel()) {
            return true;
        }
    }
    return false;

}

/**
 * Destructor
 */
MinHeap::~MinHeap() {
    delete root;
}