#include<iostream>
#include<queue>
using namespace std;

void printHeap(priority_queue<int, vector<int> ,greater<int> > h)   //important method to pass the heap
{
    while (!h.empty())
    {
        cout<<h.top()<<" ";
        h.pop();
    }
    
}

int main()
{
    priority_queue<int, vector<int> ,greater<int> > h;
    int count=0;
    int k=3; //for top 3 products
    int n;  //to store the entered value
    while (1)       //for continuous input
    {
        cin>>n;
        if(n==-1)
        {
            printHeap(h);       //we have created a function so that we don't make the heap empty when we print it
        }
        else
        {
            if(count<k)     //to put 3 elements in the heap
            {
                h.push(n);
                count++;
            }
            else
            {
                if(h.top()<n)   //we know that the smallest element is at the top so if we want to replace an element from the heap it will be the smallest so we pop from top
                {
                    h.pop();
                    h.push(n);   //then we push again and it will automatically heapify itself
                }
            }
        }
        
    }
    return 0;
}