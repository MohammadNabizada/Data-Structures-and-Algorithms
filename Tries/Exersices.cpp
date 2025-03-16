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
      bool isEmpty() {
        for (int i = 0; i < 26; i++) {
            if (children[i] != nullptr) {
                return false;
            }
        }
        return true;
    }
 
      void removeChild(Node* node, char ch) {
        int index = ch - 'a'; // Map character to index
        if (node->children[index] != nullptr) {
            delete node->children[index]; // Free memory
            node->children[index] = nullptr; // Set pointer to null
        }
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

    void remove(Node* root, string word, int index) {
        // Base case: If we've processed the entire word
        if (index == word.length()) {
            // Unmark the end-of-word flag
            root->isEndOfWord = false;
            return;
        }
    
        // Ensure index is within bounds
        if (index < 0 || index >= word.length()) {
            return; // Invalid index, do nothing
        }
    
        // Get the current character
        char ch = word[index]; // Use [] instead of at() for efficiency
        int childIndex = ch - 'a'; // Map character to index
    
        // Check if the child node exists
        Node* child = root->children[childIndex];
        if (child == nullptr) {
            return; // Word doesn't exist in the Trie
        }
    
        // Recursively process the next character
        remove(child, word, index + 1);
    
        // If the child node is no longer part of any word, delete it
        if (!child->isEndOfWord && child->isEmpty()) {
            root->removeChild(root, ch); // Remove the child node
        }
    }
    
    Node* findLastNodeOf(string prefix)
    {
        Node* current = root;
        for(const auto& ch : prefix)
        {
          Node* child = current->getChild(ch);
          if(child == nullptr)
             return nullptr;
          current = child;
        }
        return current;
    }
    void findWords(Node* root,const string &prefix,vector<string> &words)
    {
        if(root == nullptr)
          return;
        if(root->isEndOfWord)
          words.push_back(predix);
        
        for(const auto& child : root->getChildren())
        {
            findWords(child,prefix + child->charecter, words);
        }
    }
    public:
    vector<string> findWords(string prefix)
    {
          vector<string> words;
          Node* lastNode = findLastNodeOf(prefix);
          findWords(lastNode,prefix,words);
          return words;
    }
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
    trie->insert("car");
    trie->insert("care");
    trie->insert("carefull");
    trie->insert("carlos");
    trie->traversal();
    cout<<endl;
    trie->remove("mohammad");
    cout<<"find mohammad : "<<(trie->contains("mohammad") ? "YES" : "NO");
    string prefix = "car";
    vector<string> words = trie->findWords(prefix);
    
    cout << "Words with prefix '" << prefix << "':" << std::endl;

    for(const auto& word: words)
    {
        cout<<word<<endl;
    }


    return 0;
}