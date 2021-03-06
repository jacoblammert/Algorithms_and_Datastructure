

#ifndef ALGORITHMS_AND_DATASTRUCTURE_NODE_H
#define ALGORITHMS_AND_DATASTRUCTURE_NODE_H


#include <string>
#include <map>

class Node {
private:
    /* data */
    std::string label;
    std::map<Node*, int> adjacentNodes; // the int is for the weight of the egde
    Node *parent = nullptr;
    int distance = 9999999; // aka key

public:
    Node(std::string label);
    Node(std::string label, std::map<Node*, int> adjacentNodes);
    Node(std::string label, Node *parent, int dist, const std::map<Node*, int>& adjacentNodes);

    ~Node();

    void addConnection(Node *node, int dist);
    void Connect(Node* node,int dist);
    void update();
    void setParent(Node *new_parent);
    void setDist(int dist);
    void removeNode(std::string labels);
    void setParent_dist(Node *new_parent, int dist);

    int getDistance();
    int getDistanceTo(Node* here);
    int getMinDist();

    std::map<Node*,int> getNeighbours();

    std::string getLabel();
    std::string getInformationParent();
    std::string getInformationConnection();
};


#endif //ALGORITHMS_AND_DATASTRUCTURE_NODE_H
