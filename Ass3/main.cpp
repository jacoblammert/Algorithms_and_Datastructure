//
// Created by Jacob on 21.06.2020.
//
#include "Node.h"
#include "Graph.h"

int main(){

    std::vector<Node*> nodes;

    Node* a = new Node{"a"};
    Node* b = new Node{"b"};
    Node* c = new Node{"c"};
    Node* d = new Node{"d"};
    Node* e = new Node{"e"};
    Node* f = new Node{"f"};
    Node* g = new Node{"g"};

    a->addConnection(b,2);

    c->addConnection(a,3);
    c->addConnection(b,4);
    c->addConnection(f,6);

    d->addConnection(a,3);
    d->addConnection(c,5);
    d->addConnection(f,7);

    e->addConnection(b,3);
    e->addConnection(c,1);
    e->addConnection(f,8);

    g->addConnection(f,9);


    nodes.push_back(a);
    nodes.push_back(b);
    nodes.push_back(c);
    nodes.push_back(d);
    nodes.push_back(e);
    nodes.push_back(f);
    nodes.push_back(g);


    //// if directed is true for the graph template, the algorithm works fine, if not, it will only show subgraphs and not the complete minimum spanning tree
    Graph graphTemplate{nodes, false};
    graphTemplate.print("beforePrim",false);
    graphTemplate.prim();
    /**
     * The prim algorithm only works, if the Graph is bidirectional. (directed = false)
     * If the graph is not bidirectional, the algorithm may only give us parts of a tree and not all nodes
     * This is only for the computation and the graph itself can be directional or bidirectional
     */
    graphTemplate.print("afterPrim",true);



    std::vector<Node*> nodes1;





    Node* a1 = new Node{"a"};
    Node* b1 = new Node{"b"};
    Node* c1 = new Node{"c"};
    Node* d1 = new Node{"d"};
    Node* e1 = new Node{"e"};
    Node* s1 = new Node{"s"};

    a1->addConnection(c1,2);
    b1->addConnection(a1,1);
    c1->addConnection(b1,-2);
    d1->addConnection(c1,-1);
    d1->addConnection(a1,-4);
    e1->addConnection(d1,1);
    s1->addConnection(e1,8);
    s1->addConnection(a1,10);

    nodes1.push_back(s1);
    nodes1.push_back(a1);
    nodes1.push_back(b1);
    nodes1.push_back(c1);
    nodes1.push_back(d1);
    nodes1.push_back(e1);


    /**
     * The print functions are as not correct as they should be and they are a bit messy :(
     * The numbers on the red arrows are the new min dist found
     *
     * there are four files printed.
     * Two for each algorithm before and after using the algorithm for the graph
     */

    Graph graphTemplate2{nodes1, true};

    graphTemplate2.print("beforeBellmanFord", false);
    std::cout<<graphTemplate2.bellmanFord()<<std::endl;
    graphTemplate2.print("afterBellmanFord", true);



    return 0;
}

