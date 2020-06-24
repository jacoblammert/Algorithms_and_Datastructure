
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
    //adjacentNodes.insert(std::make_pair(node, dist));
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

void Node::setParent(Node *new_parent, int dist) {
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
    int min = adjacentNodes.begin()->second;
    for (const auto &elements: adjacentNodes) {
        if (elements.second < min) {
            min = elements.second;
        }
    }
    return min;
    /**/
}

std::string Node::getInformation() {
    std::string info;/**/
    for (const auto &element: adjacentNodes) {
        if (!element.first->label.empty()) {
            info += label + "->" + element.first->label + "[label = \"" + std::to_string(element.second) +
                    "\",weight=\"" + std::to_string(element.second) + "\"];\n";
        }
    }

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




