
#include "Node.h"


Node::Node(std::string label) :
        label{std::move(label)} {
}

Node::Node(std::string label, std::map<Node *, int> adjacentNodes)
        : label{std::move(label)}, adjacentNodes{std::move(adjacentNodes)} {
}


Node::Node(std::string label, Node *parent, int dist, const std::map<Node *, int> &adjacentNodes){

}

Node::~Node() {
    for (auto elements: adjacentNodes) {
        delete elements.first;

    }
}


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

/**
 * a function to remove the Connection to a Node, where the name of the Node to remove is the input as string
 * @param labels
 */
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
/**
 * @param new_parent set the parent of the Node to a new parent
 */
void Node::setParent(Node *new_parent) {
    parent = new_parent;
}

/**
 * set the Distance of this Node to its parent as int
 * @param dist
 */
void Node::setDist(int dist) {
    distance = dist;
}
int Node::getDistance() {
    return distance;
}

/**
 * returns the dist from this Node to a given Node if they are connected
 * @param here
 * @return
 */
int Node::getDistanceTo(Node *here) {
    return adjacentNodes.find(here)->second;
}

/**
 * @return the minimum distance of this Node to any other Node
 */
int Node::getMinDist() {
    if (adjacentNodes.empty()) {
        return distance;
    }
    int min = distance;
    for (const auto &elements: adjacentNodes) {
        if (elements.second < min) {
            min = elements.second;
        }
    }
    return min;
}

/**
 * @return a string with the Nodes Parent and Distance as Information
 */
std::string Node::getInformationParent() {
    std::string info;
    if (nullptr != parent) { //
        info += label + "->" + parent->label + "[label = \"" + std::to_string(distance) + "\",weight=\"" +
                std::to_string(distance) + "\" color = \"red\"];\n";
    }
    return info;
}

/**
 * @return a string with the Information of the Node and its connections
 */
std::string Node::getInformationConnection() {
    std::string info;
    for (const auto &element: adjacentNodes) {
        if (nullptr != element.first && !element.first->label.empty()) {
            info += label + "->" + element.first->label + "[label = \"" + std::to_string(element.second) +
                    "\",weight=\"" + std::to_string(element.second) + "\"];\n";
        }
    }
    return info;
}

/**
 * @return Name of the Node as string
 */
std::string Node::getLabel() {
    return label;
}

/**
 * @return all nodes this node points to as map
 */
std::map<Node *, int> Node::getNeighbours() {
    return adjacentNodes;
}







