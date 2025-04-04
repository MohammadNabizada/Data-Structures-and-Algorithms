#include <iostream>
using namespace std;
class Search
{

public:

   
    void linearSearch(int item,int size,int arr[])
    {
        for(int i = 0; i < size;i++)
        {
            if(arr[i] == item){
              cout<<item<<" is in this array and the index is :"<<i;
              return;
            }
        }
      cout<<item<<"is not found";
    }
};





int main()
{
    int array[5] = {1,2,3,5,7};

    Search search;
    search.linearSearch(1,5,array);

    return 0;
}