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
   for(int i = 0; i < length;i++)
   {
    for(int j = 1;j < length;j++)
    {
        if(array[j] < array[j-1])
          {
            swap(array,j,j-1);
          }
    }
   }


   for(int i =0; i < length;i++)
   {
    cout<< array[i];
   }
  }



};




int main()
{

    int array[5] = {1,4,2,7,3};

    Bublesort bublesort(5);
    bublesort.sort(array);



    return 0;
}