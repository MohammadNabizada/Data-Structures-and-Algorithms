#include <iostream>
#include <string>
#include <unordered_map>
#include <list>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

class Path {
  private:
      list<string> nodes;
  
  public:
      void add(string node) {
          nodes.push_back(node);
      }
      const list<string>& getNodes() const {
        return nodes;
    }
  };

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
   
   struct NodeEntry{
    Node* node;
    int priority;
    NodeEntry(Node* node,int priority): node(node), priority(priority){}
   };

   struct CompareNodeEntry
   {
    bool operator()(const NodeEntry a,const NodeEntry b)
    {
      return a.priority > b.priority;
    }
   };

   Path buildPath(unordered_map<Node*, Node*> previousNodes, Node* toNode) {
    stack<Node*> stack;
    stack.push(toNode);
    auto previous = previousNodes[toNode];
    
    while (previous != nullptr) {
        stack.push(previous);
        previous = previousNodes[previous];
    }

    Path path;
    while (!stack.empty()) {
        path.add(stack.top()->label);
        stack.pop();
    }
    return path;
}

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
   
    Path getShortestPath(string from, string to) {
      Node* fromNode = nodes.find(from)->second;
      Node* toNode = nodes.find(to)->second;
  
      unordered_map<Node*, Node*> previousNodes;
      unordered_map<Node*, int> distances;
      priority_queue<NodeEntry, vector<NodeEntry>, CompareNodeEntry> queue;
  
      for (auto& node : nodes) {
          distances[node.second] = INT_MAX;
      }
  
      distances[fromNode] = 0;
      queue.push(NodeEntry(fromNode, 0));
  
      while (!queue.empty()) {
          NodeEntry current = queue.top();
          queue.pop();
  
          if (current.node == toNode) {
              return buildPath(previousNodes, toNode);
          }
  
          for (auto edge : *(current.node->edges)) {
              Node* neighbor = edge->to;
              int newDistance = distances[current.node] + edge->weight;
  
              if (newDistance < distances[neighbor]) {
                  distances[neighbor] = newDistance;
                  previousNodes[neighbor] = current.node;
                  queue.push(NodeEntry(neighbor, newDistance));
              }
          }
      }
  
      return Path();  // Return empty path if no path exists
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

  wightedGraph *graph2 = new wightedGraph();
  
  cout<<"===============================================";
  cout<<endl;
  graph2->addNode("A");
  graph2->addNode("B");
  graph2->addNode("C");
  graph2->addNode("D");
  graph2->addNode("E");

  
  graph2->addEdge("A","B",3);
  graph2->addEdge("A","D",2);
  graph2->addEdge("B","E",1);
  graph2->addEdge("B","D",6);
  graph2->addEdge("A","C",4);
  graph2->addEdge("C","D",1);
  graph2->addEdge("D","E",5);

  Path path = graph2->getShortestPath("A", "D");
    
  // 5. Print the path (you'll need to add this to your Path class)
  cout << "Shortest path from A to D: ";
  for (const string& node : path.getNodes()) {  // Assuming you add getNodes()
      cout << node << " ";
  }
  cout << endl;
    return 0;


}