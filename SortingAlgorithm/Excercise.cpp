#include <iostream>
#include <vector>
using namespace std;

class Bublesort
{
  private:
   int length;
   void swap(int array[],int index1,int index2)
   {
     int temp = array[index1];
     array[index1] = array[index2];
     array[index2] = temp;
   }
  public:

  Bublesort(int length) : length(length){}


  void sort(int array[])
  {
    bool isSorted;
   for(int i = 0; i < length;i++)
   {
    isSorted = true;
    for(int j = 1;j < length - i;j++)
    {
        if(array[j] < array[j-1])
          {
            swap(array,j,j-1);
            isSorted = false;
          }
    }
    if(isSorted == true)
      return;
   }
  }



};

class SelectionSort{
  private:
  int length;
  void swap(int array[],int index1,int index2)
  {
    int temp = array[index1];
    array[index1] = array[index2];
    array[index2] = temp;
  }

  int findMinIndex(int array[],int minIndex)
  {
    for(int j = minIndex;j< length;j++)
    {
     if(array[j] < array[minIndex])
       minIndex = j;
    }
    return minIndex;
  }

  public:

  SelectionSort(int length): length(length){}
  void sort(int array[])
  {
    
   for(int i = 0;i < length;i++)
   {
   swap(array,findMinIndex(array,i),i);
   }

  }


};




int main()
{

    int array[5] = {1,4,2,7,3};

    Bublesort bublesort(5);
    bublesort.sort(array);
    for(int i =0; i < 5;i++)
    {
     cout<< array[i];
    }
    int array2[5] = {1,4,2,7,3};
    SelectionSort selectionsort(5);
    selectionsort.sort(array2);

    for(int i =0; i < 5;i++)
    {
     cout<< array2[i];
    }

    return 0;
}