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
      bool isEmpty()
      {
         return first == nullptr; 
      }
    public:
      void addLast(int item)
      {
        Node *node = new Node(item);
        
        if (isEmpty())
            first = last = node;
        else{
            last->next = node;
            last = node;
            last->next = nullptr;
        }


      }

      void addFirst(int item)
      {
        Node *node = new Node(item);

        if (isEmpty())
           first = last = node;
        else{
            node->next = first;
            first = node;
        }
      }
    int indexOf(int item)
    {
         int index = 0;
         Node* current = first;
         while(current->next != nullptr)
         {
            if(current->value == item){ 
              return index;
            }
            index++;
            current = current->next;
         }
         return -1;
    }
};


int main()
{
    LinkedList *list = new LinkedList();
    list->addLast(10);
    list->addLast(20);
    list->addLast(30);
    std::cout<<list->indexOf(20);
    delete list;

    return 0;
}