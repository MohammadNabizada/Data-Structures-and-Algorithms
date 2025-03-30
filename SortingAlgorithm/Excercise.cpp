#include <iostream>
#include <vector>
using namespace std;

class Bublesort
{
  private:
   int length;
  public:

  Bublesort(int length) : length(length){}
  void sort(int array[])
  {
    int temp;
     for(int i = 0 ; i < length;i++)
     {
        for(int j = i+1; j < length;j++)
        {
            if(array[j] < array[i])
            {
              temp = array[j];
              array[j] = array[i];
              array[i] = temp;
            }
        }
     }

     for(int i =0; i < length;i++)
     {
        cout<<array[i];
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