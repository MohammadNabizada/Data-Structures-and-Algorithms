//Graphs class
  //Node class
    //lable:string
  //Add Node(lable)
  //Remove Node(lable)
  //addEdge(from, to)
  //RemoveEdge(from, to)
  //print() A is connected with [B,C]
#include <iostream>
#include <string>
#include <unordered_map>
#include <list>
#include <algorithm>
using namespace std;

class Graph{

    private :
     class Node{
        public:
          string label;
          Node(string label): label(label){}
     };

    unordered_map<string,Node*> nodes;
    unordered_map<Node*, list<Node*>> adjacencyList;

     public:

     ~Graph() {
        for (auto& pair : nodes) {
            delete pair.second; 
        }
      }

       void AddNode(string label)
       {
          if(nodes.find(label) == nodes.end()){
             Node* node = new Node(label);
             nodes[label] = node;
             adjacencyList[node] = list<Node*>();
          }
       }

       void AddEdge(string from,string to)
       {
        auto it1 = nodes.find(from);
        auto it2 = nodes.find(to);

        if (it1 == nodes.end()) {
            cerr << "Key '" << from << "' not found in the hash map!" << endl;
            return;
        }
        if (it2 == nodes.end()) {
            cerr << "Key '" << to << "' not found in the hash map!" << endl;
            return;
        }

        Node* FromNode = it1->second;
        Node* ToNode = it2->second;

        
        adjacencyList[FromNode].push_back(ToNode);
        cout << "Edge added from '" << from << "' to '" << to << "'." << endl;
       }



       void PrintAdjacencyList() const {
        cout << "Adjacency List:" << endl;
        for (const auto& pair : adjacencyList) {
            Node* fromNode = pair.first;
            for (const auto& toNode : pair.second) {
                cout << "Node " << fromNode->label << " is connected to Node " << toNode->label << endl;
            }
        }
    }

    void removeNode(string label)
    {
        Node* node = nodes[label];
        if(node == nullptr)
          return;
        for(auto& pair : adjacencyList)
        {
            auto& neighbors = pair.second;
            neighbors.remove(node);
        }

        adjacencyList.erase(node);
        nodes.erase(label);

        delete node;
        cout << "Node '" << label << "' removed successfully." << endl;
    }

   



};



int main()
{
    Graph graph;
    graph.AddNode("A");
    graph.AddNode("B");
    graph.AddNode("C");

   
    graph.AddEdge("A", "B");
    graph.AddEdge("A", "C");
    graph.AddEdge("B", "C");

    
    graph.PrintAdjacencyList();

    return 0;
}

