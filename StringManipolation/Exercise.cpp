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


  void reversePharase(string str)
  {
    int end = str.length() - 1;
    
    int last;
    for(int i = str.length()-1;i >= 0;i--)
    {
        last = i;
        if(str[last - 1] == ' ' || last-1 < 0)
        {
          for(int i=last;i<=end;i++)
            cout<<str[i];
          end = last -1;
        }
        
       
    }


  }

};



int main()
{
   string str = "hello";
   string str2 = "trees are beautiful.";
   StringManipolate stringManipolate;

   cout<<"number of vowels in"<<str<<endl;
   cout<< stringManipolate.countingVowels(str);
   
   cout<<"Reverse of"<<str<<endl;
   stringManipolate.reverseString(str);
   cout<<endl;
   stringManipolate.reversePharase(str2);
    return 0;
}