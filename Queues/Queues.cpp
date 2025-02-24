#include <iostream>
#include <queue>
int main()
{
    std::queue<int> queue;
    queue.push(10);
    queue.push(20);
    queue.push(30);
    int top = queue.front();
    std::cout<<top;


    return 0;
}