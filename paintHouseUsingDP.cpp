#include<iostream>
using namespace std;
int dp[100][3];
/*In this algortihm it is filling the first row of the dp with the initial cost of the 
painting the first house now we take that if we paint the second house red then the previous house should be either 
green or blue and we take the min of the two options and add the cost of painting the 2nd house red with the min
of the two options and place it in the dp ----> we repeat the same process for the other colours*/
int mincost(int cost[100][3],int rows)  
{
    for(int i=0;i<rows;i++)
    {
        dp[0][i]=cost[0][i];
    }
    for(int i=1;i<rows;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(j==0)
            {
                dp[i][j]=cost[i][j]+min(dp[i-1][1],dp[i-1][2]);
            }
            else if(j==1)
            {
                dp[i][j]=cost[i][j]+min(dp[i-1][0],dp[i-1][2]);
            }
            else if(j==2)
            {
                dp[i][j]=cost[i][j]+min(dp[i-1][0],dp[i-1][1]);
            }
        }
    }

    return min(dp[rows-1][0],min(dp[rows-1][1],dp[rows-1][2]));

}
int main()
{
    cout<<"Enter the number of rows and columns"<<endl;
    int rows,columns;
    cin>>rows>>columns;
    int cost[100][3];
    cout<<"Enter the cost matrix : "<<endl;
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<columns;j++)
        {
            cin>>cost[i][j];
        }
    }

    cout<<mincost(cost,rows);
}