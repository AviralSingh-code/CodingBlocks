#include<iostream>
#include<vector>
using namespace std;
class minHeap{      //we are trying to implement heap using vector as the complexity for normal complete tree is O(n) --->for searching + log2(n)-->for moving the height
    private:
    void heapify(int i)
    {
        int min_index=i;    //to store the index with which we have swapped the last element with
        int left=2*i;   //for left child
        int right=2*i+1;    //for right child
        if(left<v.size()&&v[min_index]>v[left])     //left<v.size() is done to check if its child exists as if it exits then the formula 2*i is valid and the child should exist in the range of size of vector
        {
            min_index=left;
        }
        if(right<v.size()&&v[min_index]>v[right])
        {
            min_index=right;        //if right is smaller than the root value
        }

        if(min_index!=i)        //we swap when there is some change as if it remains unchanged then there is no need to swap
        {
            swap(v[min_index],v[i]);
            heapify(min_index);     //with new position of the elements
        }
    }

    public:
    vector<int>v;
    minHeap()
    {
        v.push_back(-1);    //for the first element as we don't want to use the 0 index
    }
    void push(int data)
    {
        v.push_back(data);      //we push data
        int child=v.size()-1;   //we get the child location just pushed
        int parent=child/2; //we get the parent of the child just formed
        while(child>1&&v[parent]>v[child])  //child>1 as we have to repeat this if the child has not reached the root node of the tree that is the index no 1
        {
            swap(v[parent],v[child]);  //we swap parent and child
            child=parent;   //now we make parents location as child's location
            parent=parent/2;    //we make parents position as parent/2 ----> as parent of every child is present at index (child's index)/2
        }
    }

    int top()
    {
        return v[1];
    }

    void pop()
    {
        swap(v[1],v[v.size()-1]);       //reduces complexity to O(1) form O(n) as we don't have to traverse the array
        v.pop_back();   //removes the last element i.e the root that we wanted to delete;
        heapify(1);     //1 corresponds to index 
    }
    bool empty()
    {
        return v.size()==1; //1 as we have placed -1 on our own at index 0 
    }
};
int main()
{
    minHeap h;
    h.push(1);
    h.push(4);
    h.push(14);
    h.push(24);
    h.push(40);
    h.push(-4);
    h.push(3);
    h.push(20);
    h.push(13);
    h.push(5);
    while(!h.empty())
    {
        cout<<h.top()<<" ";     //as the output is sorted so it is called heap sort
        h.pop();
    }
    
}