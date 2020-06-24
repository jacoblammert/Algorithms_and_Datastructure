

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
    int distance; // aka key

public:
    Node(std::string label);

    Node(std::string label, std::map<Node*, int> adjacentNodes);

    ~Node();


    Node(std::string label, Node *parent, int dist, const std::map<Node*, int>& adjacentNodes);

    void addConnection(Node *node, int dist);

    std::string getLabel();
    int getDistance();

    void removeNode(std::string labels);
    void setParent_dist(Node *new_parent, int dist);

    std::map<Node*,int> getNeighbours();

    void setParent(Node *new_parent, int dist);
    void setDist(int dist);
    int getMinDist();
    std::string getInformation();
};


#endif //ALGORITHMS_AND_DATASTRUCTURE_NODE_H
