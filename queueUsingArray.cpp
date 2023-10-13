#include<iostream>
using namespace std;
class queue{
    private:
    int *arr;
    int cs;
    int f;
    int n;
    int e;
    public:
    queue(int s=5)          //method to set the default parameter
    {
        n=s;
        arr=new int[s];
        f=0;
        e=n-1;
        cs=0;
    }  

    void push(int d)
    {
        if(cs<n)
        {
            //to make it circular --> as soon as e reaches limit it is re-assigned to 0
            e=(e+1)%n;     //to make the queue circular
            arr[e]=d;
            cs++;
        }
        else
        {
            cout<<"Queue is full ----> overflow"<<endl;
        }
    }

    void pop()
    {
        if(cs>0)
        {
            f=(f+1)%n;          //to make it circular --> as soon as f reaches limit it is re-assigned to 0 
            cs--;
        }
        else
        {
            cout<<"Queue is empty ----> underflow"<<endl;
        }
    }

    int front()
    {
        return arr[f];
    }

    bool empty()
    {
        return cs==0;
    }

};
int main()
{
    queue q(6);         //method to override the default parameter
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