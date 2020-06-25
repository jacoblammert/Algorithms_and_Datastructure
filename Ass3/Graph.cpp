

#include "Graph.h"


/**
 * prim algorithm to get the smallest spanning tree
 * it is not working, because the extractMin() function did not wort for some reason
 */
void Graph::prim() {
    for (int i = 0; i < nodes.size(); ++i) {
        nodes[i]->setParent_dist(nullptr,99999);
    }
    nodes[0]->setDist(0);

    minPriorityQueue = new MinHeap{nodes};
    std::vector<Node*> newNodes;

    while (!minPriorityQueue->isEmpty()){
        Node* u = minPriorityQueue->extractMin();
        std::map<Node*,int> neighbours = u->getNeighbours();
        for (auto v: neighbours) {
            if(minPriorityQueue->isIn(v.first) && v.second < v.first->getDistance()){
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
        std::map<Node*,int> neighbours = nodes[j]->getNeighbours();
        for (int i = 0; i < neighbours.size(); ++i) {

        }
    }
}

void relax(Node* u, Node* v, int w) {
    if (v->getDistance() > (w + u->getDistance())) {
        v->setParent(u);
        v->setDist(w + u->getDistance());
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
 *
 * Prints a Graph in dot file in this folder
 * @param name of the file
 * @param before bool, whether it should print the parents or the connections
 */
void Graph::print(std::string name,bool before) {
    std::ofstream textfile("../Ass3/" + name + ".dot");
    if (before) {
        textfile << "strict digraph {\n" + getInfoParent() + "}";
    } else{
        textfile << "strict digraph {\n" + getInfoConnection() + "}";
    }

}
/**
 * Method for printing
 * Takes the information from all the Nodes
 * @return String of Information
 */
std::string Graph::getInfoParent() {

    std::string info;

    //nodes = minPriorityQueue->getNodes();

    for (int i = 0; i < nodes.size(); ++i) {
        info = info + nodes[i]->getInformationParent();
    }
    return info;
}



/**
 * Method for printing
 * Takes the information from all the Nodes
 * @return String of Information
 */
std::string Graph::getInfoConnection() {

    std::string info;

    //nodes = minPriorityQueue->getNodes();

    for (int i = 0; i < nodes.size(); ++i) {
        info = info + nodes[i]->getInformationConnection();
    }
    return info;
}