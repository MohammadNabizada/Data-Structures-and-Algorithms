#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
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
    int end = str.length();
    
    int last;
    for(int i = str.length()-1;i >= 0;i--)
    {
        last = i;
        if(str[last - 1] == ' ' || last-1 < 0)
        {
          for(int j=last;j<end;j++){
            cout<<str[j];
          }
          end = last -1;
          if(last > 0)
            cout<<' ';
        }
        
       
    }


  }

  bool isRotate(string a,string b)
  {
    char last = a[a.length()-1];

    for(int i = a.length() - 2;i>=0;i--)
    {
      a[i+1] = a[i];
    }
    a[0] = last;

    return a == b;
  }


  void removeDuplicate(string str)
  {
     stack<char> stack1;
     stack<char> stack2;
     for(char ch : str)
     {
      if(stack1.empty() || stack1.top() != ch)
        stack1.push(ch);
     }

     while(!stack1.empty())
     {
       stack2.push(stack1.top());
       stack1.pop();
     }
     while(!stack2.empty())
     {
       cout<<stack2.top();
       stack2.pop();
     }
  }


  void findTheMostRepeated(string str)
  {
    unordered_map<int,char> map;

    for(char ch : str)
      map[ch]++;
    
    int maxKey = INT_MIN;
    char result;
    for(auto pair : map)
    {
      if(pair.first > maxKey)
      {
        maxKey = pair.first;
        result = pair.second;
      }
    }


    cout<<result;
  }
};



int main()
{
   string str = "hello";
   string str2 = "trees are beautiful.";
   string str3 = " trees are beatiful ";
   StringManipolate stringManipolate;

   cout<<"number of vowels in"<<str<<endl;
   cout<< stringManipolate.countingVowels(str);
   
   cout<<"Reverse of"<<str<<endl;
   stringManipolate.reverseString(str);
   cout<<endl;
   stringManipolate.reversePharase(str2);
   cout<<endl;
   stringManipolate.reversePharase(str3);

   cout<<endl;

   cout<<"is rotated :"<<(stringManipolate.isRotate("ABCD","DABC")? "YES" : "NO") ;

   cout<<endl;
   stringManipolate.removeDuplicate("Helloo!!");
   cout<<endl;
   stringManipolate.findTheMostRepeated("Hellooo!!");
   
    return 0;
}