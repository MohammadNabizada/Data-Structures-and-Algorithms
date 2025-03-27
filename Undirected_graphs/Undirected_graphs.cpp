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

      Edge(int weight,Node* from,Node* to){
        this->weight = weight;
        this->from = from;
        this->to = to;

      }

    };
   unordered_map<string,Node*> nodes;
   unordered_map<Node*,list<Edge*>> adjacancyList;

   public:
   void addNode(string label)
   {
    if(nodes.find(label) == nodes.end()){
    Node* newNode = new Node(label);
    nodes[label] = newNode;
    adjacancyList[newNode] = list<Edge*>();
    }
   }

   void addEdge(string from,string to, int weight)
   {
    auto fromKey = nodes.find(from);
    auto toKey = nodes.find(to);
    if(fromKey == nodes.end() || toKey == nodes.end())
       return;
       
    Node* fromNode = fromKey->second;
    Node* toNode = toKey->second;


    Edge *edge = new Edge(weight,fromNode,toNode);
    adjacancyList[fromNode].push_back(edge);
    adjacancyList[toNode].push_back(edge);

   }


   void printAdjacancyList()
   {
    cout << "Adjacancy List"<<endl;
    for(auto& pair : adjacancyList)
    {
      Node* node = pair.first;

      for(auto &edge : adjacancyList[node])
        cout<<"["<<edge->from->label << "]" << "is Connected to" <<"["<< edge->to->label << "]"<< "with weight" << edge->weight<<endl;
    }
   }

};

int main()
{

  wightedGraph *graph = new wightedGraph();
  graph->addNode("A");
  graph->addNode("B");
  graph->addNode("C");
  graph->addEdge("A","B",3);
  graph->addEdge("A","C",2);
  graph->printAdjacancyList();

    return 0;


}