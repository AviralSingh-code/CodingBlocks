#include<iostream>
#include<climits>
using namespace std;
int minden(int *coins,int amount,int n) //recursive 
{
    //base case
    if(amount==0)
    {
        return 0;
    }

    //recursive case
    int ans=INT_MAX;    //we have to store min so initialized with INT_MAX
    for(int i=0;i<n;i++)
    {
        if(amount-coins[i]>=0)  //can we substract the value of the coin from the amount
        {
            int chotaamount=amount-coins[i];
            int chotaans=minden(coins,chotaamount,n);   //now the amount is chotaamount so we pass that in the function
            if(chotaans!=INT_MAX&&chotaans<ans) //!= INT_MAX shows we can find the denominations
            {
                ans=chotaans+1;//+1 as we have done 1 work
            }
        }
    }
    return ans;
}


int topDownMin(int *coins,int amount,int n,int *dp)
{
    //base case
    if(amount==0)
    {
        dp[0]=0;
        return 0;
    }


    if(dp[amount]!=-1)
    {
        return dp[amount];
    }

    //recursive case
    int ans=INT_MAX;
    for(int i=0;i<n;i++)
    {
        if(amount-coins[i]>=0)
        {
            int chotaamount=amount-coins[i];
            int chotaans=topDownMin(coins,chotaamount,n,dp);
            if(chotaans!=INT_MAX&&chotaans<ans)
            {
                ans=chotaans;
            }
        }
    }
    return dp[amount]=ans;
}



int bottomup(int *coins,int amount,int n)
{
    int *dp=new int[amount+1];  //amount denotes like for 10 we will have numbers from 0 to 10 and n shows the size of the coin array --> it is the number of valid denominations
    for(int i=0;i<amount+1;i++)
    {
        dp[i]=INT_MAX;  //because we have to store minimum so initially initialize INT_MAX
    }

    //initialization
    dp[0]=0;
    for(int rup=1;rup<=amount;rup++)    //for tracking amount array for eg 0 to 10
    {
        for(int i=0;i<n;i++)    //for checking coins for each amount --> moving on the coin array
        {
            if(rup-coins[i]>=0) //checking for a valid coin
            {
                int chotaamount=rup-coins[i];
                dp[rup]=min(dp[chotaamount]+1,dp[rup]); //dp[chotaamount]+1 --> shows like for eg if we have amount = 7 and we substract 5 from it --> we have done one step in substraction --> we are left with 7-5=2 so we check what is the solution for 2 using dp[2] --> as this holds the solution --> and we add 1
            }
        }
    }
    return dp[amount];
}



int main()
{
    int coins[]={1,3,5,10};
    int n=sizeof(coins)/sizeof(int);
    int amount;
    cin>>amount;
    
    cout<<minden(coins,amount,n);


    int dp[1000];
    for(int i=0;i<1000;i++)
    {
        dp[i]=-1;
    }

    cout<<topDownMin(n,dp);
}