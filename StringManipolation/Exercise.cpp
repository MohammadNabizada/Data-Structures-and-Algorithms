#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class StringManipolate
{

  private:
  bool isVowel(char ch)
  {
    return (ch == 'o' || ch == 'O') || (ch == 'a' || ch == 'A') || (ch == 'e' || ch == 'E') || (ch == 'u' || ch == 'U') || (ch == 'i' || ch == 'I');
  }


  public:
  
  int countingVowels(string str)
  {
    int count = 0;
    for(char let : str)
    {
        if(isVowel(let))
          count++;
    }

    return count;
  }

  void reverseString(string str)
  {
    stack<char> stack;

    for(char ch : str)
      stack.push(ch);
    while(!stack.empty())
    {
        cout<<stack.top();
        stack.pop();
    }
  }

};



int main()
{
   string str = "hello";

   StringManipolate stringManipolate;

   cout<<"number of vowels in"<<str<<endl;
   cout<< stringManipolate.countingVowels(str);
   
   cout<<"Reverse of"<<str<<endl;
   stringManipolate.reverseString(str);

    return 0;
}