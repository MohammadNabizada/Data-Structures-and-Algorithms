#include <iostream>
#include <string>
#include <unordered_map>
#include <list>
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

      Edge(weight): weight(weight){}

    };
   unordered_map<string,Node*> nodes;
   unordered_map<Node*,list<Node*>> adjacancyList;

   public:


};

int main()
{



    return 0;


}