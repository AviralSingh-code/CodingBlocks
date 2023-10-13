#include<iostream>
#include<vector>                //importing the vector header file
using namespace std;
class stack{                    //creating class for implementation using vector
    private:
    vector<int>v;           //vector defined so that we are not able to access this vector from outside
    public:
    int top()
    {
        return v[v.size()-1]; //to get top element --> size()is used to get size of vector and size()-1 gives the top element position
    }
    void push(int data)     //to push elements to stack
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
    stack s;
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
    
}