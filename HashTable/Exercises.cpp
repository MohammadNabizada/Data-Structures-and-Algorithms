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



class findThemostReapeted
{
  private:
   std::unordered_map<int,int> map;
  public:
  int mostrepeated(int array[],int size)
  {
   for(int i = 0; i < size;i++){
    map[array[i]]++;
   }
   
   int mostRepeatednumber = 0;
   int maxFreq = 0;

   for(const auto& pair: map)
   {
    if(pair.second > maxFreq)
    {
        maxFreq = pair.second;
        mostRepeatednumber = pair.first;
    }
   }

   return mostRepeatednumber;
  }

};

class findingPairs{
  private:
  std::unordered_map<int,int> map;
  public:
  
  void addNumbers(const int arr[], int size)
  {
    for(int i = 0; i < size;i++)
    {
        map[arr[i]]++;
    }
  }


  int countPair(int k)
  {
    int count = 0;

    for(const auto& pair : map)
    {
        int num = pair.first;
        if(map.find(num+k) != map.end())
          count++;
        if(map.find(num - k) != map.end())
          count++;

    }
    return count / 2;
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
    findThemostReapeted mre;
    int array[] = {1,2,2,3,3,3,4};
    int size = sizeof(array) / sizeof(array[0]);
    std::cout<<"most repeated:"<<mre.mostrepeated(array,size);
    

    int arr[] = {1,7,5,9,2,12,3};
    int length = sizeof(arr) / sizeof(arr[0]);

    int k = 2;

    findingPairs fpairs;
    fpairs.addNumbers(arr,length);
    std::cout<<"pairs:"<<fpairs.countPair(k);
    return 0;
}