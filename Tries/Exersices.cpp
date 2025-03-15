//class node -> value=string  childrent=int[26] index = aski(char) - 97

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class TrieArray
{
  private:
    class Node
    {
      public:
      char charecter;
      Node *children[26];
      bool isEndOfWord;
      Node(char ch) : children{nullptr},charecter(ch),isEndOfWord(false){}

      bool hasChild(char ch)
      {
        int index = int(ch) - 97;
        return children[index] != nullptr;
      }
      void addChild(char ch)
      {
        int index = int(ch) - 97;
        Node* newNode = new Node(ch);
        children[index] = newNode;
      }

      Node* getChild(char ch)
      {
        int index = int(ch) - 97;
        return children[index];
      }
      vector<Node*> getChildren()
      {
         vector<Node*> childNodes;
         for(int i=0;i < 26;i++)
         {
            childNodes.push_back(children[i]);
         }
         return childNodes;
      }


      bool threisChild()
      {
          for(int i = 0; i < 26;i++)
          {
            if(children[i] != nullptr)
              return true;
          }
          return false;
      }
    };

 

    Node *root;

    void traversal(Node* node)
    {
         if(node == nullptr)
           return;

         cout<<node->charecter;
         for(const auto& child: node->getChildren())
         {
                traversal(child);
         }
    }

    void remove(Node* root, string word,int index)
    {
        if(index == word.length()){
          cout<<root->charecter;
          return;
        }

         char ch = word.at(index);
         Node* child = root->getChild(ch);
         if(child == nullptr)
           return;
         remove(child,word,index + 1);
         cout<<root->charecter;
    }
    public:

    void insert(string value)
    {    
        if(root == nullptr)
           root = new Node(' ');
        Node* current = root;

        for(const auto& ch : value)
        {
            if(ch != ' '){
           
            if(!current->hasChild(ch)){
                current->addChild(ch);
            }
              current = current->getChild(ch);
        } 
        }  
        current->isEndOfWord = true;
    }

    bool contains(string value)
    {
        if(value == "")
          return false;
        Node* current = root;
        for(const auto& ch : value)
        {
           if(!current->hasChild(ch))
              return false;
            current = current->getChild(ch); 
        }
        return current->isEndOfWord == true;
    }

    void traversal()
    {
        traversal(root);
    }


    void remove(string word)
    {
        
        remove(root,word,0);
    }



};


class TrieHashmap {
    private:
        class Node {
        public:
            char character; 
            unordered_map<char, Node*> children; 
            bool isEndOfWord;
    
         
            Node(char ch) : character(ch), isEndOfWord(false) {}
    
            bool hasChild(char ch) const {
                return children.find(ch) != children.end();
            }
    
          
            void addChild(char ch) {
                children[ch] = new Node(ch);
            }
    
            
            Node* getChild(char ch) {
                return children[ch];
            }
        };
    
        Node* root;
    
    public:
   
        TrieHashmap() : root(nullptr) {}
    
        void insert(const string& value) {
            if (root == nullptr) {
                root = new Node(' ');
            }
            Node* current = root;
    
            for (const auto& ch : value) {
                if (ch != ' ') {
                    if (!current->hasChild(ch)) {
                        current->addChild(ch); 
                    }
                    current = current->getChild(ch); 
                }
            }
            current->isEndOfWord = true; 
        }
    };

int main()
{

    TrieArray *trie = new TrieArray();
    trie->insert("alimohammad");
    trie->insert("mohammad");
    trie->traversal();
    cout<<endl;
    trie->remove("mohammad");
    cout<<"find ali : "<<(trie->contains("mohammad") ? "YES" : "NO");


   


    return 0;
}