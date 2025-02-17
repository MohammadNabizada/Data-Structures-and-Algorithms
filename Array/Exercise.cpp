#include <iostream>
class Array{

  private:
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
        for(int i = 0; i < length;i++)
        {
            std::cout<<items[i]<<std::endl;
        }
    }

};




int main()
{

    Array numbers(3);
    numbers.print();

    return 0;
}