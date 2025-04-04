#include <iostream>
#include <unordered_map>
#include <set>
#include <functional>
int main()
{
    std::unordered_map<int, std::string> map;

    map[1] = "Ali";
    map[2] = "Bob";
    map[3] = "Charlie";

    std::cout<<"Value for key 1: "<<map[1]<<std::endl;
    std::cout<<"Value for key 3: "<<map[3]<<std::endl;

    if(map.find(2) != map.end())
      std::cout<<"Key 2 exists!"<<std::endl;

    map.erase(2);

    for(const auto& pair : map)
      std::cout<<"Key:" << pair.first<<" Value:"<< pair.second<<std::endl;





      std::set<int> mySet;
      mySet.insert(1);
      mySet.insert(2);
      mySet.insert(3);
      mySet.insert(2);
      mySet.insert(1);

      std::cout<<"element of set:"<<std::endl;
      for(int item : mySet)
      {
        std::cout<<item<<" ";
      }

      std::string str = "hello";
      std::hash<std::string> stringHasher;
      size_t strHash = stringHasher(str);
      std::cout << "Hash code of '" << str << "': " << strHash << std::endl;


    return 0;
}