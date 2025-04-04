#include <iostream>
#include <string>
#include <unordered_map>
#include <list>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
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


   bool hasCycle(Node *node,Node *parent,set<Node*> visited)
   {
    visited.insert(node);
    for(auto edge : node->getEdges())
    {
        if(edge->to == parent)
          continue;

        if(visited.find(edge->to) != visited.end() || hasCycle(edge->to,node, visited))
          return true;
        
    
         
    }

    return false;

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
  
      return Path(); 
  }

   bool hasCycle()
   {
    
    set<Node*> visited;
    for(auto pair : nodes)
    {
       Node* node = pair.second;
      if(visited.find(node) == visited.end() && hasCycle(node,nullptr,visited))
           return true;
    }

    return false;
   }

   wightedGraph getMinimumSpanningTree() {
    wightedGraph mst;
    if (nodes.empty()) return mst;

    for (auto& pair : nodes) {
        mst.addNode(pair.first);
    }

    priority_queue<NodeEntry, vector<NodeEntry>, CompareNodeEntry> queue;
    set<Node*> visited;

    Node* startNode = nodes.begin()->second;
    queue.push(NodeEntry(startNode, 0));

    unordered_map<Node*, Edge*> minEdgeTo;

    while (!queue.empty()) {
        NodeEntry current = queue.top();
        queue.pop();

        if (visited.find(current.node) != visited.end()) continue;
        visited.insert(current.node);

        if (minEdgeTo[current.node] != nullptr) {
            Edge* edge = minEdgeTo[current.node];
            mst.addEdge(edge->from->label, edge->to->label, edge->weight);
        }

        for (auto edge : *(current.node->edges)) {
            Node* neighbor = edge->to;
            if (visited.find(neighbor) == visited.end()) {
                if (minEdgeTo.find(neighbor) == minEdgeTo.end() || 
                    edge->weight < minEdgeTo[neighbor]->weight) {
                    minEdgeTo[neighbor] = edge;
                    queue.push(NodeEntry(neighbor, edge->weight));
                }
            }
        }
    }

    return mst;
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
    
  cout << "Shortest path from A to D: ";
  for (const string& node : path.getNodes()) { 
      cout << node << " ";
  }
  cout << endl;


    wightedGraph *graph3 = new wightedGraph();

    graph3->addNode("A");
    graph3->addNode("B");
    graph3->addNode("C");
    graph3->addEdge("A","B",0);
    graph3->addEdge("B","C",0);


    cout<<"graph has cycle: "<<(graph3->hasCycle() ? "Yes" : "NO");

  cout<<endl;

  cout<<"minimum spaning tree: "<<endl;

    wightedGraph graph4;
    

    graph4.addNode("A");
    graph4.addNode("B");
    graph4.addNode("C");
    graph4.addNode("D");
    graph4.addNode("E");
    
   
    graph4.addEdge("A", "B", 4);
    graph4.addEdge("A", "C", 1);
    graph4.addEdge("B", "C", 2);
    graph4.addEdge("B", "D", 5);
    graph4.addEdge("C", "D", 8);
    graph4.addEdge("C", "E", 10);
    graph4.addEdge("D", "E", 2);
    
    cout << "Original Graph:" << endl;
    graph4.printConnections();
    
  
    wightedGraph mst = graph4.getMinimumSpanningTree();
    
    cout << "\nMinimum Spanning Tree:" << endl;
    mst.printConnections();


    return 0;


}