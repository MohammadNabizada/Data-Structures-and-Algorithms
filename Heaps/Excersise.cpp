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
     int *items = new int[10];
     int size = 0;

     void swap(int first,int seccond)
     {
         int temp = items[first];
         items[first] = items[seccond];
         items[seccond] = temp;
     }
     int getParentIndex(int index)
     {
      return ceil((index-1)/2);
     }
   public:
     int count = 0;

   void insert(int value)
   {
    items[size++] = value;
    int index = size -1;
    while(items[index] > items[getParentIndex(index)])
    {
         swap(index, parentIndex);
         index = getParentIndex(index);
    } 
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