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




    return 0;
}