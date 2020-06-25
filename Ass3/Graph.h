
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
    std::string information;

public:
    Graph(std::vector<Node *> nodes, bool directed);
    ~Graph();

    void addNode(Node *node);
    void prim();
    void relax(Node* u, Node* v, int w);
    void print(std::string name,bool parent);

    bool bellmanFord();

    std::string getInfoParent();
    std::string getInfoConnection();
};


#endif //ALGORITHMS_AND_DATASTRUCTURE_GRAPH_H
