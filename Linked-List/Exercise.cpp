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
    bool contains(int item)
    {
        return indexOf(item) != -1;
    }
    void removeFirst()
    {
        if(isEmpty())
          throw std::invalid_argument("The list is empty.");
        
        if(first == last)
        {
            first = last = nullptr;
            return;
        }
        Node* second = first->next;
        first->next = nullptr;
        first = second;
    }
};


int main()
{
    LinkedList *list = new LinkedList();
    list->addLast(10);
    list->addLast(20);
    list->addLast(30);
    list->addLast(40);
    list->addLast(50);
    std::cout<<list->indexOf(20);
    std::cout<<std::endl;
    std::cout<<list->contains(10);
    list->removeFirst();
    delete list;

    return 0;
}