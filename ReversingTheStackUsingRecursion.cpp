#include<iostream>
#include<stack>           //user-defined header file
using namespace std;

void insertatbottom(stack<int>&s,int te) //beacuse we have take the topmost element in our hand and now we want to place it in the stack that is already not empty so to put the element at the bottom we use this function
{
    if(s.empty())
    {
        s.push(te);         //we push the last element after making the stack empty
        return;
    }


    int top=s.top();        //taking out top elements to make stack empty
    s.pop();
    insertatbottom(s,te);
    s.push(top);            //to push the elements back again after placing the element at the bottom 
}


void reverse(stack<int>&s)
{
    //base case
    if(s.empty())       //to end the process
    {
        return;
    }
    
    //recursive case
    // eg if we had stack 5->4->3->2->1
    //te=5
    int te=s.top();//to take the top element that we want to hold ---> this is teh exact element the we are placing in the insertatbottom function 
    s.pop();
    reverse(s);//will return 1->2->3->4 already in the stack so we need to move this out and then at 5 at the bottom
    insertatbottom(s,te);
}

int main()
{
    stack<int>s;   //creating a new stack of integer type
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

 
    reverse(s);

    cout<<"The reversed stack is :-"<<endl;

    while (!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    
}