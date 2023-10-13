#include<iostream>
#include<stack>                 //importing stack library
using namespace std;
int main()
{
    stack<int>s;            //defining stack
    s.push(1);
    s.push(2);              //using push function
    s.push(3);
    s.push(4);
    s.push(5);

    while (!s.empty())              //standard method to print the stack
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    

}