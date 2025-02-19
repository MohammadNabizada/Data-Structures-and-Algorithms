#include <iostream>
#include <list>





int main()
{
   //built in list library
   std::list<int> mylist;

   mylist.push_back(6);
   mylist.push_back(7);
   mylist.push_back(8);
   mylist.push_front(9);
   for(int num: mylist)
   {
    std::cout<<num<<" ";
   }
   return 0;
}