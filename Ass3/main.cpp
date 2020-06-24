//
// Created by Jacob on 21.06.2020.
//
#include "Node.h"
#include "Graph.h"

int main(){

    std::vector<Node*> nodes;

    nodes.push_back(new Node{"a"/**/,{{new Node("b"),2}/*/,{new Node("c"),3},{new Node("d"),3}/**/}});
    nodes.push_back(new Node{"b"/**/,{{new Node("c"),4}/*/,{new Node("c"),2},{new Node("e"),3}/**/}});
    nodes.push_back(new Node{"c"/**/,{{new Node("a"),3},{new Node("b"),4},{new Node("d"),5},{new Node("f"),6},{new Node("e"),1}}});
    nodes.push_back(new Node{"f"/**/,{{new Node("d"),7}/*/,{new Node("e"),8},{new Node("g"),9}/**/}});

    nodes.push_back(new Node{"g"/**/,{{new Node("f"),9}}});
    nodes.push_back(new Node{"d"/**/,{{new Node("a"),3},{new Node("c"),5},{new Node("f"),7}}});
    nodes.push_back(new Node{"e"/**/,{{new Node("b"),3},{new Node("c"),1},{new Node("f"),8}}});


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
    graphTemplate.prim();
    graphTemplate.print();


    return 0;
}

