#include <iostream>
#include <math.h>
using namespace std;
class Search
{

private:


int binarySearchRec(int arr[],int size,int target,int left,int right)
{ 
   int middle = (left + right) /2;
   
   if(right < left)
     return -1;

   if(arr[middle] == target)
     return middle;

   if(target < arr[middle])
     return binarySearchRec(arr,size,target,left,middle-1);
    
   return binarySearchRec(arr,size,target,middle+1,right);
}

int ternarySearch(int arr[],int size,int target,int left,int right)
{

  if(left > right)
    return -1;
  int partitionSize = (right - left) / 3;

  int mid1 = left + partitionSize;
  int mid2 = right - partitionSize;

  if(arr[mid1] == target)
     return mid1;

  if(arr[mid2] == target)
    return mid2;
  if(target < arr[mid1])
    return ternarySearch(arr,size,target,left,mid1 - 1);
  if(target > arr[mid2])
    return ternarySearch(arr,size,target,mid2 + 1,right);

  return ternarySearch(arr,size,target,mid1 + 1,mid2 - 1);
}
public:

   
    void linearSearch(int item,int size,int arr[])
    {
        for(int i = 0; i < size;i++)
        {
            if(arr[i] == item)
            {
              cout<<item<<" is in this array and the index is :"<<i;
              return;
            }
        }
        cout<<item<<"is not found";
    }

    int binarySearchRec(int arr[],int size,int target)
    {
         return binarySearchRec(arr,size,target,0,size - 1);
    }
    

    int binarySearch(int arr[],int size,int target)
    {
      int left = 0;
      int right = size -1 ;
      int middle = (left + right) / 2;

        while(left <= right)
        {
        
            if(target == arr[middle])
                return middle;
            if(target < arr[middle])
                right = middle - 1;
            else {
              left = middle + 1;
            }
            middle = (left + right) / 2;
        }
      return -1;
    }

    int ternarySearch(int arr[],int size,int target)
    {
      return ternarySearch(arr,size,target,0,size-1);
    }


    int jumpSearch(int arr[],int size,int target)
    {
      int blockSize = int(sqrt(size));
      int start = 0;
      int next = blockSize;


      while(start < size && arr[next -1] < target)
      {
        start = next;
        next += blockSize;
        if(next > size)
          next = size;
      }

      for(int i= start; i < next;i++)
        if(arr[i] == target)
          return i;

      return -1;
    }

    int exponentialSearch(int arr[],int size,int target)
    {
      int bound =1;
      while(bound < size && arr[bound] < target)
        bound *= 2;

      return binarySearch(arr,bound,target);
    }
};





int main()
{
    int array[5] = {1,2,3,5,7};

    Search search;
    search.linearSearch(1,5,array);

    cout<<endl;
    int array2[5] = {1,2,3,5,7};
     
    cout << "seraching for 3"<<endl;
    cout<< search.binarySearchRec(array2,5,3);
    cout << endl;
    cout << "seraching for 3"<<endl;
    cout<< search.binarySearch(array2,5,3);
    cout << endl;
    cout << "seraching for 3"<<endl;
    cout<< search.ternarySearch(array2,5,3);

    cout << endl;
    cout << "seraching for 7"<<endl;
    cout<< search.ternarySearch(array2,5,7);

    cout << endl;
    cout << "seraching for 5"<<endl;
    cout<< search.exponentialSearch(array2,5,5);
    return 0;
}