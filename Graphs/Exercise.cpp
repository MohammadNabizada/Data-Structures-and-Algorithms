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
using namespace std;

class Graph{

    private :
     class Node{
        public:
          string label;
          Node(string label): label(label){}
     };
    unordered_map<string,Node*> nodes;
 
     public:

     ~Graph() {
        for (auto& pair : nodes) {
            delete pair.second; // Delete each Node
        }
    }

       void AddNode(string label)
       {
          if(nodes.find(label) == nodes.end())
             nodes[label] = new Node(label);
       }

       void AddEdge(string from,string to)
       {
           auto it1 = nodes.find(from);
           if (it1 != nodes.end())Node *FromNode = it1->second;
           else cerr << "Key '" << from << "' not found in the hash map!" <<endl;

           auto it2 = nodes.find(to);
           if (it2 != nodes.end())Node *ToNode = it2->second;
           else cerr << "Key '" << from << "' not found in the hash map!" <<endl;

       }

};



int main()
{



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