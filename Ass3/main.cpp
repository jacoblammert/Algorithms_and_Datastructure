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


    //nodes[0]->addConnection(new Node{"b"},2);
    //nodes[1]->addConnection(*nodes[2],4);

    //nodes[2]->removeNode("a");


    //nodes.push_back(new Node{"a"});
    //nodes.push_back(new Node{"b"});
    //nodes.push_back(new Node{"c"});
    //nodes.push_back(new Node{"d"});
    //nodes.push_back(new Node{"e"});
    //nodes.push_back(new Node{"f"});


    Graph graphTemplate{nodes,true};
    //graphTemplate.removeNode(new Node{"a"});
    graphTemplate.print("beforePrim",false);
    graphTemplate.prim();
    graphTemplate.print("afterPrim",true);




    return 0;
}

