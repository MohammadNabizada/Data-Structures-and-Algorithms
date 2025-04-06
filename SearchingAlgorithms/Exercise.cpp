#include <iostream>
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
   

    
};





int main()
{
    int array[5] = {1,2,3,5,7};

    Search search;
    search.linearSearch(1,5,array);

    cout<<endl;
    int array2[5] = {1,2,3,5,7};
     
    cout << "seraching for index of 3"<<endl;
    cout<< search.binarySearchRec(array2,5,3);
    return 0;
}