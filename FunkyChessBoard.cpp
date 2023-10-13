#include<iostream>
#include<climits>       /*DRY RUN THIS AND YOU WILL UNDERSTAND !! IT IS EASY*/
using namespace std;
int grid[10][10];
int dx[8]={1,2,2,1,-2,-2,-1,-1};    //possible jumps in the x direction
int dy[8]={2,1,-1,-2,1,-1,2,-2};//correspoinding jumps in the y directon
int sum=0;  //to store the number of places to which jump is possible
int n;
int N=10;  //to holdgrid size
int ans=INT_MIN;    //to store the max length of the path
void input()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>grid[i][j];
            if(grid[i][j]==1)
            {
                sum++;
            }
        }
    }
}


void knight(int x,int y,int jump)
{
    ans=max(ans,jump);      //every time it gets a path, knight gets called and so to get the max length of the path we use this
    for(int i=0;i<8;i++)    //for moving in the 8 directions
    {
        int xx=x+dx[i]; //for value of destination in the x direction
        int yy=y+dy[i]; //for y direction

        if(xx<=N&&xx>=0&&yy>=0&&yy<=N&&grid[xx][yy]==1) //if all true then the jump is valid
        {
            grid[xx][yy]=0; //as we are standing on this grid now so it is valid already so we put 0 as done previously
            //when knight gets called it will go up again and will keep on checking for a valid path from the destination 
            knight(xx,yy,jump+1);   //calling recursion from the location where we have reached unless we either get 0 or we move out of the grid
            grid[xx][yy]=1; //so that if we now reach this location using some other path then we have to consider this so we have to revert thr change made.
        }
    }
}

int main()
{
    cin>>n; //size input
    input();
    grid[0][0]=0;   //removing point 0,0 from consideration as we are standing on it so it is a already a valid point
    knight(0,0,1);  //0--> for x , 0--> for y positions and 1-->for jumps
    cout<<sum-ans;
    return 0;
}