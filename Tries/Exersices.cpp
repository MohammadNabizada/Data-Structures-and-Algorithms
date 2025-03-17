
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <stack>
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
       
        if (index == word.length()) {
            root->isEndOfWord = false;
            return;
        }
    
       
        if (index < 0 || index >= word.length()) {
            return;
        }
    
        char ch = word[index]; 
        int childIndex = ch - 'a';
    
       
        Node* child = root->children[childIndex];
        if (child == nullptr) {
            return; 
        }
    
       
        remove(child, word, index + 1);
    
        
        if (!child->isEndOfWord && child->isEmpty()) {
            root->removeChild(root, ch); 
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
        if(root == nullptr || prefix == "")
          return;
        if(root->isEndOfWord)
          words.push_back(prefix);
        
        for(const auto& child : root->getChildren())
        {
            if(child != nullptr)
              findWords(child,prefix + child->charecter, words);
        }
    }

    bool containsRecursively(string word,Node* root,int index)
   {
     if(root == nullptr)
       return false;
     
     if(index == word.length())
       return root->isEndOfWord;
     
     char ch = word[index];

     if(!root->hasChild(ch))
       return false;
     
     return containsRecursively(word,root->getChild(ch),index+1);
   }
    int countWords(Node* root)
    {
        if(root == nullptr)
         return 0;
        int count = 0;
        stack<Node*> stack;
        stack.push(root);

        while(!stack.empty())
        {
            Node* current = stack.top();
            stack.pop();

            if(current->isEndOfWord){
              count++;
            }
            
            for(int i = 0; i < 26;i++)
            {
                if(current->children[i] != nullptr) 
            {
                stack.push(current->children[i]);
            }
            }
        }
        return count;
     }


    int countRecursively(Node* root)
    {
        if(root == nullptr)
         return 0;
        
        int count = 0;

        if(root->isEndOfWord)
          count++;
        
        for(int i = 0; i < 26;i++)
        {
            if(root->children[i] != nullptr)
              count += countRecursively(root->children[i]);
        }
    
        return count;
    }


    string longestCommonPrefixHelper()
    {
        string prefix = "";
        Node* current = root;

        while(current != nullptr)
        {
            int childCount = 0;
            Node *childNode =  nullptr;
            char childChar = '\0';

            for(int i = 0; i < 26;i++)
            {
                if(current->children[i] != nullptr)
                {
                    childCount++;
                    childNode = current->children[i];
                    childChar = 'a' + i;
                }
            }

            if(childCount != 1)
              break;
            
            prefix += childChar;
            current = childNode;

            if (current->isEndOfWord) {
                break;
            }
        }
        return prefix;
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

    bool containsRecursively(string word)
    {
        return containsRecursively(word,root,0);
    }

    int countWords()
    {
        return countWords(root); 
    }

    int countRecursively()
    {
        return countRecursively(root);
    }

    string longestCommonPrefix(vector<string> words)
    {
          for(const auto& word: words)
          {
            insert(word);
          }
        return longestCommonPrefixHelper();
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

    cout<<"find carlos recursively : "<<(trie->containsRecursively("carlos") ? "YES" : "NO");
    cout<<endl;

    cout<<"Count of words in trie Iterative:"<< trie->countWords();
    cout<<endl;
    cout<<"Count of words in trie Recursively:"<< trie->countRecursively();
    cout<<endl;
     TrieArray *trie2 = new TrieArray();
    vector<string> word = {"car","care","carefull"};

    cout<<trie2->longestCommonPrefix(word);
    return 0;
}