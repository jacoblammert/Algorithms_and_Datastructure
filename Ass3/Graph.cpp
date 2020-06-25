

#include "Graph.h"


/**
 * prim algorithm to get the minimum spanning tree
 * it is not working, because the extractMin() function did not wort for some reason
 */
void Graph::prim() {
    for (int i = 0; i < nodes.size(); ++i) {
        nodes[i]->setParent_dist(nullptr, 9999999);
    }
    nodes[0]->setDist(0);

    minPriorityQueue = new MinHeap{nodes};
    std::vector<Node *> newNodes;

    while (!minPriorityQueue->isEmpty()) {
        Node *u = minPriorityQueue->extractMin();
        std::map<Node *, int> neighbours = u->getNeighbours();
        for (auto v: neighbours) {
            if (minPriorityQueue->isIn(v.first) && v.second < v.first->getDistance()) {
                v.first->setParent_dist(u, v.second);
            }
        }
    }
}

/**
 * Second algorithm we should implement
 */
bool Graph::bellmanFord() {


    for (int i = 0; i < nodes.size(); ++i) {
        nodes[i]->setParent_dist(nullptr, 9999999);
    }
    nodes[0]->setDist(0);

    for (int k = 0; k < nodes.size(); ++k) {
        for (int j = 0; j < nodes.size(); ++j) {

            std::map<Node *, int> neighbours = nodes[j]->getNeighbours();
            for (auto element: neighbours) {
                relax(nodes[j], element.first, element.second);
            }
        }
    }
    for (Node *node : nodes) {
        if (nullptr != node) {
            std::map<Node *, int> neighbours = node->getNeighbours();/**/
            for (auto element : neighbours) {
                if (element.first->getDistance() > (element.second + node->getDistance())) {
                    return false;
                }
            }
        }
    }
    return true;
}

/**
 * relaxing method finding out, whether a shorter path has been found.
 * if so, it updates the graph
 * @param u Node 1
 * @param v Node 2
 * @param w dist from N1 to N2
 */
void Graph::relax(Node *u, Node *v, int w) {

    w += u->getDistance();

    if (v->getDistance() > w) {
        v->setParent_dist(u,w);
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

    if (!isDirected) {
        for (int i = 0; i < this->nodes.size(); ++i) {
            this->nodes[i]->update();
        }
    }
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
void Graph::addNode(Node *node) {
    nodes.push_back(node);
}


/**
 *
 * Prints a Graph in dot file in this folder
 * @param name of the file
 * @param parent bool, whether it should print the parents or the connections
 */
void Graph::print(std::string name, bool parent) {
    std::ofstream textfile("../Ass3/" + name + ".dot");
    if (parent) {
        information +=  getInfoParent();
        textfile << "digraph {\n" + information + "}";
    } else {
        information = getInfoConnection(); // this second Graph will have the Colorinformation as well, therefore we can display the color in the graph
        textfile << "digraph {\n" + information + "}";
    }

}

/**
 * Method for printing
 * Takes the information from all the Nodes
 * @return String of Information
 */
std::string Graph::getInfoParent() {

    std::string info;

    for (int i = 0; i < nodes.size(); ++i) {
        if (nullptr != nodes[i]) {
            info = info + nodes[i]->getInformationParent();
        }
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

    for (int i = 0; i < nodes.size(); ++i) {
        info = info + nodes[i]->getInformationConnection();
    }
    return info;
}