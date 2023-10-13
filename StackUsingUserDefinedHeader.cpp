#include<iostream>
#include"stack.h"           //user-defined header file
int main()
{
    stack<int>s;        //creating a new stack of integer type
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    while (!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    
    cout<<endl<<endl;

    stack<char>ch;          //creating a char type of stack
    ch.push('A');
    ch.push('B');
    ch.push('C');
    ch.push('D');

    while (!ch.empty())
    {
        cout<<ch.top()<<" ";
        ch.pop();
    }
    

}