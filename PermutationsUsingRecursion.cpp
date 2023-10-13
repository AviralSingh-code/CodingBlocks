#include<iostream>
#include<algorithm>
using namespace std;
void permutation(char *arr,int i)
{
    //base case
    if(arr[i]=='\0')            //as the counter i reaches the end the print the string
    {
        cout<<arr<<endl;
        return;
    }

    //recursive case
    for(int j=i;arr[j]!='\0';j++)       //for one counter that moves from i to the last till it finds null
    {
        swap(arr[i],arr[j]);            //swapping the elements eg. abc becomes bac when j=i+1
        permutation(arr,i+1);  //permutation on rest of the string i.e. for abc---> bca--->we are concerned about only ca that is why we use i+1 
        swap(arr[i],arr[j]);    //Backtracing to reset the array and to nullify all the swapping
        //as array is passed by reference then any change in the array causes a permanent change
    }
}
int main()
{
    char arr[10];
    cin>>arr;
    permutation(arr,0);
}