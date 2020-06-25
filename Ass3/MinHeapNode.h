

#ifndef ALGORITHMS_AND_DATASTRUCTURE_MINHEAPNODE_H
#define ALGORITHMS_AND_DATASTRUCTURE_MINHEAPNODE_H


#include <vector>
#include <iostream>
#include "Node.h"

class MinHeapNode {
private:
    /* data */
    Node *node = nullptr;
    MinHeapNode *parent = nullptr;
    MinHeapNode *left = nullptr;
    MinHeapNode *right = nullptr;

public:

    /**
     * Sorts the Minheap from lowest minimal Connection inside the vector to highest minimal connection in the vector
     * @param nodes
     */
    MinHeapNode(std::vector<Node *> nodes,MinHeapNode *parent);


    std::vector<Node *> getNodes();


    ~MinHeapNode();

    Node* getNode();

    Node *extractSmallest();

    void deleteSmallest();

    bool isEmpty();

    // TODO: implement additional constructors
};


#endif //ALGORITHMS_AND_DATASTRUCTURE_MINHEAPNODE_H
