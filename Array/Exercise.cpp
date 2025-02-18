#include <iostream>
class Array{

  private:
    int count = 0;
    int length;
    int *items;

  public:

   // Use an Initializer list to avoid shadowing
    Array(int len) : length(len) {
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
          delete[] items;
          items = newItems;
          length *= 2;

        }
        //Add the new item at the end
        items[count++] = item;
    }
    void removeAt(int index)
    {
      //Validate the index
       if (index < 0 || index >= count)
          throw std::invalid_argument("Value cannot be negative");

      //Shift the items to the left to fill the hole
      for (int i = index; i < count;i++)
         items[i] = items[i+1];

      count--;

    }
    int indexOf(int item)
    {
      //If we find it, return index
      //Otherwise, return -1

      for(int i = 0; i < count; i++)
      {
        if(items[i] == item)
           return i;
      }
       return -1;
    }
    int max()
    {
      int temp_max = INT_MIN;
      for(int i = 0; i < count; i++)
      {
        if(items[i] > temp_max)
           temp_max = items[i];
      }
      return temp_max;
    }
    ~Array()
    {
      delete[] items;
    }

};




int main()
{
    
    Array numbers(3);
    numbers.insert(20);
    numbers.insert(30);
    numbers.insert(40);
    numbers.insert(50);
    numbers.removeAt(2);
    std::cout<<numbers.indexOf(30)<<std::endl;
    numbers.print();
    std::cout<<numbers.max()<<std::endl;
    std::cin.get();
    return 0;
}