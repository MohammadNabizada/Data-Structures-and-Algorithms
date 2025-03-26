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

      Edge(weight): weight(weight), from{nullptr}, to{nullptr}{}

    };
   unordered_map<string,Node*> nodes;
   unordered_map<Node*,list<Edge*>> adjacancyList;

   public:
   void addNode(string label)
   {
    if(nodes.find(label) == node.end()){
    Node* newNode = new Node(label);
    nodes[label] = newNode;
    adjacancyList[newNode] = list<Edge*>();
    }
   }

   void addEdge(string from,string to, int weight)
   {
    auto fromKey = nodes.find(from);
    auto tokey = nodes.find(to);
    if(fromKey == nodes.end() || toKey == nodes.end())
       return;
       
    Node* fromNode = fromKey->second;
    Node* toNode = tokey->second;


    Edge *edge = new Edge(fromNode,toNode,weight);
    adjacancyList[fromNode].push_back(edge);
    adjacancyList[toNode].push_back(edge);

   }


   void printAdjacancyList()
   {
    cout << "Adjacancy List";
    for(auto& pair : adjacancyList)
    {
      Node* node = pair.first;

      for(auto &edge : adjacancyList[node])
        cout<<"["<<edge->from->label << "]" << "is Connected to" <<"[" edge->to << "]"<< "with weight" << edge->weight;
    }
   }

};

int main()
{



    return 0;


}