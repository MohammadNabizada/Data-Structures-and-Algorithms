#include <iostream>
#include <vector>
using namespace std;

class Bubblesort
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

  Bubblesort(int length){
    this->length = length;
  }


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

class InsertionSort
{
    private:
    int length;

    public:
    InsertionSort(int length):length(length){}

    void sort(int array[])
    {
         for(int i = 1; i < length;i++)
         {
            int current = array[i];
            int j = i - 1;
            while(j >= 0 && array[i] > current)
            {
              array[j+1] = array[j];
              j--;
            }
            array[j+1] = current;
         }

    }
};


class MergeSort
{
  private:
  int length;


  void merge(int array[] left,int array[] right,int array[] result)
  {
     int i = 0, j = 0, k = 0;
     
  }
  public:

  MergeSort(int length): length(length){}
  void sort(int array[])
  {
   int middle = length / 2;
   int *left = new int[middle];

   for(int i = 0; i < middle;i++)
      left[i] = array[i];

      int *right = new int[length - middle];
      for(int i = middle; i < length; i++)
        right[i - middle] = array[i];

       sort(left);
       sort(right);

  }



};


int main()
{

    int array[5] = {1,4,2,7,3};

    Bubblesort bublesort(5);
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

    int array3[5] = {1,4,2,7,3};
    InsertionSort insertionsort(5);
    insertionsort.sort(array3);

    for(int i =0; i < 5;i++)
    {
     cout<< array3[i];
    }
    return 0;
}