

#ifndef ALGORITHMS_AND_DATASTRUCTURE_MINHEAP_H
#define ALGORITHMS_AND_DATASTRUCTURE_MINHEAP_H


#include "MinHeapNode.h"

class MinHeap {
private:
    MinHeapNode *root;

public:
    MinHeap(std::vector<Node*>);

    ~MinHeap();


    /**
     * Restructures the min priority queue
     * by getting all the nodes and reconstructing a new one
     */
    void restructure();

    bool isIn(Node*);

    Node *extractMin();

    bool isEmpty();
};


#endif //ALGORITHMS_AND_DATASTRUCTURE_MINHEAP_H
