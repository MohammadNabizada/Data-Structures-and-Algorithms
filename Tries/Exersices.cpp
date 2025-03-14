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
      Node children[26];
      bool isEndOfWord;
      Node(char charecter)
      {
        this->charecter = charecter;
        this->isEndOfWord = false;
      }
    };

    Node *root;
    public:

  


};










int main()
{





    return 0;
}