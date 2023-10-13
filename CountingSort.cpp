#include <iostream>
#include <cmath>
#include<climits>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    int max=INT_MIN;
    //step 1 is to find the max element of the array
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        if(arr[i]>max)              //Finding maximum element in the entered array
        {
            max=arr[i];
        }
    } 
    int res[max+1]={0};             //Creating an array from 0 to max elements as the index
    //step 2 is to store the frequency of all the elements in a array
    for(int i=0;i<n;i++)            
    {   //frequency storing
        res[arr[i]]++;          //increasing one every time (in the res array formed) when an element is aquired in the original array
    }                               //at the index value equal to the array

    //step 3 is to find the prefix sum of the frequency array formed
    for(int i=1;i<=max;i++)         //Finding prefix sum
    {
        res[i]=res[i]+res[i-1];
    }
    int out[n];
    //step 4 is to place the element at their (prefix sum - 1) location and then reduce the frequency 
    for(int i=0;i<n;i++)                //placing the elements at the correct position
    {
        out[res[arr[i]]-1]=arr[i];          //-1 is very important to adjust the index value
        res[arr[i]]--;     //reducing 1 every time from the frequency held in the res arrayafter putting the element in the correct place
    }
    for(int i=0;i<n;i++)
    {
        cout<<out[i]<<" ";
    }
}

