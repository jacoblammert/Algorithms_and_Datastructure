
#include "Node.h"


Node::Node(std::string label) :
        label{std::move(label)} {
}

Node::Node(std::string label, std::map<Node *, int> adjacentNodes)
        : label{std::move(label)}, adjacentNodes{std::move(adjacentNodes)} {
}

/*/
Node() {
        for (auto elements: adjacentNodes) {
            adjacentNodes.erase(elements.first);
        }
}/**/


Node::Node(std::string label, Node *parent, int dist, const std::map<Node *, int> &adjacentNodes)
/*/: label{label}, parent{parent}, distance{dist}, adjacentNodes{adjacentNodes} /**/{}



/**
 * Adds a new Connection from the current element to the new node with a weight of the distance
 * @param node new Node
 * @param dist from current Node to new Node
 */
void Node::addConnection(Node *node, int dist) {
    adjacentNodes[node] = dist;
}
/**
 * For connections in both directions
 * @param node node this one is connected to
 * @param dist of the connection
 */
void Node::Connect(Node *node, int dist) {
    adjacentNodes[node] = dist;
}

/**
 * If the graph is bidirectional, the prim algorithm works.
 * Therefore we have to make it bidirectional by connecting the nodes we point to
 * with us and make them point at us as well
 */
void Node::update() {
    for (auto elements : adjacentNodes){
        elements.first->Connect(this,elements.second);
    }
}


void Node::removeNode(std::string labels) {

    for (auto elements: adjacentNodes) {
        if (elements.first->label == labels) { // name of the nodes is the same
            if (nullptr != elements.first) {
                delete elements.first;
            }
        }
    }
}

/**
 * Set the new Parent of the node and set a distance/ weight of the edge
 * @param new_parent new parent of this node
 * @param dist new weight
 */
void Node::setParent_dist(Node *new_parent, int dist) {
    parent = new_parent;
    distance = dist;
}

void Node::setParent(Node *new_parent) {
    parent = new_parent;
}


void Node::setDist(int dist) {
    distance = dist;
}

int Node::getMinDist() {
    //return 0;
    ///*/
    if (adjacentNodes.empty()) {
        return distance;
    }
    int min = distance;//adjacentNodes.begin()->second;
    for (const auto &elements: adjacentNodes) {
        if (elements.second < min) {
            min = elements.second;
        }
    }
    return min;
    /**/
}

std::string Node::getInformationParent() {
    std::string info;
    /*/
    for (const auto &element: adjacentNodes) {
        if (!element.first->label.empty()) {
            info += label + "->" + element.first->label + "[label = \"" + std::to_string(element.second) +
                    "\",weight=\"" + std::to_string(element.second) + "\"];\n";
        }
    }/*/
    if (nullptr != parent) { //
        info += label + "->" + parent->label + "[label = \"" + std::to_string(distance) + "\",weight=\"" +
                std::to_string(distance) + "\"];\n";
    }
    /**/

    return info;
}

std::string Node::getInformationConnection() {
    std::string info;
    /**/
    for (const auto &element: adjacentNodes) {
        if (nullptr != element.first && !element.first->label.empty()) {
            info += label + "->" + element.first->label + "[label = \"" + std::to_string(element.second) +
                    "\",weight=\"" + std::to_string(element.second) + "\"];\n";
        }
    }
    /*/
    if (nullptr != parent) { //
        info += label + "->" + parent->label + "[label = \"" + std::to_string(distance) + "\",weight=\"" +
                std::to_string(distance) + "\"];\n";
    }
    /**/

    return info;
}

std::string Node::getLabel() {
    return label;
}

Node::~Node() {
    for (auto elements: adjacentNodes) {
        delete elements.first;

    }
}

std::map<Node *, int> Node::getNeighbours() {
    return adjacentNodes;
}

int Node::getDistance() {
    return distance;
}


int Node::getDistanceTo(Node *here) {
    return adjacentNodes.find(here)->second;//[here]
    return 99999;
}






