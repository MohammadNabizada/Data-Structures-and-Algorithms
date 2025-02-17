#include <iostream>
class Array{

  private:
    int count = 0;
    int length;
    int *items;

  public:

    Array(int length)
    { 
        this->length = length;
        items = new int[length];
    }

    void print()
    {
        for(int i = 0; i < count;i++)
        {
            std::cout<<items[i]<<std::endl;
        }
    }
    void insert(int item)
    {
        //If the array is full, resize it

        if (length == count)
        {
          //Creat a new array (twice the size)
          int *newItems = new int[count * 2];
          //Copy all the exsiting items
          for (int i = 0; i < count;i++)
          {
            newItems[i] = items[i];
          }
          //Set "items" to this new array
          items = newItems;

        }
        //Add the new item at the end
        items[count++] = item;
    }



};




int main()
{

    Array numbers(3);
    numbers.insert(2);
    numbers.insert(3);
    numbers.insert(2);
    numbers.insert(3);
    numbers.print();

    return 0;
}