#include<iostream>
#include<algorithm>
using namespace std;
int sol[][10]={0};
bool ratinamaze(char maze[][10],int i,int j,int m,int n)
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



    //recursive case
    sol[i][j]=1;
    if(j+1<m&&maze[i][j+1]!='X')
    {
        bool ans=ratinamaze(maze,i,j+1,m,n);
        if(ans==true)
        {
            return true;
        }
    }

    if(i+1<n&&maze[i+1][j]!='X')
    {
        bool ans=ratinamaze(maze,i+1,j,m,n);
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
        }
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