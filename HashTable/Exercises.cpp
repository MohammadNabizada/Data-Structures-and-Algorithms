#include <iostream>
#include <unordered_map>
#include <list>
#include <string>
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
    private:
   
    class Entry {
    public:
        int key;
        std::string value;

        Entry(int key, std::string value) : key(key), value(value) {}
    };

    static const int TABLE_SIZE = 5; 
    std::list<Entry> entries[TABLE_SIZE];

  
    int hash(int key) {
        return key % TABLE_SIZE;
    }
    
public:
    
    void put(int key, std::string value) {
        int index = hash(key);
        for (auto& entry : entries[index]) {
            if (entry.key == key) {
                entry.value = value;
                return;
            }
        }
        entries[index].emplace_back(key, value);
    }

   
    std::string get(int key) {
        int index = hash(key);
        for (const auto& entry : entries[index]) {
            if (entry.key == key) {
                return entry.value;
            }
        }
        return "";
    }
    void remove(int key)
    {
        int index = hash(key);

        entries[index].remove_if([key](const Entry& entry){
            return entry.key == key;
        });
        
    }


};


int main()
{


    firstNonerepeat noneRepeated("green apple");
    std::cout<<noneRepeated.noneRepeated();
    std::cout<<std::endl;
    std::cout<<noneRepeated.firstRepeatedchar();

    HashTable table;
    table.put(1,"ALI");
    table.put(2,"Jack");
    table.put(11,"john");
    table.remove(2);
    return 0;
}