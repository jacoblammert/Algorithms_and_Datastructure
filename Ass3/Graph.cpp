

#include "Graph.h"


/**
 * prim algorithm to get the smallest spanning tree
 * it is not working, because the extractMin() function did not wort for some reason
 */
void Graph::prim() {
    for (int i = 0; i < nodes.size(); ++i) {
        nodes[i]->setParent_dist(nullptr,INFINITY);
    }
    nodes[0]->setDist(0);

    minPriorityQueue = new MinHeap{nodes};

    while (!minPriorityQueue->isEmpty()){
        Node* u = minPriorityQueue->extractMin();
        std::map<Node*,int> neighbours = u->getNeighbours();
        for (auto v: neighbours) {
            if(nullptr != v.first && minPriorityQueue->isIn(v.first) && v.second < v.first->getDistance()){
                v.first->setParent_dist(u,v.second);
            }
        }
    }


}

/**
 * Second algorithm we should implement
 */
void Graph::bellmanFord() {
    for (int i = 0; i < nodes.size(); ++i) {
        nodes[i]->setParent_dist(nullptr,INFINITY);
    }
    nodes[0] = 0;

    for (int j = 0; j < nodes.size()-1; ++j) {
        for (int i = 0; i < nodes[j]->getNeighbours().size(); ++i) {

        }
    }
}
/**
 * Constructor to generate Graphs
 * @param nodes as an array
 * @param directed bool, whether it is directed or not
 */
Graph::Graph(std::vector<Node *> nodes, bool directed) :
        nodes{std::move(nodes)} {
    isDirected = directed;
}

/**
 * Destructor to delete the Graph
 */
Graph::~Graph() {
    for (int i = nodes.size(); i < 1; --i) {
        delete nodes[i];
    }
}
/**
 * method to add a node to the Graph
 * @param node to be added
 */
void Graph::addNode(Node *node)  {
    nodes.push_back(node);
}

/**
 * Prints a Graph in dot file in this folder
 */
void Graph::print() {
    std::ofstream textfile("../Ass3/example.dot");
    textfile << "strict digraph {\n" + getInfo() + "}";
}

/**
 * Method for printing
 * Takes the information from all the Nodes
 * @return String of Information
 */
std::string Graph::getInfo() {

    std::string info;

    for (int i = 0; i < nodes.size(); ++i) {
        info = info + nodes[i]->getInformation();
    }
    return info;
}


