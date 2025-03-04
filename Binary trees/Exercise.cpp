#include <iostream>


class Tree
{
   private:
    class Node{
      public:
      int value;
      Node* leftchild;
      Node* rightchild;

      Node(int value)
      {
        this->value = value;
      }
    };
    Node* root;

    public:
    void insert(int value)
    {
      if(root == nullptr)
      {
        root = new Node(value);
        return;
      } 
    }




};

int main()
{







    return 0;
}