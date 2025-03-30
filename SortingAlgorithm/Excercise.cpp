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




int main()
{

    int array[5] = {1,4,2,7,3};

    Bublesort bublesort(5);
    bublesort.sort(array);
    for(int i =0; i < 5;i++)
    {
     cout<< array[i];
    }
    return 0;
}