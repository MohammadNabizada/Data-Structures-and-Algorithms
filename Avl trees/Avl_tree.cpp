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
         int height;

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
  bool isleaf(Node *node)
  {
     return node->leftchild == nullptr && node->rightchild == nullptr;
  }
  int height(Node *root)
  {
    if(root == nullptr)
      return -1;
    if(isleaf(root))
      return 0;
    return std::max(height(root->leftchild),height(root->rightchild)) + 1;
  }

  void height()
  {
   height = height(root);
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
    tree->insert(1);
    tree->insert(6);
    tree->insert(8);
    tree->insert(10);


    return 0;
}