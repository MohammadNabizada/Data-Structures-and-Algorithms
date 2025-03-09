#include <iostream>
#include <string.h>
using namespace std;

class Avltree
{
private:
  class Node
  {
  public:
    int value;
    Node *leftchild;
    Node *rightchild;
    int height = 0;
    string isBalancedfactor;
    string rotation;
    Node(int value)
    {
      this->value = value;
      leftchild = nullptr;
      rightchild = nullptr;
      isBalancedfactor = "Balanced";
      rotation = "";
    }
  };

  Node *root = nullptr;
  Node *insert(int value, Node *root)
  {
    if (root == nullptr)
      return new Node(value);
    if (value < root->value)
    {
      root->leftchild = insert(value, root->leftchild);
    }
    else
    {
      root->rightchild = insert(value, root->rightchild);
    }
    root->height = max(height(root->leftchild), height(root->rightchild)) + 1;
    
    root = Balance(root);
    
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
  bool isLeftHeavy(Node *node)
  {
    return Balancefactor(node) > 1;
  }
  bool isRighttHeavy(Node *node)
  {
    return Balancefactor(node) < -1;
  }

  int Balancefactor(Node *node)
  {
    return (node == nullptr) ? 0 : height(node->leftchild) - height(node->rightchild);
  }

  Node* Balance(Node *root)
  {
    if (isLeftHeavy(root)){
      root->isBalancedfactor = "leftHeavy";
      if(Balancefactor(root->leftchild) < 0)
        root->leftchild->rotation = "rightRotation";
      root->rotation = "LeftRotation";
    }
    else if (isRighttHeavy(root)){
      root->isBalancedfactor = "rightHeavy";

      Node* newRoot = root->rightchild;
      if(Balancefactor(root->rightchild) > 0){
        root->rightchild->rotation = "rightRotation";

        root->rightchild = newRoot->leftchild;
        root->rightchild->rightchild = newRoot;
        root->rightchild = height(root->rightchild);
        newRoot->height = height(newRoot);
      }
      root->rotation = "leftRotation";
      
      if(newRoot->leftchild == nullptr)
      {
        newRoot->leftchild = root;
      }else{
        root->rightchild = newRoot->leftchild;
      }
      root = newRoot;
      root->height = height(root);
      root->leftchild->height=height(root);
    }
    return root;
  }


public:
  void insert(int value)
  {
    root = insert(value, root);
  }



};

int main()
{

  Avltree *tree = new Avltree();
  tree->insert(10);
  tree->insert(20);
  tree->insert(30);

  return 0;
}