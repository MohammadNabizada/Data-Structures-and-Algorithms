#include <iostream>
#include <queue>
#include <stack>
//Adding a new method to queue built-in class in cpp
template <typename T>
class CustomQueue : public std::queue<T>
{
  public:
    void reverse()
    {
        std::stack<T> stack;
        while(!this->empty())
        {
            stack.push(this->front());
            this->pop();
        }
        while(!stack.empty())
        {
            int pu = stack.top();
            this->push(pu);
            stack.pop();
        }
    }
    void printQueue() {
        std::queue<T> tempQueue = *this;
        while (!tempQueue.empty()) {
            std::cout << tempQueue.front() << " ";
            tempQueue.pop();
        }
        std::cout << std::endl;
    }
};
class ArrayQueue
{
 private:
  int *items;
  int rear = 0;
  int count = 0;
  int length;
  int front = 0;
 public:
   ArrayQueue(int capacity)
   {
    items = new int[capacity];
    length = capacity;
   }
 void enqueue(int item)
 {
  if(count == length)
      throw std::invalid_argument("queue is full");
  items[rear] = item;
  rear = (rear + 1) % length;
  count++;
 }

 int dequeue()
 {
   int item = items[front];
   items[front] = 0;
   front = (front + 1) % length;
   count--; 
   return item;
 }
 int peek()
 {
    int item = items[front];
    return item;
 }
 void reverser(int kth)
 {
    int fr = front;
    int swap;
    for(int i = kth - 1; i >= 0; i--)
    {
        swap = items[fr];
        items[fr++] = items[i];
        items[i] = swap;
    }
 }
};

class QueueWithLinkedlist
{
  private:
  class Node{
    public:
    Node *next;
    int value;
    Node(int value)
    {
      this->value = value;
    }
  };
  Node *front = nullptr;
  int sizel = 0;
  public:
  void enqueue(int item)
  {
    Node *node = new Node(item);
    Node *current;
    if(isEmpty())
    {
      front = current = node;
      node->next = nullptr;
    }
    current->next = node;
    sizel++;
  }
  int dequeue()
  {
    if(isEmpty())
      throw std::invalid_argument("queue is empty");
    int pop = front->value;
    front = front->next;
    sizel--;
    return pop;
  }
  bool isEmpty()
  {
    return front == nullptr;
  }
  int peek()
  {
    if(isEmpty())
      throw std::invalid_argument("queue is empty");
    int pop = front->value;
    return pop;
  }
  int size()
  {
    int len = sizel;
    return len;
  }
 

};
//implementation a queue with a stack
class QueueStack
{
    private:

    std::stack<int> stack1;
    std::stack<int> stack2;

    public:
    void enqueue(int item)
    {
        stack1.push(item);
    }
    int dequeue()
    {
        if(isEmpty())
          throw std::invalid_argument("queue is empty");
        if(stack2.empty())
        {
          while(!stack1.empty()){
            stack2.push(stack1.top());
            stack1.pop();
          }
        }
        int pop = stack2.top();
        stack2.pop();
        return pop;    
    }

    bool isEmpty()
    {
       return stack1.empty() && stack2.empty();
    }

    int peek()
    {
        if(isEmpty())
        throw std::invalid_argument("queue is empty");
        moveStack1toStack2();
        int pop = stack2.top();
        return pop;
    }
    void moveStack1toStack2()
    {
        if (stack2.empty())
        {
            while (!stack1.empty())
            {
                stack2.push(stack1.top());
            }
        }
    }
};


class priorityQ{

    private:
    int *items = new int[5];
    int count = 0;
    int length = 5;
    public:

    void add(int item)
    {

        if(isFull())
          throw std::invalid_argument("queue is full");
      int i = shiftItemsToInsert(item);
      items[i] = item;
      count++;
    }
    int shiftItemsToInsert(int item)
    {
        int i;
        for (i = count - 1; i >= 0; i--)
        {
            if (items[i] > item)
                items[i + 1] = items[i];
            else
                break;
        }
        return i + 1;
    }
    bool isFull()
    {
        return count == length;
    }
    int remove()
    {
        if(isEmpty())
         throw std::invalid_argument("queue is empty");
        return items[--count];
    }

    bool isEmpty()
    {
        return count == 0;
    }


};


class StackWith2Queues
{
  private:
   std::queue<int> queue1;
   std::queue<int> queue2;

  public:

   void push(int item)
   {

    queue2.push(item);

    while(!queue1.empty())
    {
      queue2.push(queue1.front());
      queue1.pop();
    }


    std::swap(queue1,queue2);
   }

};


int main()
{
    CustomQueue<int> queue;
    queue.push(10);
    queue.push(20);
    queue.push(30);
    queue.push(40);
    queue.push(50);

    std::cout << "Queue elements: ";
    queue.printQueue();
    queue.reverse(); 
    std::cout << "Queue elements: ";
    queue.printQueue();

   ArrayQueue *my_queue = new ArrayQueue(5);
   my_queue->enqueue(10);
   my_queue->enqueue(20);
   my_queue->enqueue(30);
   my_queue->dequeue();


   my_queue->enqueue(10);
   my_queue->reverser(1);

   QueueStack *queueS = new QueueStack;
   queueS->enqueue(1);
   queueS->enqueue(2);
   queueS->enqueue(3);

  std::cout<<queueS->dequeue();

  std::cout<<std::endl;
  priorityQ *queuep = new priorityQ;
  queuep->add(1);
  queuep->add(3);
  queuep->add(2);
  queuep->add(6);
  queuep->add(4);

 while (!queuep->isEmpty())
 {
    std::cout<<queuep->remove()<<std::endl;
 }
 delete queuep;

 std::cout<<"this is a queue with linked list"<<std::endl;

 QueueWithLinkedlist *lqueue = new QueueWithLinkedlist;

 lqueue->enqueue(1);
 lqueue->enqueue(2);
 lqueue->enqueue(3);
 lqueue->enqueue(4);
 std::cout<<lqueue->peek();


 StackWith2Queues stackQueue;

  return 0;
}