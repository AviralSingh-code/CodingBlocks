#include<iostream>
#include<vector>                //importing the vector header file
using namespace std;

template<typename T>            //syntax ------> template<typename name>

class stack{                    //creating class for implementation using vector
    private:
    vector<T>v;           //vector defined so that we are not able to access this vector from outside
    public:
    T top()
    {
        return v[v.size()-1]; //to get top element --> size()is used to get size of vector and size()-1 gives the top element position
    }
    void push(T data)     //to push elements to stack
    {
        v.push_back(data);
    }
    void pop()
    {
        v.pop_back();
    }
    bool empty()                //to check if the stack is empty
    {
        return v.size()==0;
    }
    int size()
    {
        return v.size();
    }
};
int main()
{
    stack<int>s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);

    while (!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }

    cout<<endl<<endl;

    stack<char>ch;          //when template is defined
    ch.push('A');
    ch.push('B');
    ch.push('C');
    ch.push('D');
    ch.push('E');

    while (!ch.empty())
    {
        cout<<ch.top()<<" ";
        ch.pop();
    }
    
}