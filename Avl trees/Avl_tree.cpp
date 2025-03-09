#include <iostream>
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
    Node(int value)
    {
      this->value = value;
      leftchild = nullptr;
      rightchild = nullptr;
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
    setHieght(root);
    return Balance(root);
  }

  Node *Balance(Node *root)
  {
    if (isLeftHeavy(root))
    {
      if (Balancefactor(root->leftchild) < 0)
      {
        root->leftchild = (root->leftchild);
      }
      return rotateRight(root);
    }
    else if (isRighttHeavy(root))
    {
      Node *newRoot = root->rightchild;
      if (Balancefactor(root->rightchild) > 0)
      {
        root->rightchild = rotateRight(root->rightchild);
      }
      return rotateLeft(root);
    }
    return root;
  }

  Node *rotateLeft(Node *root)
  {
    Node *newRoot = root->rightchild;
    root->rightchild = newRoot->leftchild;
    newRoot->leftchild = root;
    setHieght(root);
    setHieght(newRoot);

    return newRoot;
  }
  Node *rotateRight(Node *root)
  {
    Node *newRoot = root->leftchild;
    root->leftchild = newRoot->rightchild;
    newRoot->rightchild = root;
    setHieght(root);
    setHieght(newRoot);

    return newRoot;
  }

  void setHieght(Node *node)
  {
    node->height = max(height(node->leftchild), height(node->rightchild)) + 1;
  }

  int Balancefactor(Node *node)
  {
    return (node == nullptr) ? 0 : height(node->leftchild) - height(node->rightchild);
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