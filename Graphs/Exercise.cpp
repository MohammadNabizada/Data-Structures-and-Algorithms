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
            delete pair.second; // Delete each Node
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

        // Add the edge to the adjacency list
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
};



int main()
{
    Graph graph;
    graph.AddNode("A");
    graph.AddNode("B");
    graph.AddNode("C");

    // Add edges
    graph.AddEdge("A", "B");
    graph.AddEdge("A", "C");
    graph.AddEdge("B", "C");

    // Print the adjacency list
    graph.PrintAdjacencyList();

    return 0;
}



// class Graph{
//     private:
//     class Node{
//       public:

//       string label;
//       vector<Node*> neighbours;

//       Node(string lable): label(lable),neighbours{nullptr}{}
//     };

//     vector<Node*> Nodes;
    

//     bool hasLabel(const vector<Node*> Nodes, const string& targetLabel) {
//         for (Node* head : Nodes) {
//             if (head != nullptr && head->label == targetLabel) {
//                 return true; 
//             }
//         }
//         return false;
//     }
//     public:
   

//     void AddNode(string label)
//     {
//         if(!hasLabel(Nodes,label))
//         {
//             Node* newNode = new Node(label);
//             Nodes.push_back(newNode);
//         }
//     }
//   };




//   int main()
//   {
     
//     Graph *graph = new Graph();

//     graph->AddNode("A");
//     graph->AddNode("B");
//     graph->AddNode("C");



//     return 0;
//   }