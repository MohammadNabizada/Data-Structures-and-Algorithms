#include <iostream>
#include <math.h>

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
        leftchild = nullptr;
        rightchild = nullptr;
      }
    };
    Node* root;
    void traversalPreOrder(Node *root)
    {
         if(root == nullptr)
          return;
         std::cout<<root->value<<",";
         traversalPreOrder(root->leftchild);
         traversalPreOrder(root->rightchild);
    }
    void traversalInorder(Node *root)
    {
     if(root == nullptr)
      return;
     traversalInorder(root->leftchild);
     std::cout<<root->value<<",";
     traversalInorder(root->rightchild);
    }

    void traversalPostorder(Node *root)
    {

        if(root == nullptr)
          return;

        traversalPostorder(root->leftchild);
        traversalPostorder(root->rightchild);
        std::cout<<root->value<<",";
    }
    int hight(Node *root)
    {
        if(root->leftchild == nullptr && root->rightchild == nullptr)
        return 0;
        return 1 + std::max(hight(root->leftchild),hight(root->rightchild));
    }
    public:
    void insert(int value)
    {
      Node* node = new Node(value);
      if(root == nullptr)
      {
        root = new Node(value);
        return;
      }
      Node* current = root;

      while(true)
      {
        if(value < current->value){
          if(current->leftchild == nullptr){
            current->leftchild = node;
            break;
          }
          current = current->leftchild;

        }
        else{
        
          if(current->rightchild == nullptr){
            current->rightchild = node;
            break;
          }

          current = current->rightchild;
        }
      } 
    }

    bool find(int value)
    {
        Node* current = root;
        while(current != nullptr)
        {
          if(value < current->value)
            current = current->leftchild;
          else if(value > current->value)
            current = current->rightchild;
          else 
            return true;
        }

          return false;
        }
   
    void traversalPreOrder(){
        traversalPreOrder(root);
    }
    void traversalInorder(){
        traversalInorder(root);
    }

    void traversalPostorder(){
        traversalPostorder(root);
    }
    int hight()
    {
        hight(root);
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
    std::cout<<"find 3:"<<tree->find(17)<<std::endl;
    std::cout<<"PreOrder Traversal:";
    tree->traversalPreOrder();
    std::cout<<std::endl;
    std::cout<<"Inorder Traversal:";
    tree->traversalInorder();
    std::cout<<std::endl;
    std::cout<<"Postorder Traversal:";
    tree->traversalPostorder();
    std::cout<<std::endl;
    std::cout<<"hight of tree:"<<tree->hight();

    return 0;
}