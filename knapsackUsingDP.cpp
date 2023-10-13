#include<iostream>
#include<climits>
#include<cstring>
using namespace std;
int knapsack(int *price,int *weight,int capacity,int n,int dp[][100])
{
    //base case
    if(n==0||capacity==0)
    {
        return dp[n][capacity]=0;
    }


    if(dp[n][capacity]!=-1)
    {
        return dp[n][capacity];
    }
    
    //recursive case
    int op1=INT_MIN;
    int op2=INT_MIN;
    op1=0+knapsack(price,weight,capacity,n-1,dp);  //if we are excluding the item
    if(capacity>=weight[n-1])   //only includes when there is space left
    {
        op2=price[n-1]+knapsack(price,weight,capacity-weight[n-1],n-1,dp);     //if we are including then we have put that element into the bag and so we do capacity=capacity-weight[n-1]
    }
    return dp[n][capacity]=max(op1,op2);
}


int bottomup(int *price,int *weight,int tcap,int tn)    //tcap is the total capacity and tn is the total number of elements
{
    int dp[100][100]={0};   //as if the capacity is 0 or the number of items is zero the max profit is 0
    for(int n=1;n<=tn;n++)
    {
        for(int ccap=1;ccap<=tcap;ccap++)       //ccap is the current capacity
        {
            int op1=INT_MIN;
            int op2=INT_MIN;
            if(ccap>=weight[n-1])
            {
                op1=price[n-1]+dp[n-1][ccap-weight[n-1]];  //if we include the item then we add its price and we reduce the left capacity and the number of items
            }
            op2=0+dp[n-1][ccap];    //we dont include the element

            dp[n][ccap]=max(op1,op2);   //taking the max of the two options
        }
    }
    return dp[tn][tcap];    //return the value of the index required
}



int main()
{
    int price[]={4,5,8,1};
    int weight[]={1,3,5,1};
    int n=sizeof(weight)/sizeof(int);
    int dp[100][100];
    memset(dp,-1,sizeof(dp));       //we cannot use this dynamically defined DP array
    int capacity=5;
    cout<<knapsack(price,weight,capacity,n,dp);

    cout<<endl;
    cout<<"The result of the bottomup approach :"<<endl;
    cout<<bottomup(price,weight,capacity,n);
    return 0;
}