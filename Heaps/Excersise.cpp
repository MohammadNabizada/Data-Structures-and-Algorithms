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
   Heap heap;
   heap.insert(15);
   heap.insert(12); 
   heap.insert(9); 
   heap.insert(8); 
   heap.insert(10); 
   heap.insert(3); 
   heap.insert(4); 
   heap.insert(1);
   heap.insert(24); 
 cout<<"done";


    return 0;
}