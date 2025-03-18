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
#include <vector>
using namespace std;


class Graph{
    private:
    class Node{
      public:

      string label;
      vector<Node*> neighbours;

      Node(string lable): label(lable),neighbours{nullptr}{}
    };

    vector<Node*> Nodes;
    

    bool hasLabel(const vector<Node*> Nodes, const string& targetLabel) {
        for (Node* head : Nodes) {
            if (head != nullptr && head->label == targetLabel) {
                return true; 
            }
        }
        return false;
    }
    public:
   

    void AddNode(string label)
    {
        if(!hasLabel(Nodes,label))
        {
            Node* newNode = new Node(label);
            Nodes.push_back(newNode);
        }
    }
  };




  int main()
  {
     
    Graph *graph = new Graph();

    graph->AddNode("A");
    graph->AddNode("B");
    graph->AddNode("C");



    return 0;
  }