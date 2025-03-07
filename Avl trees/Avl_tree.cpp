#include <iostream>
using namespace std;


class Avltree
{
  private:
    class Node{
         public :
         int value;
         Node* leftchild;
         Node* rightchild;

         Node(int value)
         {
            this->value = value;
            leftchild = nullptr;
            rightchild = nullptr;
         }
    };

    Node *root = nullptr;
  Node* insert(int value,Node* root)
  {
    if(root == nullptr)
      return new Node(value);
    if(value < root->value)
    {
      root->leftchild = insert(value,root->leftchild);
    }else{
      root->rightchild = insert(value,root->rightchild);
    }
    return root;
  }
  public:
  void insert(int value)
  {
    root = insert(value,root);
  }



};



int main()
{

    Avltree *tree = new Avltree();
    tree->insert(7);
    tree->insert(4);
    tree->insert(9);
    cout<<"finish";


    return 0;
}