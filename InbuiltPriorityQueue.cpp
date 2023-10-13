#include<iostream>
#include<queue>
using namespace std;
int main()
{
    // priority_queue<int>h;   //by default max heap
    priority_queue<int,vector<int>, greater<int> >h;    //for getting the min heap. Space in b/w <int> and the last closing brackets is important and not like <int>> it gets confused with >> used with cin
    h.push(1);
    h.push(6);
    h.push(3);
    h.push(2);
    h.push(10);
    h.push(13);
    while (!h.empty())
    {
        cout<<h.top()<<endl;
        h.pop();
    }
    cout<<endl;
    
}