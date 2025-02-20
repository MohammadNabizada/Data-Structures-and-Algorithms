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
      int size;
      bool isEmpty()
      {
         return first == nullptr; 
      }
      Node *getPrevious(Node* node)
      {
        Node* current = first;
        while(current != nullptr){
            if(current->next == node) return current;
            current = current->next;
        }
        return nullptr;
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

       size++;
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
        size++;
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
            first = last = nullptr;
        else{
        Node* second = first->next;
        first->next = nullptr;
        first = second;
        }
        size--;
    }
    void removeLast()
    {
     if(isEmpty())
     throw std::invalid_argument("list is empty.");
     if(first == last)
        first = last = nullptr;
    else{
     Node* previous =  getPrevious(last);
     last = previous;
     last->next = nullptr;
    }    
     size--;
    }
    int *toArray(){
      int *array = new int[size];
      Node* current = first;
      int index = 0;
      while(current != nullptr)
      {
        array[index++] = current->value;
        current = current->next;
      }
      return array;
    }

    int getSize()
    {
        return size;
    }

        void reverseList()
    {
      if(isEmpty()) return;
      
      Node*previous = first;
      Node*current = first->next;
      while(current != nullptr)
      {
        Node*next = current->next;
        current->next = previous;
        previous = current;
        current = next;
      }
      last = first;
      last->next = nullptr;
      first = previous;

    }
   // 1 -> 2 -> 3 -> 4 -> 5
      
    int getKthFromTheEnd(int k)
    {
      if (isEmpty())
        throw std::invalid_argument("list is empty");
      Node*a = first;
      Node*b = first;
      
      for(int i = 0; i < k -1 ;i++){
        b = b->next;
        if ( b == nullptr)
          throw std::invalid_argument("this is more than the size of linked list");
      }
      while(b != last)
      {
        a = a->next;
        b = b->next;
      }
       return a->value;
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
    //10 -> 20 -> 30 -> 40
    std::cout<<"kth from end"<<std::endl;
    std::cout<<list->getKthFromTheEnd(2)<<std::endl;

    std::cout<<"k'th element"<<std::endl;
    std::cout<<list->getKthFromTheEnd(1);
    std::cout<<list->indexOf(20);
    std::cout<<std::endl;
    std::cout<<list->contains(10);
    list->removeFirst();
    list->removeLast();
    list->reverseList();
    std::cout<<"kth element from the end";
    std::cout<<list->getKthFromTheEnd(2);
    std::cout<<std::endl;
    std::cout<<list->getSize();
    int *array = list->toArray();

    std::cout<<std::endl; 
    
    for (int i = 0; i < list->getSize(); ++i) {
        std::cout << array[i] << " ";
    }

    delete[] array;
    delete list;

    return 0;
}