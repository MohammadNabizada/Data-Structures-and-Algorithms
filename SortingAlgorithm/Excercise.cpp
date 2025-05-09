#include <iostream>
#include <iterator>
#include <list>
#include <vector>
#include <algorithm> 
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

  void merge(int left[] ,int leftsize,int right[],int rightsize ,int result[])
  {
     int i = 0, j = 0, k = 0;
     while(i < leftsize && j < rightsize)
     {
       if(left[i] <= right[j])
         result[k++] = left[i++];
       else
         result[k++] = right[j++];
     }

     while(i < leftsize)
      result[k++] = left[i++];

     while(j < rightsize)
      result[k++] = right[j++];
      
      
  }
  public:


  void sort(int array[],int length)
  {

   if(length < 2)
     return;
     int middle = length / 2;
  
     int* left = new int[middle];
     int* right = new int[length - middle]; 
     
   
     for(int i = 0; i < middle; i++) {
         left[i] = array[i]; 
     }
     
     for(int i = middle; i < length; i++) {
         right[i - middle] = array[i]; 
     }
     
    
       sort(left,middle);
       sort(right,length - middle);

       merge(left,middle,right,length - middle,array);

       delete[] left;
       delete[] right;
  }



};


class QuickSort{
  private:
  void swap(int array[],int index1,int index2)
  {
    int temp = array[index1];
    array[index1] = array[index2];
    array[index2] = temp;
  }


  int partition(int array[],int length,int start,int end)
  {
   int pivot = array[end];
   int boundary = start-1;

   for(int i =start ; i <= end;i++)
   {
    if(array[i] <= pivot)
      swap(array,i,++boundary);
   }
   return boundary;
  }
  void sort(int array[],int length,int start,int end)
  {
   if(start >= end)
    return;
   int boundary = partition(array,length,start,end);

   sort(array,length,start,boundary-1);
   sort(array,length,boundary+1,end);
  }

  public:
  void sort(int array[],int length)
  {
    sort(array,length,0,length-1);
  }


};


class CountSort{


 public:
 void sort(int arr[], int size) {
  if (size <= 1) return;

  int max_val = arr[0];
  for (int i = 1; i < size; i++) {
      if (arr[i] > max_val) {
          max_val = arr[i];
      }
  }

  int* count = new int[max_val + 1](); 

  for (int i = 0; i < size; i++) {
      count[arr[i]]++;
  }

  for (int i = 1; i <= max_val; i++) {
      count[i] += count[i - 1];
  }

  int* output = new int[size];
  for (int i = size - 1; i >= 0; i--) {
      output[count[arr[i]] - 1] = arr[i];
      count[arr[i]]--;
  }

  for (int i = 0; i < size; i++) {
      arr[i] = output[i];
  }

  delete[] count;
  delete[] output;
}
};

class BucketSort {
  public:
      void sort(int array[], int length, int numberofBuckets) {
          if (length <= 0 || numberofBuckets <= 0) return;
  
          
          int min_val = array[0];
          int max_val = array[0];
          for (int i = 1; i < length; i++) {
              if (array[i] < min_val) min_val = array[i];
              if (array[i] > max_val) max_val = array[i];
          }
          if (min_val == max_val) return; 
  
        
          vector<vector<int>> buckets(numberofBuckets);
  
          
          float range = (max_val - min_val + 1) / (float)numberofBuckets;
          for (int i = 0; i < length; i++) {
              int bucket_idx = (array[i] - min_val) / range;
              buckets[bucket_idx].push_back(array[i]);
          }
  
       
          int index = 0;
          for (auto& bucket : buckets) {
              std::sort(bucket.begin(), bucket.end()); 
              for (int num : bucket) {
                  array[index++] = num; 
              }
          }
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

    cout<<endl;

    int array4[5] = {1,4,2,7,3};
    MergeSort mergesort;
    mergesort.sort(array4,5);

    for(int i =0; i < 5;i++)
    {
     cout<< array4[i];
    }

    int array5[5] = {1,4,2,7,3};
    QuickSort quicksort;
    quicksort.sort(array5,5);

    for(int i =0; i < 5;i++)
    {
     cout<< array5[i];
    }

   cout<<endl;
   int arr[] = {4, 2, 2, 8, 3, 3, 1};
   CountSort countsort;
   countsort.sort(arr, 7);
   
   for (int i = 0; i < 7; i++) {
       std::cout << arr[i] << " ";
   }
   BucketSort sorter;
   int arr2[8] = {29, 25, 3, 49, 9, 37, 21, 43};
   int buckets = 5;

   cout << "Original array: ";
   for (int i = 0; i < 8; i++) cout << arr2[i] << " ";
   cout << endl;

   sorter.sort(arr2, 8, buckets);

   cout << "Sorted array: ";
   for (int i = 0; i < 8; i++) cout << arr2[i] << " ";
   cout << endl;
    return 0;
}