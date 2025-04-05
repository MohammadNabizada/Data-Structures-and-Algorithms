
#include <iostream>
#include <string>
#include <unordered_map>
#include <list>
#include <algorithm>
#include <set>
#include <stack>
#include <queue>
#include <vector>
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



	bool hasCycle(Node* node,set<Node*>& all,set<Node*>& visiting,set<Node*>& visited) {		
		all.erase(node);
		visiting.insert(node);

		
		for (Node* neighbor : adjacansyList[node]) {
			if (visited.find(neighbor) != visited.end()) {
				continue;
			}
			if (visiting.find(neighbor) != visiting.end()) {
				return true; 
			}
			if (hasCycle(neighbor, all, visiting, visited)) {
				return true;
			}
		}

		
		visiting.erase(node);
		visited.insert(node);
		return false;
	}

	void BFSrecursive(queue<Node*> queue, set<Node*> visited)
	{
		if (queue.empty())
			return;
		Node* currentNode = queue.front();
		queue.push(currentNode);
		queue.pop();
		cout << currentNode->label << " ";

		for (Node* neighbour : adjacancyList[currentNode]) {
			if (visited.find(neighbour) == visited.end()) {
				visited.insert(neighbour);
				queue.push(neighbour);
			}
		}

		BFSrecursive(queue, visited);
		
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
        auto fromKey = nodes.find(from);
        auto toKey = nodes.find(to);

        if (fromKey == nodes.end() || toKey == nodes.end()) {
            cerr << "Key '" << from <<"and"<<to<< "' not found in the hash map!" << endl;
            return;
        }
        Node* FromNode = fromKey->second;
        Node* ToNode = toKey->second;  
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
      
        auto fromKey = nodes.find(from);
        if (fromKey == nodes.end()) {
            cerr << "Node '" << from << "' not found in the graph." << endl;
            return;
        }
    
       
        auto toKey = nodes.find(to);
        if (toKey == nodes.end()) {
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


void topologicalSortUtil(Node* node, set<Node*>& visited, stack<Node*>& stack) {
    visited.insert(node); 

   
    for (Node* neighbor : adjacencyList[node]) {
        if (visited.find(neighbor) == visited.end()) {
            topologicalSortUtil(neighbor, visited, stack);
        }
    }

    
    stack.push(node);
}


vector<string> topologicalSort() {
    set<Node*> visited; 
    stack<Node*> stack; 

    for (auto& pair : nodes) {
        Node* node = pair.second;
        if (visited.find(node) == visited.end()) {
            topologicalSortUtil(node, visited, stack);
        }
    }

    vector<string> result;
    while (!stack.empty()) {
        result.push_back(stack.top()->label);
        stack.pop();
    }

    return result;
}




bool hasCycle() {
	set<Node*> all;
	set<Node*> visiting;
	set<Node*> visited;


	for (auto& pair : nodes) {
		all.insert(pair.second);
	}

	
	while (!all.empty()) {
		Node* current = *all.begin();
		if (hasCycle(current, all, visiting, visited)) {
			return true;
		}
	}
	return false;
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
    graph.PrintAdjacencyList();
    graph.Dfs("A");




    Graph graph2;

    graph2.AddNode("X");
    graph2.AddNode("A");
    graph2.AddNode("B");
    graph2.AddNode("P");
    

    graph2.AddEdge("X", "A");
    graph2.AddEdge("X", "B");
    graph2.AddEdge("A", "P");
    graph2.AddEdge("B", "P");
  

    vector<string> sortedOrder = graph2.topologicalSort();

    cout << "Topological Sort Order: ";
    for (const string& node : sortedOrder) {
        cout << node << " ";
    }
    cout << endl;




    Graph graph3;

    // Add nodes
    graph3.AddNode("A");
    graph3.AddNode("B");
    graph3.AddNode("C");
    graph3.AddNode("D");

    // Add directed edges (create a cycle)
    graph3.AddEdge("A", "B");
    graph3.AddEdge("B", "C");
    graph3.AddEdge("C", "A"); // Cycle: A -> B -> C -> A

    // Check if the graph has a cycle
    if (graph3.hasCycle()) {
        cout << "The graph contains a cycle." << endl;
    } else {
        cout << "The graph does not contain a cycle." << endl;
    }

    return 0;
}

