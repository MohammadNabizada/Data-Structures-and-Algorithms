#include <iostream>
#include <unordered_map>
class firstNonerepeat
{
   private:
    std::unordered_map<char,int> map;
    std::string str;
   public:
   firstNonerepeat(std::string str)
   {
    this->str = str;
   }
    char noneRepeated()
    {
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

};

int main()
{


    firstNonerepeat noneRepeated("a green apple.");
    std::cout<<noneRepeated.noneRepeated();


    return 0;
}