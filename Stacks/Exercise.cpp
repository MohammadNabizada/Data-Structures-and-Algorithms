#include <iostream>
#include <stack>
#include <string.h>

class Stack{

  private:
  int *st_array = new int[1];
  int size = 1;
  public:
  int count = 0;
  void push(int ch)
  {
  if(count == size){
    int *new_array = new int[count * 2];

    for(int i = 0; i < count; i++){
      new_array[i] = st_array[i];
    }

    delete[] st_array;
    st_array = new_array;
    size *= 2;
  }
      st_array[count++] = ch;
  }
  int top(){
    if(count > 0){
      return  st_array[count - 1];
    }
    return 0;
  }
  void pop()
  {
    count--;
  }
  bool isEmpty()
  {
    if(count < 0)
      return true;
    
    return false;
  }
};


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

class Expression{
  private:
   std::string leftBrackets = "({<";
   std::string rightBrackets = ")}>";

   bool isLefBracket(char ch)
   {
    return leftBrackets.find(ch) != std::string::npos;
   }

   bool isRightBracket(char ch)
   {
    return rightBrackets.find(ch) != std::string::npos; 
   }

   bool bracketsMatch(char left, char right)
   {
    return (right == ')' && left != '(') ||
           (right == '>' && left != '<') ||
           (right == ']' && left != '[') ||
           (right == '}' && left != '{');
   }
  public:
   bool isBalanced(std::string input){
    std::stack<char> stack;

    for(char ch : input)
    {
      if(isLefBracket(ch))
        stack.push(ch);
      
      if(isRightBracket(ch)){

        if (stack.empty()) return false;
        char top = stack.top();

        if(bracketsMatch(top,ch)) return false;
        stack.pop();
      }
    }
    return stack.empty();
   }
};
int main()
{
    std::string str = "abcd"; 
    StringReverser *reverser = new StringReverser();
    std::cout<<reverser->reverse(str);

    std::cout<<std::endl;
    Expression *exp = new Expression();
    std::string str2 = "(1+2)[]";
    std::cout<<exp->isBalanced(str2);
    std::cout<<std::endl<<"top"<<std::endl;
    Stack *stack = new Stack();
    stack->push(2);
    stack->pop();
    std::cout<<stack->top();
    std::cout<<std::endl;
    std::cout<<stack->isEmpty();
    return 0;
}