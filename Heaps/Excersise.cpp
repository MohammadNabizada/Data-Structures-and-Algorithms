//heap
//int[]
//insert(int)
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