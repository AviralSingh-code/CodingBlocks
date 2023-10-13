#include<iostream>
using namespace std;
class node{         //to form the nodes of the linked list
    public:
    int data;
    node*next;          //next stores the address of the next node and so it is a pointer of node type as it is pointing to a node

    node(int d)     //constructor 
    {
        data=d;
        next=NULL;      //sets the next to null when each node is formed
    }

};

void insertAtFront(node*&head,node*&tail,int data)      //to insert the element in the front
{
    node*n=new node(data);
    if(head==NULL)
    {
        head=n;
        tail=n;
    }
    else
    {
        n->next=head;
        head=n;
    }
}

void insertAtTail(node*&head, node*&tail,int data)      //to insert the elements at the tail of the element
{
    node*n=new node(data);
    if(tail==NULL)
    {
        head=n;
        tail=n;
    }
    else
    {
        tail->next=n;
        tail=n;

    }
}

int length(node*head)           //iterative way 
{
    int count=0;
    while (head!=NULL)
    {
        head=head->next;
        count++;
    }
    return count;
}

int lengthrec(node*head)            //recursive way to find the length
{
    if(head==NULL)
    {
        return 0;
    }

    return 1+lengthrec(head->next);
}

void insertAtAnyPosition(node*&head,node*&tail,int data,int pos)
{
    if(pos==0)
    {
        insertAtFront(head,tail,data);
    }
    else if(pos>=length(head))
    {
        insertAtTail(head,tail,data);
    }
    else
    {
        node*n=new node(data);
        node*temp=head;
        for(int i=1;i<=pos-1;i++)       //important way to reach a particular position
        {
            temp=temp->next;
        }
        n->next=temp->next;
        temp->next=n;
    }
}

void printlinkedList(node*head)     //printing the linked list
{
    while (head!=NULL)
    {
        cout<<head->data<<"->";
        head=head->next;
    }
    
}

void deleteTheFrontElement(node*&head,node*&tail)
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
    }
    else                    //n points to the head--> head moves to the next location--> then head is deleted
    {
        node*n=head;
        head=head->next;
        delete n;
    }
}

void deleteTheEndElement(node*&head,node*&tail)
{
    if(head==NULL)
    {
        return;
    }
    if(head->next==NULL)
    {
        delete head;
        head=NULL;
        tail=NULL;
    }
    else
    {
        node*temp=head;
        while(temp->next!=tail)
        {
            temp=temp->next;
        }
        delete tail;
        tail=temp;
        tail->next=NULL;        //to make the tail to point to NULL as its data is delete 
    }
}


void deleteAtanyposition(node*&head,node*&tail,int pos)
{
    if(pos==0)
    {
        deleteTheFrontElement(head,tail);
    }
    if(pos>=length(head)-1)
    {
        deleteTheEndElement(head,tail);
    }
    else
    {
        node*temp=head;
        for(int i=1;i<=pos-1;i++)
        {
            temp=temp->next;
        }
        node*n=temp->next;      //n to hold the node that is to be deleted
        temp->next=n->next;
        delete n;
    }
}
/*Parameter if taken as node*head and not node*&head because we don't want any change in the original head pointer*/
node* searchForElement(node*head,node*tail,int key)     //return type is set to node* because it is returning a pointer----->head
{
    while (head!=NULL)
    {
        if(head->data==key)
        {
            return head;
        }
        head=head->next;
    }
    return NULL;
}

node* searchRecursively(node*head,node*tail,int key)
{
    //base case
    if(head==NULL)
    {
        return NULL;
    }
    if(head->data==key)
    {
        return head;
    }


    //recursive case
    return searchRecursively(head->next,tail,key);
}

node* mid(node*head)        //Using mid point runner method
{
    if(head==NULL)
    {
        return NULL;
    }

    node*fast=head->next; //to give it advantage over the slow pointer so that 1->2->3->4->5->6 is the linked list with even number of elements we get 3 as out put and if fast=head the we get 4
    node*slow=head;
    while (fast!=NULL&&fast->next!=NULL)        //IMPORTANT first check the fast!=NULL condition otherwise it will give Segmentation fault
    {
        slow=slow->next;        //moving the slow pointer 1 step 
        fast=fast->next->next;      //moving the fast pointer two steps
    }
    return slow;        //returning the slow pointer as it reaches the mid when fast reaches the end
}


void reversalOfLinkedList(node*&head,node*&tail)
{
    node*c=head;
    node*prev=NULL;
    node*n=NULL;
    while (c!=NULL)
    {
        n=c->next;
        c->next=prev;
        prev=c;
        c=n;
    }
    tail = head;
    head = prev;
    tail->next = NULL;
}

int main()
{
    // node n1(3);
    // node n2(4);
    // n1.next=&n2;            //linking
    // cout<<"Data of n2 using n1"<<(*n1.next).data<<endl;/*next is a pointer so if we de-refer this we will get the value so n1.next points to n2*/
    // cout<<"Data of n2 using n1"<<n1->next.data<<endl;//n1->next.data goes to print the data of n2
    node*head=NULL;
    node*tail=NULL;
    insertAtFront(head,tail,1);
    insertAtFront(head,tail,2);
    insertAtFront(head,tail,3);
    insertAtFront(head,tail,4);
    insertAtFront(head,tail,5);
    insertAtFront(head,tail,6);
    printlinkedList(head);

    insertAtTail(head,tail,25);
    insertAtTail(head,tail,26);
    insertAtTail(head,tail,27);
    insertAtTail(head,tail,28);

    cout<<"Printing linked list"<<endl;
    printlinkedList(head);          //function to print the linked list

    cout<<endl;
    insertAtAnyPosition(head,tail,99,2);        //function to insert the element at any position
    printlinkedList(head);
    cout<<endl;
    cout<<"Length of the linked list is "<<length(head)<<endl;

    cout<<"Length of the linked list using recursion is "<<lengthrec(head)<<endl;

    cout<<"Delete the front element"<<endl;

    printlinkedList(head);
    deleteTheFrontElement(head,tail);       //to delete the front element

    cout<<endl;
    printlinkedList(head);


    cout<<"Delete the element at the end "<<endl;
    deleteTheEndElement(head,tail);     //to delete the element at the end
    printlinkedList(head);


    cout<<"Delete the element at the end"<<endl;
    deleteAtanyposition(head,tail,4);           //to delete at end position
    printlinkedList(head);


    cout<<"Searching the element"<<endl;
    node*x=searchForElement(head,tail,99);       //for searching the element, we have used node* to catch the pointer
    if(x==NULL)
    {
        cout<<"Key Not Found";
    }
    else
    {
        cout<<"Key found "<<x->data<<endl;
    }



    cout<<"Recursive searching :"<<endl;
    node*y=searchRecursively(head,tail,25);     //recursive searching
    if(y==NULL)
    {
        cout<<"Key Not Found";
    }
    else
    {
        cout<<"Key found "<<y->data<<endl;
    }


    cout<<endl;
    node*m=mid(head);
    if(m==NULL)
    {
        cout<<"Linked list does not exist"<<endl;
    }
    else
    {
        cout<<"Mid element is : "<<m->data<<endl;
    }



    cout<<endl;
    cout<<"Reversed linked list is : "<<endl;       //reversal of the linked list
    reversalOfLinkedList(head,tail);
    printlinkedList(head);



    return 0;

    

}