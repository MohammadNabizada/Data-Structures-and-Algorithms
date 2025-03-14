//class node -> value=string  childrent=int[26] index = aski(char) - 97

#include <iostream>
#include <string>
#include <unordered_map>
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
    };

    Node *root;

    bool isInTrie(int index,Node* current)
    {
       return current->children[index] != nullptr;
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
    trie->insert("ali");
    trie->insert("alii");
    cout<<"done";


    return 0;
}