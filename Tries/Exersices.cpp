//class node -> value=string  childrent=int[26] index = aski(char) - 97

#include <iostream>
#include <string>
using namespace std;

class Trie
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
        for(auto it = value.begin(); it != value.end(); ++it)
        {
            bool isLastIteration = (it + 1 == value.end());
            int index = int(*it) - 97;


            if(!isInTrie(index,current)){
              Node* newNode = new Node(*it);
              current->children[index] = newNode;
              current = current->children[index];
              if(isLastIteration)
               current->isEndOfWord = true;
            }else{
              current = current->children[index];
            }
        }   
    }


};










int main()
{

    Trie *trie = new Trie();
    trie->insert("ali");
    cout<<"done";


    return 0;
}