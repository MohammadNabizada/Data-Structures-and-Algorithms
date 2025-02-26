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
    //make a priority queue
    std::cout<<std::endl;
    std::priority_queue<int> pQueue;
    
    pQueue.push(1);
    pQueue.push(3);
    pQueue.push(6);
    pQueue.push(2);

    while(!pQueue.empty())
    {
        std::cout<<pQueue.top()<<std::endl;
        pQueue.pop();
    }



    return 0;
}