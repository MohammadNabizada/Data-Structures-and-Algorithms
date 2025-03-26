#include <iostream>
#include <string>
#include <unordered_map>
#include <list>
#include <algorithm>
using namespace std;

class wightedGraph{
   private:
    class Node{
        public:
        string label;
        Node(string label): label(label){}
    };

    class Edge{
      public:
      Node* from;
      Node* to;
      int weight;

      Edge(weight): weight(weight){}

    };
   unordered_map<string,Node*> nodes;
   unordered_map<Node*,list<Node*>> adjacancyList;

   public:
   void addNode(string label)
   {
    if(nodes.find(label) == node.end()){
    Node* newNode = new Node(label);
    nodes[label] = newNode;
    adjacancyList[newNode] = list<Node*>();
    }
   }

   

};

int main()
{



    return 0;


}