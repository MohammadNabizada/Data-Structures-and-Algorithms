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
  items[rear++] = item;
  count++;
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



    return 0;
}