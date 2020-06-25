

#ifndef ALGORITHMS_AND_DATASTRUCTURE_MINHEAPNODE_H
#define ALGORITHMS_AND_DATASTRUCTURE_MINHEAPNODE_H


#include <vector>
#include <iostream>
#include "Node.h"

class MinHeapNode {
private:
    Node *node = nullptr;
    MinHeapNode *parent = nullptr;
    MinHeapNode *left = nullptr;
    MinHeapNode *right = nullptr;

public:

    MinHeapNode(std::vector<Node *> nodes,MinHeapNode *parent);

    ~MinHeapNode();

    std::vector<Node *> getNodes();

    Node* getNode();

    Node *extractSmallest();

    void deleteSmallest();

    bool isEmpty();

};


#endif //ALGORITHMS_AND_DATASTRUCTURE_MINHEAPNODE_H
