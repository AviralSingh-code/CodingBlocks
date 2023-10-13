#include<iostream>
using namespace std;
int coin[40];               //globally declared so that we don't have to pass it to the function
int optimalgame(int i,int j)
{
    //base case
    if(i>j)                 //if the i pointer crosses the j pointer
    {
        return 0;
    }

    //recursive case

    //case 1 when we pick the first element
    /*This case is when we pick the first element then comes the turn of the opponent 
    the opponent picks up the element that leaves minimum value for us to pick so that is why we choose min function*/
    long long int firstPick = coin[i]+min(optimalgame(i+2,j),optimalgame(i+1,j-1)); 

    //case 2
    /*This case is when we pick the last element then comes the turn of the opponent 
    the opponent picks up the element that leaves minimum value for us to pick so that is why we choose min function*/
    long long int secondPick = coin[j]+min(optimalgame(i,j-2),optimalgame(i+1,j-1));

    return max(firstPick,secondPick);       /*we return the max of whether we should choose the first element or the last element to get
                                            the maximum value for us to win*/
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)        //getting the values of the coins
    {
        cin>>coin[i];
    }
    cout<<optimalgame(0,n-1);
}