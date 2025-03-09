#include <iostream>
#include <string.h>
using namespace std;


class Avltree
{
  private:
    class Node{
         public :
         int value;
         Node* leftchild;
         Node* rightchild;
         int height = 0;
         string isBalancedfactor;

         Node(int value)
         {
            this->value = value;
            leftchild = nullptr;
            rightchild = nullptr;
            isBalancedfactor = "";
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
    root->height = max(height(root->leftchild),height(root->rightchild)) + 1;
    if(height(root->rightchild)-height(root->leftchild) > 1)
      root->isBalancedfactor = "leftHeavy";
    else if(height(root->rightchild)-height(root->leftchild) < -1)
      root->isBalancedfactor= "rightHeavy";
       
    return root;
  }
  bool isleaf(Node *node)
  {
     return node->leftchild == nullptr && node->rightchild == nullptr;
  }
  int height(Node *node)
  {
   return (node == nullptr) ? -1 : node->height;
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
    tree->insert(15);
    tree->insert(14);
    tree->insert(13);
    tree->insert(2);


    return 0;
}