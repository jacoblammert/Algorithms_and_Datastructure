
#ifndef ALGORITHMS_AND_DATASTRUCTURE_GRAPH_H
#define ALGORITHMS_AND_DATASTRUCTURE_GRAPH_H


#include <vector>
#include <fstream>
#include "MinHeap.h"

class Graph {
private:
    std::vector<Node *> nodes;
    MinHeap *minPriorityQueue;
    bool isDirected;

public:
    Graph(std::vector<Node *> nodes, bool directed);
    ~Graph();

    void addNode(Node *node);
    void prim();


    // TODO: implement Bellman-Ford
    void bellmanFord();

    void print(std::string name,bool before);
    std::string getInfoParent();
    std::string getInfoConnection();
};


#endif //ALGORITHMS_AND_DATASTRUCTURE_GRAPH_H
