#include <iostream>
#include <math.h>
using namespace std;
class Heap
{
   private:
     int *items;
     int size = 0;
     int capacity;



     void swap(int first,int seccond)
     {
         int temp = items[first];
         items[first] = items[seccond];
         items[seccond] = temp;
     }
     int getParentIndex(int index)
     {
      return (index-1)/2;
     }
     void bubbleUp(int index)
     {
      while(index > 0 && items[index] > items[getParentIndex(index)])
      {
           swap(index, getParentIndex(index));
           index = getParentIndex(index);
      } 
     }
    bool isLeaf(int value)
    {
      for(int i = 0;i < size;i++)
      {
        if(value == items[i]){
           return items[(i*2)+1]&&items[(i*2)+2];
        }
      }
      return false;
    }
    int leftChildIndex(int index)
    {
      return index * 2 + 1;
    }
    int rightChildIndex(int index)
    {
      return index * 2 + 2;
    }
    int leftChild(int index)
    {
      return items[leftChildIndex(index)];
    }
    int rightChild(int index)
    {
      return items[rightChildIndex(index)];
    }
    bool ifValidParent(int index)
    {
      if(!hasLeftChild(index))
        return true;
      bool isValid = items[index] >= leftChild(index);
      if(hasLeftChild(index))
         isValid &= items[index] >= rightChild(index);
      return isValid;
    }
    int largerChildIndexf(int index)
    {
      if(!hasLeftChild(index))
        return index;
      if(!hasRightChild(index))
        return leftChildIndex(index);
      return (leftChild(index) > rightChild(index)) ? leftChildIndex(index) :  rightChildIndex(index);
    }
   

    bool hasLeftChild(int index)
    {
      return leftChildIndex(index) <= size;
    }
    bool hasRightChild(int index)
    {
      return rightChildIndex(index) <= size;
    }


    void bubbleDown()
    {
      int index = 0;
      while(index <=size && !ifValidParent(index))
      {
       int largerChildIndex = largerChildIndexf(index);
       swap(index, largerChildIndex);
       index = largerChildIndex;
      }
    }
   public:
   bool isEmpty()
   {
     return size == 0;
   }
   bool isFull()
   {
    return size == capacity;
   }
   Heap(int capacity = 10) : size(0), capacity(capacity) {
    items = new int[capacity];
   }

   ~Heap() {
    delete[] items;
   }
 
   void insert(int value)
   {
    if(isFull())
      throw invalid_argument("Heap is full!");
    items[size++] = value;
    bubbleUp(size-1);
   }
   int remove()
   {
    if(isEmpty())
      throw invalid_argument("The heap is empty");
    int root = items[0];
    items[0] = items[--size];
    bubbleDown();
    return root;
   }
};


class PriorityQueuewithHeap{

 private:
   Heap *heap = new Heap();
 public:

  void enqueue(int item)
  {
     heap->insert(item);
  }

  int dequeue()
  {
   return heap->remove();
  }
  bool isEmpty()
  {
    return heap->isEmpty();
  }
};

class maxHeap{
    private:
    static void heapify(int array[],int size,int index)
    {
      int largerIndex = index;
      int leftIndex = index * 2 + 1;
      int rightIndex = index * 2 + 2;
      if(leftIndex < size && array[leftIndex] > array[largerIndex])
          largerIndex = leftIndex;
      if(rightIndex < size && array[rightIndex] > array[largerIndex])
          largerIndex = rightIndex;
      if(index == largerIndex)
          return;
      swap(array,index,largerIndex);
      heapify(array,6,largerIndex);
    }

    static void swap(int array[],int first,int seccond){
      int temp = array[first];
      array[first] = array[seccond];
      array[seccond] = temp;
    }
    public:
    static void heapify(int array[],int size)
    {
      for(int i = 0;i < size;i++)
      {
        heapify(array,6,i);
      }
    }


};



int main()
{
   Heap *heap = new Heap();
   heap->insert(10);
   heap->insert(5);
   heap->insert(17);
   heap->insert(4);
   heap->insert(22);
   heap->remove();
   delete heap; 
   int array[6] = {5,3,10,1,4,2};
   Heap *heap2 = new Heap();

   for(const auto& num: array)
    heap2->insert(num);
  
    for(int i = 0;i<6;i++)
    {
      array[i] = heap2->remove();
      cout<<array[i];
    }
    PriorityQueuewithHeap *queue = new PriorityQueuewithHeap();
    queue->enqueue(5);
    queue->enqueue(3);
    queue->enqueue(10);
    queue->enqueue(1);
    queue->isEmpty();
    cout<<endl;
    int numbers[6] =  {5,3,8,4,1,2};

    maxHeap::heapify(numbers,6);
    for(int num: numbers)
     cout<<num<<endl;
    return 0;
}