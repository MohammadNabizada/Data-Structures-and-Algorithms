#include <iostream>
#include <stack>
using namespace std;
int main()
{
  stack<int> stack;
  stack.push(10);
  stack.push(20);
  stack.push(30);

  cout<<stack.top();
  int top = stack.top();
  stack.pop();
  cout<<stack.top();

    return 0;
}