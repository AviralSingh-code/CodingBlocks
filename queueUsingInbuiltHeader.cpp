#include<iostream>
#include<queue>             //inbuilt header file for queue
using namespace std;
int main()
{
    queue<int>q;         //method to override the default parameter
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);

    while (!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    
    return 0;
}