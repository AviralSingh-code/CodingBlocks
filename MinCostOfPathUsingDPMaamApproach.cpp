#include<iostream>
#include<climits>
#include<cstring>
using namespace std;

int topDown(int cost[][4],int i,int j,int dp[][100])
{
    //base case
    if(i==0&&j==0)
    {
        return dp[i][j]=cost[i][j];
    }
    //eg if it reaches the top right corner of the matrix then when it compared with the element left to it that element in the left should get selected
    if(i<0||j<0)
    {
        return INT_MAX; //it returns int max so that in comparison this never gets selected with the other element in consideration
    }

    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }


    //recursive case
    int op1=topDown(cost,i,j-1,dp);
    int op2=topDown(cost,i-1,j,dp);

    return dp[i][j]=min(op1,op2)+cost[i][j]; //cost of i and j is the cost of the current location
}



int bottomUp(int  cost[][4],int i,int j)
{
    int dp[100][100];
    dp[0][0]=cost[0][0];    //initialization for the first cell
    /*
    the main idea behind this is first we assign value to the first row and first column
    and then we calculate the value of every cell of dp by checking it with top element to it and 
    the left element to it for the top path and path from the left to the current cell
    */
    for(int i=1;i<4;i++)
    {
        dp[0][i]=cost[0][i]+dp[0][i-1]; //to fill the first row
    }
    for(int i=1;i<4;i++)
    {
        dp[i][0]=cost[i][0]+dp[i][0];   //to fill the first column
    }

    for(int i=1;i<4;i++)
    {
        for(int j=1;j<4;j++)
        {
            int op1=dp[i-1][j];
            int op2=dp[i][j-1];
            dp[i][j]=cost[i][j]+min(op1,op2);
        }
    }
    return dp[i][j];    //i and j used is not the same as used for loop as the i and j defined is within the scope of the function and these i and j are of the destination
}




int main()
{
    int cost[][4]={
        {2,1,3,4},
        {3,1,1,10},
        {1,6,1,1},
        {2,7,4,3}
    };

    // int dp[100][100];
    // for(int i=0;i<100;i++)
    // {
    //     for(int j=0;j<100;j++)
    //     {
    //         dp[i][j]=-1;
    //     }
    // }

    // memset(dp,-1,sizeof(dp));   //to put -1 to all the locations of the array
    int i=2,j=3;    //for destination
    // cout<<topDown(cost,i,j,dp);


    cout<<"Using bottom up approach :"<<endl;
    cout<<bottomUp(cost,i,j);
}