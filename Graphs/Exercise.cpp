
#include <iostream>
#include <string>
#include <unordered_map>
#include <list>
#include <algorithm>
#include <set>
#include <stack>
#include <queue>
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
    void DfsRecursively(Node* current_node, set<Node*> visited)
    {
        if(current_node == nullptr || visited.find(current_node) != visited.end())
          return;
        
        visited.insert(current_node);
        cout<<current_node->label<< ' ';

        for(Node* neighbor : adjacencyList[current_node])
        {
            if(visited.find(neighbor) == visited.end())
              DfsRecursively(neighbor,visited);
        }
    }
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

    void removeEdge(const string& from, const string& to) {
      
        auto itFrom = nodes.find(from);
        if (itFrom == nodes.end()) {
            cerr << "Node '" << from << "' not found in the graph." << endl;
            return;
        }
    
       
        auto itTo = nodes.find(to);
        if (itTo == nodes.end()) {
            cerr << "Node '" << to << "' not found in the graph." << endl;
            return;
        }
    
        Node* fromNode = itFrom->second;
        Node* toNode = itTo->second;
    
        auto& neighbors = adjacencyList[fromNode];
        auto it = find(neighbors.begin(), neighbors.end(), toNode);
        if (it != neighbors.end()) {
            neighbors.erase(it); 
            cout << "Edge from '" << from << "' to '" << to << "' removed successfully." << endl;
        } else {
            cerr << "Edge from '" << from << "' to '" << to << "' does not exist." << endl;
        }
    }

   void Dfs(string startlabel)
   {
    auto it = nodes.find(startlabel);
    if(it == nodes.end())
      return;
    
    Node* startNode = it->second;
    set<Node*> visited;
    cout << "Depth-First Traversal (DFS) starting from '" << startlabel << "': ";
    DfsRecursively(startNode, visited);
    cout<<endl;
   }
   void DFS(const string& startLabel) {
    auto it = nodes.find(startLabel);
    if (it == nodes.end()) {
        cerr << "Node '" << startLabel << "' not found in the graph." << endl;
        return;
    }

    set<Node*> visited; 
    stack<Node*> stack; 

   
    stack.push(it->second);

    cout << "Depth-First Traversal (DFS) starting from '" << startLabel << "': ";
    while (!stack.empty()) {
        Node* current = stack.top();
        stack.pop(); 

      
        if (visited.find(current) == visited.end()) {
            visited.insert(current);
            cout << current->label << " ";

            
            for (Node* neighbor : adjacencyList[current]) {
                if (visited.find(neighbor) == visited.end()) {
                    stack.push(neighbor);
                }
            }
        }
    }
    cout << endl;
}
     void traverseBredthFirstFirst(string root)
     {
        auto it = nodes.find(root);
        if (it == nodes.end()) {
            cerr << "Node '" << root << "' not found in the graph." << endl;
            return;
        }
    
        set<Node*> visited; 
        queue<Node*> queue;
    
       
        queue.push(it->second);
        visited.insert(it->second); 
    
        cout << "Breadth-First Traversal (BFS) starting from '" << root << "': ";
        while (!queue.empty()) {
            Node* current = queue.front();
            queue.pop();
    
           
            cout << current->label << " ";
    
            
            for (Node* neighbor : adjacencyList[current]) {
                if (visited.find(neighbor) == visited.end()) {
                    visited.insert(neighbor);
                    queue.push(neighbor); 
                }
            }
        }
        cout << endl; 
     }
};



int main()
{
    Graph graph;
    graph.AddNode("A");
    graph.AddNode("B");
    graph.AddNode("C");
    graph.AddNode("D");
    graph.AddNode("E");

    graph.AddEdge("A", "B");
    graph.AddEdge("A", "C");
    graph.AddEdge("B", "D");
    graph.AddEdge("C", "E");
    graph.AddEdge("D", "E");
    // graph.removeEdge("A","C");
    // graph.removeNode("B");
    graph.PrintAdjacencyList();
    graph.Dfs("A");
    graph.traverseBredthFirstFirst("A");
    return 0;
}

