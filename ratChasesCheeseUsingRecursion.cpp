#include<iostream>
#include<algorithm>
using namespace std;
int sol[100][100]={0};
int visited[100][100]={0};      //to remember the location already visited
bool ratinamaze(char maze[10][10],int i,int j,int m,int n)
{
    //base case
    if(i==n-1&&j==m-1)
    {
        sol[i][j]=1;
        for(int k=0;k<n;k++)
        {
            for(int l=0;l<m;l++)
            {
                cout<<sol[k][l];
            }
            cout<<endl;
        }
        return true;
    }

    if(visited[i][j]==1)        //to return false if the location is already visited
    {
        return false;
    }

    //recursive case
    visited[i][j]=1;
    sol[i][j]=1;
    if(j+1<m&&visited[i][j+1]!=1)
    {
        bool ans=ratinamaze(maze,i,j+1,m,n);
        if(ans==true)
        {
             return true;
        }
    }


    if(i+1<n&&visited[i+1][j]!=1)
    {
        bool ans=ratinamaze(maze,i+1,j,m,n);
        if(ans==true)
        {
            return true;
        }
    }

    if(i>0&&visited[i-1][j]!=1)
    {
        bool ans=ratinamaze(maze,i-1,j,m,n);
            if(ans==true)
            {
                return true;
            }
    }

    if(j>0&&visited[i][j-1]!=1)
    {
        bool ans=ratinamaze(maze,i,j-1,m,n);
            if(ans==true)
            {
                return true;
            }
    }

    sol[i][j]=0;
    return false;
}
int main()
{
    int n,m;
    cin>>n>>m;
    char maze[10][10];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>maze[i][j];
            if(maze[i][j]=='X')
            {
                visited[i][j]=1;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<visited[i][j];
        }
        cout<<endl;
    }
    bool value=ratinamaze(maze,0,0,m,n);
    if(value==false)
    {
        cout<<"Path does not exist"<<endl;
    }
    else
    {
        cout<<"Path exists"<<endl;
    }
    return 0;
}