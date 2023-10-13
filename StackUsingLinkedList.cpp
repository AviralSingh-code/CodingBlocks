#include<iostream>
using namespace std;
class node{                 //to form node of the linked list
    public:
    int data;
    node*next;
    node(int d)
    {
        data=d;
        next=NULL;
    }
};

class stack{                //to implement stack
    private:
    node*head;          //private because we don't want to use it outside the class
    int len;

    public:

    stack()     //constructor
    {
        head=NULL;
        len=0;
    }

    void push(int d)        //to push data to stack
    {
        node*n=new node(d);
        n->next=head;
        head=n;
        len++;
    }


    void pop()      //to pop data from stack
    {
        if(head==NULL)
        {
            return;
        }
        if(head->next==NULL)
        {
            delete head;
            head=NULL;
            len--;
        }
        else
        {
            node*temp=head;
            head=head->next;
            delete temp;
            temp=NULL;
            len--;
        }
    }

    int size()      //to return size of the stack
    {
        return len;
    }


    int top()           //to return the top element
    {
        return head->data;
    }


    bool empty()
    {
        return head==NULL;
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

    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }




    return 0;
}