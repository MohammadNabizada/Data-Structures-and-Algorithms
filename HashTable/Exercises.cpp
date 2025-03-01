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
        for(const auto& ch : str)
        {
          auto it = map.find(ch);
          if(it != map.end())
             map[ch]++;
          else 
             return ch;
        }
        return '\0';
    }

};

int main()
{


    firstNonerepeat noneRepeated("a green apple.");
    std::cout<<noneRepeated.noneRepeated();
    std::cout<<std::endl;
    std::cout<<noneRepeated.firstRepeatedchar();


    return 0;
}