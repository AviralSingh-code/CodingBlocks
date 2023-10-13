#include<iostream>
#include<cstring>
using namespace std;
int nstaircase(int n,int k,int *dp)
{
    //base case
    if(n==0)    //on the zeroth level
    {
        return dp[n]=1;
    }
    if(n<0)
    {
        return 0;   //as this does not exist
    }


    if(dp[n]!=-1)   //check before calculation
    {
        return dp[n];
    }

    //recursive case
    int ans=0;
    for(int l=1;l<=k;l++)   //to add value k steps behind it
    {
        ans=ans+nstaircase(n-l,k,dp);  //if it can take at max 4 steps so we will add the value just 4 steps behind the current step 
    } 

    return dp[n]=ans;
}



int nstaircaseOptimized(int n,int k)
{
    int dp[1000];
    dp[0]=dp[1]=1;  //initialization for the first two ----> important
    for(int i=2;i<=n;i++)
    {
        if(i-1-k>=0)    //logic--> dp[i+1]=dp[i]-dp[i-k]+dp[i] --> therefore for i put i=i-1;
        {   //we have done i-1-k>=0 so that we don't access invalid index
            dp[i]=2*dp[i-1]-dp[i-1-k];
        }
        else
        {
            dp[i]=2*dp[i-1];
        }
    }

    return dp[n];
}



int bottonUp(int n,int k)
{
    int dp[1000];
    memset(dp,-1,sizeof(dp));
    dp[0]=1;    //initialization
    for(int i=1;i<=n;i++)
    {
        int ans=0;
        for(int j=1;j<=k;j++)
        {
            if(i>=j)    //if i>=j then only we can move back on the array otherwise if will gol on an invalid index
            {
                ans=ans+dp[i-j];
            }
        }
        dp[i]=ans;  //assigning value to dp
    }
    return dp[n];
}


int main()
{
    int dp[1000];
    memset(dp,-1,sizeof(dp));
    int n,k;
    cin>>n>>k;
    cout<<nstaircase(n,k,dp);

    cout<<endl;
    cout<<"For bottom up approach :"<<endl;
    cout<<bottonUp(n,k);


    cout<<endl;
    cout<<"For the optimized approach :"<<endl;
    cout<<nstaircaseOptimized(n,k);
    return 0;
}