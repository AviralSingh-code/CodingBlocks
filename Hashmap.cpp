#include<iostream>
using namespace std;
class node{
    public:
    int val;
    string key;
    node*next;

    node(string k,int v)
    {
        key=k;
        val=v;
        next=NULL;
    }
};


class hashmap{

    int hashFunction(string key)
    {
        int ans=0;
        int mulFact=1;  //multiplication factor
        for(int i=0;i<key.length();i++)
        {
            ans=ans+(key[i]%ts*mulFact%ts)%ts; //or we can 
            mulFact=(mulFact*29)%ts;     //any slightly bigger prime no can be used. we take mod with ts to keep it in range otherwise it will get bigger than integer range
        }

        ans=ans%ts; //to keep it in range

        return ans;
    }



    void Rehashing()
    {
        node**oldarr=arr;    //to hold the address of the old array
        int oldts=ts;
        arr=new node* [ts*2];    //creating the new array
        ts=ts*2;    //as we are creating the size of the array a 2*ts
        cs=0;   //for the new table
        for(int i=0;i<ts;i++)
        {
            arr[i]=NULL;
        }
        //copy the value from the old table
        for(int i=0;i<oldts;i++)
        {
            node*head=oldarr[i];   //to hold the elements at a particular address
            while(head)
            {
                insert(head->key,head->val);    //as the table size of the new table changes so we need to follow the original procedure and we cannot just pick from position 1 to position 1 of the new table
                head=head->next;
            }
        }
        delete [] oldarr;   //deleting the old table
    }





    public:
    int ts;     //table size
    int cs;     //current size
    node**arr;      //as the main table stores pointers of the linked list so its data type is node* and the pointer of this table will be node**

    hashmap(int size=7)
    {
        cs=0;
        ts=size;
        arr=new node* [ts];  //pointer of node* is node** 
        for(int i=0;i<ts;i++)
        {
            arr[i]=NULL;    //points initially to NULL
        }
    }


    void insert(string key,int val)
    {
        int index=hashFunction(key);    //returns the value of the index where it need to be placed in the table
        node*n=new node(key,val);       //creating a new node
        n->next=arr[index]; //to insert the node in the front of the linked list
        arr[index]=n;       //stores the value of the node address
        cs++;   //increment in the current size 
        if((cs*1.0)/ts>0.6) //we multiply by 1.0 to convert int to float. 0.6 ----> 60% full
        {
            Rehashing();
        }
    }


    void print()
    {
        for (int  i = 0; i < ts; i++)
        {
            cout<<i<<"-->";
            node*head=arr[i];   //to store the address of the linked list
            while (head)
            {
                cout<<head->key<<" ";
                head=head->next;
            }

            cout<<endl;
        }
    }

    node* search(string key)
    {
        int indx=hashFunction(key); //give index of the table
        node*head=arr[indx];    //searching the linked list with same index in the table
        while (head)
        {
            if(head->key==key)
            {
                return head;
            }
            head=head->next;
        }
        return NULL;    //if the key is not present
    }


    //operator overloading
    int& operator [](string key)        //  IMPORTANT int& is return by reference and it return the bucket by reference
    {
        node*ans=search(key);
        //key is not present 
        if(ans==NULL)
        {
            int g;  //for garbage value;
            insert(key,g);  //to add it to the table
            ans=search(key);        //searching again after putting it in the table

            return ans->val;    //returns the val of ans so that it can get corrected
        }



        //key is present
        else
        {
            return ans->val;
        }
    }

};
int main()
{
    hashmap h;
    h.insert("mango",100);
    h.insert("Kiwi",150);
    h.insert("apple",60);
    h.insert("banana",180);
    h.insert("orange",200);
    h.insert("abc",30);
    h.insert("dfe",78);
    h.insert("the",21);
    h.insert("dwkkw",68);

    h.print();
    cout<<endl;



    //to use hashmap so that we can use it as index
    h["papaya"]=200; //as it is not present so it will get first added and then the functions returns it by reference so that it can read value from here



    cout<<endl;
    h.print();  //to print after inserting papaya



    cout<<"The price of kiwi is : "<<h["Kiwi"]<<endl;


    return 0;

}