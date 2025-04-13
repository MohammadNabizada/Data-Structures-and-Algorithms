#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <vector>
#include <cctype>
#include <algorithm>
#include <iterator>
#include <sstream>
using namespace std;

class StringManipolate
{

  private:
  vector<string> split(string sentence)
  {
    istringstream iss(sentence);
    return{
      istream_iterator<string>(iss),
      istream_iterator<string>()
    };
  }

  public:
  
  int countingVowels(string str)
  {
    int count = 0;
    string vowels = "aouie";
    for(char let : str)
    {
        if(vowels.find(let) != string::npos)
          count++;
    }

    return count;
  }

  string reverseString(string str)
  {
    string reversed  = "";
    for(int i = str.length()-1; i >= 0 ; i--)
       reversed.push_back(str[i]);

    return reversed;
  }


  void reversePharase(string str)
  {
    vector<string> words = split(str);
    string reversed = "";
    for(int i = words.size() - 1;i >= 0 ;i--)
    {
      reversed += words[i];
      if (i != 0) {  // Don't add space after last word
          reversed += " ";
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
    unordered_map<char,int> map;

    for(char ch : str)
      map[ch]++;
    
    int maxKey = INT_MIN;
    char result;
    for(auto pair : map)
    {
      if(pair.second > maxKey)
      {
        maxKey = pair.second;
        result = pair.first;
      }
    }


    cout<<result;
  }

  
  
string capitalizeWords(const string& str) {
  string result;
  bool newWord = true;
  for (char ch : str) {
      if (isspace(ch)) {
        
          if (!newWord) { 
              result += ' ';
              newWord = true;
          }
         
      } else {
          if (newWord) {
              result += toupper(ch);  
              newWord = false;
          } else {
              result += ch; 
          }
      }
  }
  
  if (!result.empty() && result.back() == ' ') {
      result.pop_back();
  }
  
  return result;
}

bool isAnagram(string a,string b)
{
  if(a.length() != b.length())
    return false;
  sort(a.begin(),a.end());
  sort(b.begin(),b.end());
  
  return a == b;
}

bool isPalindrom(string str)
{
  stack<char> stack;
  int count = 0;
  for(char ch : str)
   stack.push(ch);
  
  while(!stack.empty())
  {
    if(stack.top() != str[count])
      return false;
    stack.pop();
    count++;
  }

  return true;
}

};



int main()
{
   string str = "hello";
   string str2 = "trees are beautiful.";
   string str3 = " trees are beatiful ";
   StringManipolate stringManipolate;

   cout<<"number of vowels in"<<str<<endl;
   cout<< stringManipolate.countingVowels(str)<<endl;
   
   cout<<"Reverse of "<<str<<endl;
   cout<<stringManipolate.reverseString(str);
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
   cout<<endl;
 
   cout << stringManipolate.capitalizeWords(" trees are beautiful ") << endl;   
   cout << stringManipolate.capitalizeWords("   This    is    a  TEST   ") << endl;


   cout << (stringManipolate.isAnagram("abcd","dcab") ? "YES" : "NO");

   cout<<endl;

   cout<<(stringManipolate.isPalindrom("abbac") ? "YES" : "NO");
    return 0;
}