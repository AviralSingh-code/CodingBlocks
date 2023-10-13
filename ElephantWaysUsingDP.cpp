#include<iostream>
#include<cstring>
using namespace std;
int elephantWays(int i,int j,int dp[][100])
{
    //base case
    if(i==0&&j==0)
    {
        return dp[i][j]=1;   //value of standing there
    }


    //check before calu.
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }

    //recursive case
    int ans=0;
    for(int k=0;k<i;k++)
    {
        ans=ans+elephantWays(k,j,dp);  //for moving in the column
    }
    for(int k=0;k<j;k++)
    {
        ans=ans+elephantWays(i,k,dp);  //for moving in the column
    }
    return dp[i][j]=ans;
}


int bottomup(int n,int m)
{
    int dp[][100];
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0&&j==0)   //initialization
            {
                dp[i][j]=1;
            }
            else
            {
                int ans=0;      //for every value we are calculating
                for(int k=0;k<n;k++)
                {
                    ans+=dp[k][j];
                }
                for(int k=0;k<m;k++)
                {
                    ans+=dp[i][k];
                }
                dp[i][j]=ans;
            }
        }
    }
    return dp[n][m];    //returns the value at the destination
}


int main()
{
    int dp[100][100];
    memset(dp,-1,sizeof(dp));   //to assign value -1 to the entire array
    int i,j;
    cin>>i>>j;
    cout<<elephantWays(i,j,dp);
    return 0;
}