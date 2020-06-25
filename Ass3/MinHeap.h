

#ifndef ALGORITHMS_AND_DATASTRUCTURE_MINHEAP_H
#define ALGORITHMS_AND_DATASTRUCTURE_MINHEAP_H


#include "MinHeapNode.h"

class MinHeap {
private:
    MinHeapNode *root;

public:
    MinHeap(std::vector<Node*>);

    ~MinHeap();

    void restructure();

    bool isIn(Node*);

    Node *extractMin();

    std::vector<Node*> getNodes();

    bool isEmpty();
};


#endif //ALGORITHMS_AND_DATASTRUCTURE_MINHEAP_H
