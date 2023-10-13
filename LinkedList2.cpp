#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node*alpha;     //to hold address we can have any next or alpha or anything else

    node(int d)     //constructor
    {
        data=d;
        alpha=NULL;     //pointer should initially point to NULL
    }
};

void insert(node*&head,node*&tail,int data)     //pass by reference as we have to permanentaly manupilate the pointer head and tail
{
    node*n=new node(data);
    if(head==NULL)
    {
        head=n;
        tail=n;
    }
    else
    {
        n->alpha=head;
        head=n;
    }
}


void printll(node*head)     //pass by value as we don't want any permanent change in the head
{
    while (head!=NULL)
    {
        cout<<head->data<<"->";
        head=head->alpha;
    }
    
}


node* mid(node*head)                    //mid point runner approach
{
    node*slow=head;
    node*fast=head->alpha;
    while (fast!=NULL&&fast->alpha!=NULL)
    {
        slow=slow->alpha;
        fast=fast->alpha->alpha;
    }
    return slow;
    
}

node* merge(node*a,node*b)      //as it is returning pointer so return type is node*
{
    //base case
    if(a==NULL)                 //if we don't have the first linked list the return second one
    {
        return b;
    }
    if(b==NULL)                 //if we don't have the second linked list the return first one
    {
        return a;
    }
    //recursive case
    node*newhead;                   //to hold the first value that is smaller for the two linked list
    if(a->data<b->data)
    {
        newhead=a;                      //taking out the first element of the linked list which is smaller
        node*c=merge(a->alpha,b);       //letting recursion work ----> it returns a pointer for the head of the remaining linked list
        newhead->alpha=c;               //pointing the element we took out to the linked list returned by recursion
    }
    else
    {
        newhead=b;
        node*d=merge(a,b->alpha);
        newhead->alpha=d;
    }
    return newhead;                     //returning the head of the merged linked list
}



node* mergesort(node*head)
{
    //base case
    if(head==NULL||head->alpha==NULL)
    {
        return head;
    }
    //recursive case

    node*m=mid(head);
    node*b=head;
    node*c=m->alpha;
    m->alpha=NULL;

    b=mergesort(b);
    c=mergesort(c);

    node*finalPointer=merge(b,c);

    return finalPointer;
}


bool checkCyclic(node*head)
{
    node*slow=head;
    node*fast=head;
    while (fast!=NULL&&fast->alpha!=NULL)
    {
        fast=fast->alpha->alpha;
        slow=slow->alpha;
        if(fast==slow)                          //Floyd test for cyclicity
        {
            return true;
        }
    }
    return false;
}


void createcycle(node*head,node*&tail)              //tail getting manupilated so pass by reference
{
    // node*temp=head;                                      Another approach using temp pointer
    // while (temp->alpha!=NULL)
    // {
    //     temp=temp->alpha
    // }
    // temp->alpha=head->alpha->alpha;
    tail->alpha=head->alpha->alpha;                     //for linking tail to the third element i.e. head->aplha->alpha
}



void breakCycle(node*head)                      //Floyd cycle algorithm
{
    node*fast=head;
    node*slow=head;
    while (fast!=NULL&&fast->alpha!=NULL)
    {
        slow=slow->alpha;
        fast=fast->alpha->alpha;
        if(fast==slow)                          //to get point of overlap of two pointer
        {
            break;
        }
    }
    slow=head;                          //setting it back to head
    node*prev=head;                         //getting previous to hold point just before head
    while (prev->alpha!=fast)                   //getting to a location before head
    {
        prev=prev->alpha;
    }
    while (fast!=slow)                  //moving fast and slow to meet at a point again
    {
        prev=fast;
        fast=fast->alpha;
        slow=slow->alpha;
    }
    prev->alpha=NULL;                   //setting previous to null to break the cyclic linked list
    
    
}



int main()
{
    node*head=NULL,*tail=NULL;          //first linked list
    insert(head,tail,99);
    insert(head,tail,87);
    insert(head,tail,50);
    insert(head,tail,30);
    insert(head,tail,9);
    insert(head,tail,2);

    node*head2=NULL,*tail2=NULL;            //second linked list
    insert(head2,tail2,45);
    insert(head2,tail2,39);
    insert(head2,tail2,19);
    insert(head2,tail2,15);
    insert(head2,tail2,10);

    cout<<"First linked list :-"<<endl;
    printll(head);
    cout<<endl;
    cout<<"Second linked list :-"<<endl;
    printll(head2);


    cout<<endl;
    cout<<"Merged linked list are :-";
    node*finalHead=merge(head,head2);
    printll(finalHead); 
    cout<<endl;                    //print using the final head of the merged linked list


    //third linked list to use mergesort


    node*head3=NULL,*tail3=NULL;            //third linked list
    insert(head3,tail3,34);
    insert(head3,tail3,78);
    insert(head3,tail3,19);
    insert(head3,tail3,22);
    insert(head3,tail3,17);
    insert(head3,tail3,1);
    insert(head3,tail3,190);
    insert(head3,tail3,145);
    insert(head3,tail3,12);
    printll(head3);
    cout<<endl;
    mergesort(head3);
    cout<<"Sorted linked list :-"<<endl;
    printll(head3);

    cout<<endl;

    //creating fourth linked list to demonstrate cyclic behaviour

    node*head4=NULL,*tail4=NULL;            //third linked list
    insert(head4,tail4,36);
    insert(head4,tail4,76);
    insert(head4,tail4,16);
    insert(head4,tail4,26);
    insert(head4,tail4,14);
    insert(head4,tail4,1);
    insert(head4,tail4,1340);
    insert(head4,tail4,1345);
    insert(head4,tail4,134);
    printll(head4);
    cout<<endl;
    if(checkCyclic(head4))
    {
        cout<<"Yes the linked list is cyclic"<<endl;
    }
    else
    {
        cout<<"No the linked list is not cyclic"<<endl;
    }


    //converting it above linked list to cyclic

    createcycle(head4,tail4);
    
    if(checkCyclic(head4))              //checking again
    {
        cout<<"Yes the linked list is cyclic"<<endl;
    }
    else
    {
        cout<<"No the linked list is not cyclic"<<endl;
    }




    //breaking the cyclic linked list
    breakCycle(head4);
    printll(head4);

    
    return 0;

}