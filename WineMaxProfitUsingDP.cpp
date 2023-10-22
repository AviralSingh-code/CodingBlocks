#include<iostream>
using namespace std;


int wineMaximumProfit(int l,int r,int *price,int day)
{
    //base case
    if(l>r)
    {
        return 0;   //when no bottle then no profit
    }



    //recursive case
    int op1=price[l]*day+wineMaximumProfit(l+1,r,price,day+1);    //for taking first element
    

    int op2=price[r]*day+wineMaximumProfit(l,r-1,price,day+1);


    return max(op1,op2);

}


int topDown(int l,int r,int*price,int day,int dp[][100])   //as the value of dp depends on 2 parameters l and r then it is 2D dp
{
    //base case
        if(l>r)
        {
            return dp[l][r]=0;  //storing before returning
        }

        //check before calculating
        if(dp[l][r]!=-1)
        {
            return dp[l][r];
        }


    //recursive case
    int op1=price[l]*day+topDown(l+1,r,price,day+1,dp);

    int op2=price[r]*day+topDown(l,r-1,price,day+1,dp);


    return dp[l][r]=max(op1,op2);   //storing before returning
}


int bottomUp(int *price,int n)
{
    int dp[100][100]={0};   //putting 0 at every place
    for(int i=0;i<n;i++)
    {
        dp[i][i]=price[i]*n;    //for getting the diagonal elements --> check class notes 
    }

    for(int i=n-2;i>=0;i--)     //check class notes ----> case 4 
    {
        for(int j=0;j<n;j++)
        {
            if(i<j)
            {
                int day=n-j-i;
                int op1=day*price[i]+dp[i+1][j];
                int op2=day*price[j]+dp[i][j-1];
                dp[i][j]=max(op1,op2;)
            }
        }
    }
    return dp[0][n-1];  //returns the block for example 0,4 block of the matrix
}


int main()
{
    int price[]={2,3,5,1,4};  //price array
    int n=sizeof(price)/sizeof(int);
    int day=1;  //initially
    cout<<wineMaximumProfit(0,n-1,price,day);       //0--> for left pointer n-1 --> for right pointer
    int dp[100][100];
    for(int i=0;i<100;i++)
    {
        for(int j=0;j<100;j++)
        {
            dp[i][j]=-1;
        }
    }


    cout<<endl;
    cout<<"Top Down approach using DP :"<<endl;
    cout<<topDown(0,n-1,price,day,dp);
}