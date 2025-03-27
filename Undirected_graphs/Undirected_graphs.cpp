#include <iostream>
#include <string>
#include <unordered_map>
#include <list>
#include <algorithm>
using namespace std;

class wightedGraph{
   private:

   class Edge;  
    class Node{
        public:
        string label;
        list<Edge*> *edges = new list<Edge*>();
        Node(string label): label(label){}

        void addEdge(Node* to,int weight)
        {
          edges->push_back(new Edge(weight,this, to));
        }
        list<Edge*> getEdges()
        {
         return *edges;
        }
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


   public:
   ~wightedGraph() {
    for (auto& pair : nodes) {
        for (auto edge : *pair.second->edges) {
            delete edge;
        }
        delete pair.second->edges;
        delete pair.second;
    }
}

  

   void addNode(string label)
   {
    if(nodes.find(label) == nodes.end()){
    Node* newNode = new Node(label);
    nodes[label] = newNode;
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

    fromNode->addEdge(toNode, weight);
    toNode->addEdge(fromNode, weight);

   }


   void printConnections()
   {
    cout << "Adjacancy List" << endl;
    for (auto& pair : nodes) {
        Node* node = pair.second;
        cout << "[" << node->label << "] is connected to: ";
        for (auto edge : node->getEdges()) {
            cout << "[" << edge->to->label << "](weight:" << edge->weight << ") ";
        }
        cout << endl;
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
  graph->printConnections();

    return 0;


}