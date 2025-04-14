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
#include <set>
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
      if (i != 0) {  
          reversed += " ";
      }
        
    }


  }

  bool isRotate(string a,string b)
  {
    return a.length() != b.length() && (a + b).find(b) == string::npos;

  }


  string removeDuplicate(string str)
  {
    string output;
    set<char> seen;
    for(char ch : str)
    {
      if(seen.find(ch) == seen.end())
      {
           seen.insert(ch);
           output.push_back(ch);
      }
    }

    return output;
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
   
  vector<string> words = split(str);
    string result = "";
    
    for(int i = 0; i < words.size(); i++) 
    {
        if (!words[i].empty())
            words[i][0] = toupper(words[i][0]);
        result += words[i];
        if (i != words.size() - 1)
            result += " ";
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

bool isAnagram2(string a,string b)
{
  
  int frequencies[26] = {0};
  
  for(int i =  0 ; i < a.length();i++){
    char c = a[i];
    c = tolower(c);
     frequencies[c - 'a']++;

  }
  
  for(int i = 0; i < b.length();i++){
  char c = b[i];
  c = tolower(c);
  if(frequencies[c - 'a'] == 0)
    return false;
   frequencies[c - 'a']--;
  }


  return true;
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
   cout<<stringManipolate.removeDuplicate("Helloo!!");
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