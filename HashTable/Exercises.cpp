#include <iostream>
#include <unordered_map>
class firstNonerepeat
{
   private:
    std::string str;
   public:
   firstNonerepeat(std::string str)
   {
    this->str = str;
   }
    char noneRepeated()
    {
        std::unordered_map<char,int> map;
        for(const auto& ch : str)
        {
            map[ch]++;
        }   
        for(const auto& ch :str)
        {
            if(map[ch] == 1)
              return ch;
        }
        return '\0';
    }
    char firstRepeatedchar()
    {
        std::unordered_map<char,int> map;
        for (const auto& ch : str) {
            map[ch]++;
        }
    
        for (const auto& ch : str) {
            if (map[ch] > 1) {
                return ch;
            }
        }
        return '\0';
    }

};

class HashTable
{
  //put(k,v)
  //get(k) : v
  //remove(k)
  //k :int
  //value : string
  //colisions : chaining
  //linkedList[]
  //Entry class

  private:
  class Entry{
   public:
   Entry *next;
   int value;

   Entry(int vl)
   {
    this->value = vl;
   }
  };

  Entry *list = new Entry[5]; 
  public:










};


int main()
{


    firstNonerepeat noneRepeated("green apple");
    std::cout<<noneRepeated.noneRepeated();
    std::cout<<std::endl;
    std::cout<<noneRepeated.firstRepeatedchar();


    return 0;
}