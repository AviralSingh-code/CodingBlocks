#include<iostream>
using namespace std;
class node{                 //creating node of the linked list
    public:
    int data;
    node*next;
    node(int d)
    {
        data=d;
        next=NULL;
    }
};


class queue{
    private:
    node*head;          //to maintain the properties of stack 
    node*tail;
    int len;
    public:
    queue()         //constructor
    {
        head=NULL;
        tail=NULL;
        len=0;
    }

    void push(int d)
    {
        node*n=new node(d);
        if(head==NULL)
        {
            head=n;
            tail=n;
            len++;
        }
        else
        {
            tail->next=n;
            tail=n;
            len++;
        }
    }

    void pop()
    {
        if(head==NULL)
        {
            return;
        }
        else if(head->next==NULL)
        {
            delete head;
            head=NULL;
            tail=NULL;
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


    int front()
    {
        return head->data;
    }

    int size()
    {
        return len;
    }


    bool empty()
    {
        return head==NULL;
    }



};


int main()
{
    queue q;
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