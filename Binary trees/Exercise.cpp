#include <iostream>
#include <math.h>
#include <algorithm>
class Tree
{
private:
  class Node
  {
  public:
    int value;
    Node *leftchild;
    Node *rightchild;

    Node(int value)
    {
      this->value = value;
      leftchild = nullptr;
      rightchild = nullptr;
    }
  };

  Node *root;
  void traversalPreOrder(Node *root)
  {
    if (root == nullptr)
      return;
    std::cout << root->value << ",";
    traversalPreOrder(root->leftchild);
    traversalPreOrder(root->rightchild);
  }
  void traversalInorder(Node *root)
  {
    if (root == nullptr)
      return;
    traversalInorder(root->leftchild);
    std::cout << root->value << ",";
    traversalInorder(root->rightchild);
  }

  void traversalPostorder(Node *root)
  {

    if (root == nullptr)
      return;

    traversalPostorder(root->leftchild);
    traversalPostorder(root->rightchild);
    std::cout << root->value << ",";
  }
  int height(Node *root)
  {
    if (root == nullptr) // Base case: empty tree
      return -1;
    if (isLeaf(root)) // Base case: leaf node
      return 0;
    return 1 + std::max(height(root->leftchild), height(root->rightchild)); // Recursive case
  }

  int min(Node *root)
  {
    if (root == nullptr)                             // Base case: empty tree
      throw std::invalid_argument("Tree is empty."); // Handle empty tree case
    if (isLeaf(root))                                // Base case: leaf node
      return root->value;

    // Recursive case: find the minimum value in the left and right subtrees
    int left = (root->leftchild != nullptr) ? min(root->leftchild) : root->value;
    int right = (root->rightchild != nullptr) ? min(root->rightchild) : root->value;

    return std::min({left, right, root->value});
  }
  bool isLeaf(Node *node)
  {
    if (node == nullptr) // Add null check
      return false;      // A null node is not a leaf
    return node->leftchild == nullptr && node->rightchild == nullptr;
  }
  bool equal(Node *first, Node *seccond)
  {
    if (first == nullptr && seccond == nullptr)
      return true;
    if (first != nullptr && seccond != nullptr)
      return first->value == seccond->value && equal(first->leftchild, seccond->leftchild) && equal(first->rightchild, seccond->rightchild);
    return false;
  }

  bool isBinarySearchTree(Node *root, int min, int max)
  {
    if (root == nullptr)
      return true;
    if (root->value < min || root->value > max)
      return false;
    return isBinarySearchTree(root->leftchild, min, root->value - 1) && isBinarySearchTree(root->rightchild, root->value + 1, max);
  }
  void kDistance(Node *root, int distance)
  {
    if (root == nullptr)
      return;
    if (distance == 0)
    {
      std::cout << root->value << ",";
      return;
    }
    kDistance(root->leftchild, distance - 1);
    kDistance(root->rightchild, distance - 1);
  }

  int countLeaves(Node *root)
  {
    if (root == nullptr)
      return 0;
    // base condition
    if (root->leftchild == nullptr && root->rightchild == nullptr)
      return 1;

    return countLeaves(root->leftchild) + countLeaves(root->rightchild);
  }
  int size(Node *root)
  {
    if (root == nullptr)
      return 0;
    if (root->leftchild == nullptr && root->rightchild == nullptr)
      return 1;
    return size(root->leftchild) + size(root->rightchild) + 1;
  }
  
  int max(Node *root)
  {
    //base condition
    if(root == nullptr)
      return -1;
    if(root->leftchild == nullptr && root->rightchild == nullptr)
      return root->value;
    return std::max({root->value,max(root->leftchild),max(root->rightchild)});
  }

  bool contains(Node *root,int item)
  {
    if(root == nullptr)
      return false;
    if(root->value == item)
      return true;
    return contains(root->leftchild,item) || contains(root->rightchild,item);
  }
 
public:


Node* findParent(Node* root,int value)
{
  if(root == nullptr || root->value == value)
     return nullptr;
  if((root->leftchild != nullptr && root->leftchild->value ==value) || (root->rightchild != nullptr && root->rightchild->value == value)){
    return root;
  }


  Node* leftParent = findParent(root->leftchild,value);
  if(leftParent != nullptr)
    return leftParent;
  return findParent(root->rightchild,value);
}


bool areSibling(int value1, int value2)
{
  if(root == nullptr || value1 == value2)
     return false;
  
  Node* parent1 = findParent(root,value1);
  Node* parent2 = findParent(root,value2);

  return (parent1 != nullptr && parent2 != nullptr && parent1 == parent2);
}



  void insert(int value)
  {
    Node *node = new Node(value);
    if (root == nullptr)
    {
      root = new Node(value);
      return;
    }
    Node *current = root;

    while (true)
    {
      if (value < current->value)
      {
        if (current->leftchild == nullptr)
        {
          current->leftchild = node;
          break;
        }
        current = current->leftchild;
      }
      else
      {

        if (current->rightchild == nullptr)
        {
          current->rightchild = node;
          break;
        }

        current = current->rightchild;
      }
    }
  }

  bool find(int value)
  {
    Node *current = root;
    while (current != nullptr)
    {
      if (value < current->value)
        current = current->leftchild;
      else if (value > current->value)
        current = current->rightchild;
      else
        return true;
    }

    return false;
  }

  void traversalPreOrder()
  {
    traversalPreOrder(root);
  }
  void traversalInorder()
  {
    traversalInorder(root);
  }

  void traversalPostorder()
  {
    traversalPostorder(root);
  }
  int height()
  {
    return height(root);
  }
  int min()
  {
    return min(root);
  }
  bool equal(Tree other)
  {
    if (other.root == nullptr)
      throw std::invalid_argument("tree can not be null");
    return equal(root, other.root);
  }

  bool isBinarySearchTree()
  {
    return isBinarySearchTree(root, INT_MIN, INT_MAX);
  }

  void swap()
  {
    Node *temp = root->leftchild;
    root->leftchild = root->rightchild;
    root->rightchild = temp;
  }
  void kDistance(int distance)
  {
    kDistance(root, distance);
  }
  void traverseLevelOrder()
  {
    if (root == nullptr)
    {
      std::cout << "Tree is empty." << std::endl;
      return;
    }

    int h = height(root); // Get the height of the tree
    for (int level = 0; level <= h; level++)
    {
      kDistance(root, level); // Process each level
    }
    std::cout << std::endl;
  }

  int size()
  {
    return size(root);
  }
  int countLeaves()
  {
    return countLeaves(root);
  }

  
  int max()
  {
    return max(root);
  }

  bool contains(int item)
  {
    return contains(root,item);
  }

};

int main()
{

  Tree *tree = new Tree();
  tree->insert(7);
  tree->insert(4);
  tree->insert(9);
  tree->insert(1);
  tree->insert(6);
  tree->insert(8);
  tree->insert(10);
  std::cout << "find 3:" << tree->find(17) << std::endl;
  std::cout << "PreOrder Traversal:";
  tree->traversalPreOrder();
  std::cout << std::endl;
  std::cout << "Inorder Traversal:";
  tree->traversalInorder();
  std::cout << std::endl;
  std::cout << "Postorder Traversal:";
  tree->traversalPostorder();
  std::cout << std::endl;
  std::cout << "hight of tree:" << tree->height();
  std::cout << std::endl;
  std::cout << "min:" << tree->min();

  Tree *tree2 = new Tree();
  tree2->insert(7);
  tree2->insert(4);
  tree2->insert(9);
  tree2->insert(1);
  tree2->insert(6);
  tree2->insert(8);
  tree2->insert(10);
  std::cout << std::endl;
  std::cout << "is equal tree1 and tree2:";
  std::cout << (tree->equal(*tree2) ? "Yes" : "No") << std::endl;
  std::cout << std::endl;
  std::cout << "is tree Binary search:";
  std::cout << (tree->isBinarySearchTree() ? "Yes" : "No") << std::endl;
  tree->swap();
  std::cout << "is tree Binary search after swaping:";
  std::cout << (tree->isBinarySearchTree() ? "Yes" : "No") << std::endl;
  std::cout << std::endl;
  std::cout << "node in k distance:";
  tree2->kDistance(3);
  std::cout << std::endl;
  std::cout << "Level order traversal:";
  tree2->traverseLevelOrder();
  std::cout << std::endl;
  std::cout << "Size of tree:";
  std::cout << tree->size();

  std::cout << std::endl;
  std::cout << "number of leaves:";
  std::cout << tree->countLeaves();

  std::cout << std::endl;
  std::cout << "maximum value in tree:";
  std::cout << tree->max();

  std::cout << std::endl;
  std::cout << "finding an item using contains method:";
  std::cout << (tree->contains(10) ? "YES" : "No")<<std::endl;


  std::cout << "Are 7 and 4 siblings? " << (tree->areSibling(7, 4) ? "Yes" : "No") << std::endl;
  return 0;
}