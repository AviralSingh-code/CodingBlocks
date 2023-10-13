#include<iostream>
#include<climits>
using namespace std;

int topDownminStepstoOne(int n,int *dp)
{
    //base case
    if(n==1)
    {
        dp[n]=0;    //store before return
        return 0;   //as we have already reached 1
    }

    //check before calculation
    if(dp[n]!=-1)   //means already calculated
    {
        return dp[n];
    }

    //resursive case
    int op1,op2,op3;
    op1=op2=op3=INT_MAX;    //as we have to min of the three options then we need to initialize it with INT_MAX 
    /*we are doing the 3rd option first because for this recursion moves down and gets the value of every no less than n eg if
    n=10 the n-1 operation will get the value of 9,8,7,6,5,4,3,2,1 so when we start on with other operations i.e n/3 or n/2 we will get some value in this range only so
    we have done this first*/

    /*applying dp reduces time complexity from O(3^(N-1)) --> O(3^N) to O(3N) --> O(N)*/
    op3=topDownminStepstoOne(n-1,dp); //as if it is placed after the op1 and op2 it will never go there so to avoid   GREEDY approach we take this on top
    if(n%3==0)
    {
        op1=topDownminStepstoOne(n/3,dp);
    }
    else if(n%2==0)
    {
        op2=topDownminStepstoOne(n/2,dp);
    }

        //store before store

        return dp[n]=min(op1,min(op2,op3))+1;   //it returns min of op1, op2 and op3. +1 as we have done 1 step
}


int bottomUP(int n)
{
    int *dp=new int[n+1];
    dp[1]=0;    //base case of top down is initializattion condition here
    int op1,op2,op3;
    for(int i=2;i<n+1;i++)
    {
        op1=op2=op3=INT_MAX;    //for every option
        op1=dp[i-1];    //for 2 it will give 0 but while assigning we are adding 1
        if(i%2==0)
        {
            op2=dp[i/2];
        }
        if(i%3==0)
        {
            op3=dp[i/3];
        }
        dp[i]=min(op1,min(op2,op3))+1;  //ADDING 1 OVER HERE
    }
    int ans=dp[n];
    delete [] dp;   //as we have created it using DMA
    return ans;
}


int main()
{
    int n;
    cin>>n;
    int *dp=new int[n+1];
    for(int i=0;i<n+1;i++)
    {
        dp[i]=-1;
    }
    cout<<topDownminStepstoOne(n,arr);

    cout<<endl;
    cout<<"Using bottomup approach :"<<endl;
    cout<<bottomUP(n);
    return 0;
}