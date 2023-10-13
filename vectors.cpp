#include<iostream>
#include<vector>
using namespace std; 
int main()
{
    vector<int> v;      //way to define a vector
    v.push_back(1);     //way to put value in the vector
    v.push_back(2);
    v.push_back(3);

    int size=v.size();      //to store the size of the vector
    int capacity=v.capacity();          //to store the max capacity of the vector

    //vector<int> v(10);  to define the size of the vector behaves as the array

    v.pop_back();       //removes the size of the vector. It only decreases the size not the capacity of the vector

}