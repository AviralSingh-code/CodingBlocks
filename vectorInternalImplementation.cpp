#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std; 
class Vector{
    public:
    int cs;     //for current size
    int ms;     //for maximum capacity
    int *arr;       //for dynamic formation of array


    Vector(int s=2)     //default constructor s=2 is to set the initial size of the vector to 2
    {
        ms=s;       //initially maximum size is set to 2
        cs=0;       //current size to 0
        arr = new int[ms];      //to form the array of initial size to 2 dynamically
    }


    void push_back(int a)       //to push the element a in the vector
    {
        if(ms==cs) //if the capacity of the vector is equal to current size then there is no space left so we need to form the new vector of double the size
        {
            int *oldarr=arr;//to store the pointer of the old array because we have to copy the elements of the old vector to the new vector
            int oldms=ms;       //to store the old capacity of the old vector
            arr = new int[2*ms];        //to form the new vector of double the size
            ms*=2;      //to double the capacity of the new vector
            for(int i=0;i<ms;i++)       //to copy the elements of the old vector to the new vector
            {
                arr[i]=oldarr[i];
            }

            delete [] oldarr;   //to delete the previous vector at the previous pointer  location
        }
        arr[cs]=a;      //to push the elements in the vector
        cs++;   //to increase the size of the vector
    }

    void pop_back()     //to pop the last element
    {
        if(cs>0)
        {
            cs--;
        }
    }

    int size()      //to return the size of the vector
    {
        return cs;
    }

    int capacity()      //to return the capacity of the vector
    {
        return ms;
    }


    int operator [](int i) //[] operator is over loaded and i is taken as parameter
    { 
        return arr[i];
    }

};
int main()
{
    Vector v;
    v.push_back(1);
    v.push_back(4);
    v.push_back(2);
    v.push_back(5);
    v.push_back(7);
    cout<<"Size of the vector is "<<v.size()<<endl;
    cout<<"Capacity of the vector is "<<v.capacity()<<endl;
    v.pop_back();
    cout<<"Size of the vector is "<<v.size()<<endl;
    cout<<"Capacity of the vector is "<<v.capacity()<<endl;


    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }

    return 0;
}