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
    
    tree->traversalPreOrder();


    return 0;
}