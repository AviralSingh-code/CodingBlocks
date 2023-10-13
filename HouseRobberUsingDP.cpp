#include<iostream>
#include<cmath>
using namespace std;

int houserobberBottomUp(int *nums,int length)
{
    if(length==0)
    {
        return 0;
    }
    if(length==1)
    {
        return nums[0];
    }

    if(length==2)
    {
        return max(nums[0],nums[1]);
    }

    int *dp=new int[length];
    dp[0]=nums[0];  //as the index is one less than the number of houses therefore 0 represents one house
    dp[1]=max(nums[0],nums[1]); //1 represents two houses
    for(int i=2;i<length;i++)
    {
        dp[i]=max(nums[i]+dp[i-2],dp[i-1]); //either we take the current element with nums[i] and add dp[i-2] ---> leaving the previous element or we can either leave this element and take just the previous element only
    }

    return dp[length-1];       //as the index is off by one element so we take length-1 for the last element
}

int main()
{
    int n;
    cin>>n;
    int nums[n];
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    cout<<houserobberBottomUp(nums,n);
    return 0;
}