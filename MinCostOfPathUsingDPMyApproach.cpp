#include <iostream>
#include<climits>
using namespace std;
int costPath(int cost[][4],int i,int j,int dp[100][100],int desi,int desj)
{
    //base case
    if(i==desi&&j==desj)
    {
        return dp[i][j]=cost[i][j];
    }


    //recursive case
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }

    int op1,op2;
    op1=op2=INT_MAX;
    if(j!=3)
    {
       op1=cost[i][j+1];
    }

    if(i!=3)
    {
       op2=cost[i+1][j];
    }
 

    if(op1<op2)
    {
        return dp[i][j]=cost[i][j]+costPath(cost,i,j+1,dp,desi,desj);
    }
    else
    {
        return dp[i][j]=cost[i][j]+costPath(cost,i+1,j,dp,desi,desj);
    }
}


int main() {
    int cost[][4]={
        {2,1,3,4},
        {3,1,1,10},
        {1,6,1,1},
        {2,7,4,3}
    };

    int dp[100][100];
    memset(dp,-1,sizeof(dp));   //to put -1 to all the locations of the array
    int i=0,j=0;    //for source
    int desi=3,desj=3;//for destination
    cout<<costPath(cost,i,j,dp,desi,desj);
}
