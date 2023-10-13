#include"node.h"            //method to use the user-defined header file ----> as node if being used so we included it over here
using namespace std;
template<typename T>            //defining template for the stack header
class stack{                
    private:
    node<T>*head;                   //defining the node syntax -----> node<T>*nameOfNode  
    int len;

    public:

    stack()     
    {
        head=NULL;
        len=0;
    }

    void push(T d)        //changing data type to data type of template
    {
        node<T>*n=new node<T>(d);       //defining pointer
        n->next=head;
        head=n;
        len++;
    }


    void pop()      
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
            node<T>*temp=head;
            head=head->next;
            delete temp;
            temp=NULL;
            len--;
        }
    }

    int size()      
    {
        return len;
    }


    T top()           
    {
        return head->data;
    }


    bool empty()
    {
        return head==NULL;
    }


};
