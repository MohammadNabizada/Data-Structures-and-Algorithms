#include <iostream>
#include <unordered_map>
#include <list>
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
      private:
       int key;
       std::string value;
      public:
      Entry(int key, std::string value)
      {
         this->key = key;
         this->value = value;
      }

      private:
       std::list<Entry> entries[5];
       int hash(int key)
       {
          return key % entries->size();
       }
      public:
       void put(int key, std::string value)
       {
        int index = hash(key);
        for(auto &entry: entries[index])
        {
            if(entry.key == key)
            {
                entry.value = value;
                return;
            }

            entries[index].push_back({key, value});
        }
       }

       std::string get(int key)
       {
        int index = hash(key);
        std::list<Entry> bucket = entries[index];

        for(auto &entry: bucket)
        {
            if(entry.key == key)
             return entry.value;
        }
        return "";
       }

   };








};


int main()
{


    firstNonerepeat noneRepeated("green apple");
    std::cout<<noneRepeated.noneRepeated();
    std::cout<<std::endl;
    std::cout<<noneRepeated.firstRepeatedchar();


    return 0;
}