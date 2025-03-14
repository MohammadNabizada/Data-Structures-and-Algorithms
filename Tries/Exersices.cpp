//class node -> value=string  childrent=int[26] index = aski(char) - 97

#include <iostream>
#include <string>
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
            int index = int(ch) - 97;
            if(!isInTrie(index,current)){
              Node* newNode = new Node(ch);
              current->children[index] = newNode;
            }
              current = current->children[index];
        } 
        }  
        current->isEndOfWord = true;
    }


};










int main()
{

    TrieArray *trie = new TrieArray();
    trie->insert("ali");
    cout<<"done";


    return 0;
}