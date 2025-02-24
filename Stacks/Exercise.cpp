#include <iostream>
#include <stack>
#include <string.h>
using namespace std;

class TwoStacks {
private:
    int* arr;
    int size;
    int top1, top2;

public:
    TwoStacks(int n) {
        size = n;
        arr = new int[n];
        top1 = -1;
        top2 = size;
    }

    void push1(int value) {
        if (top1 < top2 - 1) {
            top1++;
            arr[top1] = value;
        } else {
            cout << "Stack Overflow: No space to push in Stack 1" << endl;
        }
    }

    void push2(int value) {
        if (top1 < top2 - 1) {
            top2--;
            arr[top2] = value;
        } else {
            cout << "Stack Overflow: No space to push in Stack 2" << endl;
        }
    }

    int pop1() {
        if (top1 >= 0) {
            int value = arr[top1];
            top1--;
            return value;
        } else {
            cout << "Stack Underflow: No elements to pop in Stack 1" << endl;
            return -1;
        }
    }

    int pop2() {
        if (top2 < size) {
            int value = arr[top2];
            top2++;
            return value;
        } else {
            cout << "Stack Underflow: No elements to pop in Stack 2" << endl;
            return -1;
        }
    }
};


class Stack{
  private:
     int *items = new int[5];
     int length = 5;
     int count;
  public:
     void push(int item)
     {
      if(count == length)
         throw std::invalid_argument("Stack overflow");
      
      items[count++] = item;
     }

     int pop()
     {
      if(count == 0)
        throw std::invalid_argument("stack is empty");
      return items[--count];
     }

     int peek()
     {
      if(count == 0)
        throw std::invalid_argument("stack is empty");
      return items[count - 1];
     }
     bool isEmpty()
     {
      return count == 0;
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
    std::cout<<std::endl;
    std::cout<<stack->isEmpty();

    TwoStacks ts(5);
    ts.push1(5);
    ts.push2(10);
    ts.push2(15);
    ts.push1(11);
    ts.push2(7);

    cout << "Popped element from stack1 is " << ts.pop1() << endl;
    ts.push2(40);
    cout << "Popped element from stack2 is " << ts.pop2() << endl;
    return 0;
}