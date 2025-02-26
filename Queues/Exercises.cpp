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
        if(stack1.empty() && stack2.empty())
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
   

   QueueStack *queueS = new QueueStack;
   queueS->enqueue(1);
   queueS->enqueue(2);
   queueS->enqueue(3);

  std::cout<<queueS->dequeue();



    return 0;
}