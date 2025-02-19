#include <iostream>

class LinkedList
{

    private:
     class Node
      {
         public:
         int value;
         Node *next;
         Node(int value){
            this->value = value;
         }
      };
      Node *first;
      Node *last;
   
    public:
      void addLast(int item)
      {
        Node *node = new Node(item);
        
        if (first == nullptr)
            first = last = node;
        else{
            last->next = node;
            last = node;
        }


      }

};


int main()
{
    LinkedList *list = new LinkedList();
    list->addLast(10);
    list->addLast(20);
    list->addLast(30);
    return 0;
}