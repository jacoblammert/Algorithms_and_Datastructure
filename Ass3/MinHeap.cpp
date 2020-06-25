

#include "MinHeap.h"

#include <utility>

/**
 * rebuilds the Minheap by getting all the elements out first and rebuilding it afterwards
 */
void MinHeap::restructure() {
    std::vector<Node *> OldNodes = root->getNodes();

}


/**
 * function to get the pointer to the element with the smallest connection to another element
 * @return the Node with the smallest distance
 */
Node *MinHeap::extractMin() {

    Node *minHeapNode = nullptr;

    int counter = 0;
    std::vector<Node *> OldNodes = root->getNodes();
    if (!OldNodes.empty()) {
        for (int i = 1; i < OldNodes.size(); ++i) {
            if (OldNodes[i]->getMinDist() < OldNodes[counter]->getMinDist()) {
                counter = i;
            }
        }
        minHeapNode = OldNodes[counter];

        std::vector<Node *> NewNodes;

        for (int j = 0; j < OldNodes.size(); ++j) {
            if(counter != j){
                NewNodes.push_back(OldNodes[j]);
            }
        }
        root = new MinHeapNode{NewNodes, nullptr};
    }
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
bool MinHeap::isIn(Node *node) {
    std::vector<Node *> nodes = root->getNodes();

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

/**
 * @return all Nodes inside the Heap
 */
std::vector<Node *> MinHeap::getNodes() {
    return  root->getNodes();
}
