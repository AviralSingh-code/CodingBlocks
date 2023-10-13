#include<iostream>
#include<list>  //header for linked list
using namespace std;
int main()
{
    list<int>l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    l.push_back(5);


    for(auto n:l)   //for each loop --> n show kis ka data --> l is the entire linked list
    {
        cout<<n<<" ";
    } 
    return 0;
}