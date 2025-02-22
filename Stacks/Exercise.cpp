#include <iostream>
#include <stack>
#include <string.h>
class StringReverser{

  public:

  std::string reverse(std::string input){

    if(input == std::string("null"))
     throw std::invalid_argument("you give me a bad argument");


     std::stack<char> stack;

     for(char ch : input)
        stack.push(ch);
    
    
    std::string reversed = "";
     while(!stack.empty())
     {
       reversed += stack.top();
       stack.pop();
     }

     return reversed;
  }

};


int main()
{
    std::string str = "abcd"; 
    StringReverser *reverser = new StringReverser();
    std::cout<<reverser->reverse(str);
    return 0;
}