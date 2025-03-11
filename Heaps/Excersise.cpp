
//remove(int)
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
      return items[index] >= leftChild(index) && items[index] >= rightChild(index);
    }
    int largerChildIndex(int index)
    {
      return (leftchild(index) > rightChild(index)) ? leftChildIndex(index) :  rightChildIndex(index);
    }
    bool isEmpty()
    {
      return size == 0;
    }
   public:
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

   void remove()
   {
    if(isEmpty())
      throw invalid_argument("The heap is empty");
    items[0] = items[--size];

    int index = 0;
    while(index <=size && !ifValidParent())
    {
     int largerChildIndex = largerChildIndex(index);
     swap(index, largerChildIndex);
     index = largerChildIndex;
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
   delete heap; 
 cout<<"done";


    return 0;
}