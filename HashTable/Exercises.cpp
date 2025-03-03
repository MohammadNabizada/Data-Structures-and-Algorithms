#include <iostream>
#include <unordered_map>
#include <list>
#include <string>
#include <stdexcept>
#include <vector>
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

class findingTwosum
{
 private:
  std::unordered_map<int,int> map;

 public:
 std::vector<int> twoSum(const int nums[], int size,int target)
 {
   for(int i = 0; i < size; i++)
   {
    int complement = target - nums[i];

    if(map.find(complement) != map.end())
      return {map[complement],i};
    map[nums[i]] = i;
   }

   return {};
 }

};

class Hashtable {
    private:
        int INITIAL_SIZE = 16;
    
        class Entry {
        public:
            int key;
            std::string value;
            bool isDeleted;
            Entry(int key, std::string value) {
                this->key = key;
                this->value = value;
                this->isDeleted = false;
            }
        };
    
        std::vector<Entry*> table;
        int size = 0;
    
        int hash(int key) {
            return key % INITIAL_SIZE;
        }
    
    public:
        Hashtable() {
            table.resize(INITIAL_SIZE, nullptr);
        }
    
        ~Hashtable() {
            for (auto entry : table) {
                if (entry) delete entry;
            }
        }
    
        void put(int key, std::string value) {
            int index = hash(key);
            int startIndex = index;
    
            while (table[index] != nullptr && !table[index]->isDeleted && table[index]->key != key) {
                index = (index + 1) % INITIAL_SIZE;
                if (index == startIndex) {
                    // Table is full, handle resizing or throw an error
                    return;
                }
            }
    
            if (table[index] == nullptr || table[index]->isDeleted) {
                if (table[index]) delete table[index];
                table[index] = new Entry(key, value);
                size++;
            } else {
                table[index]->value = value;
            }
        }
    
        std::string get(int key) {
            int index = hash(key);
            int startIndex = index;
    
            while (table[index] != nullptr) {
                if (table[index]->key == key && !table[index]->isDeleted) {
                    return table[index]->value;
                }
                index = (index + 1) % INITIAL_SIZE;
                if (index == startIndex) {
                    break;
                }
            }
            return "";
        }
    
        void remove(int key) {
            int index = hash(key);
            int startIndex = index;
    
            while (table[index] != nullptr) {
                if (table[index]->key == key && !table[index]->isDeleted) {
                    table[index]->isDeleted = true;
                    size--;
                    return;
                }
                index = (index + 1) % INITIAL_SIZE;
                if (index == startIndex) {
                    break;
                }
            }
        }
    
        int length() {
            return size;
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
    
    std::cout<<std::endl;
    int arr2 [] = {2,7,11,15};
    int len = 4;
    int target = 9;
    findingTwosum twoSum;
    std::vector<int> result = twoSum.twoSum(arr2,len,target);
    std::cout<<"twoSum:["<<result[0]<<","<<result[1]<<"]";

    Hashtable hashMap2;
    hashMap2.put(1, "Value1");
    hashMap2.put(2, "Value2");
    hashMap2.put(3, "Value3");

    std::cout << "Size: " << hashMap2.length() << std::endl;
    std::cout << "Key 2: " << hashMap2.get(2) << std::endl;

    hashMap2.remove(2);
    std::cout << "Key 2 after removal: " << hashMap2.get(2) << std::endl;
    std::cout << "Size after removal: " << hashMap2.length() << std::endl;
    return 0;
}