#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
bool canweplacethequeen(int board[][50],int i,int j, int n)
{
    //vertical column 
    for(int k=0;k<n;k++)
    {
        if(board[k][j]==1)
        {
            return false;
        }
    }

    //horizontal row
    for(int k=0;k<n;k++)
    {
        if(board[i][k]==1)
        {
            return false;
        }
    }

    //right diagonal
    int r=i,c=j;        //to hold the values of i and j as it is modified after this.
    while (i>=0&&j<n)
    {
        if(board[i][j]==1)
        {
            return false;
        }
        i--;
        j++;
    }

    //left diagonal
    i=r;
    j=c;
    while (i>=0&&j>=0)
    {
        if(board[i][j]==1)
        {
            return false;
        }
        i--;
        j--;
    }
    
    return true;//returns true when we are not able to find any other queen in the row, column, diagonals that can attack the placed one.
    
}
bool nqueen(int board[][50], int i, int n)
{
    //base case
    if(i==n)            //when the pointer i moves out of the rows i.e i==n (and not i==n-1) then it is time to print the board.
    {
        for(int k=0;k<n;k++)
        {
            for(int l=0;l<n;l++)
            {
                if(board[k][l]==1)
                {
                    cout<<"Q"<<" ";
                }
                else
                {
                    cout<<"-"<<" ";
                }
            }
            cout<<endl;
        }
        return true;        //to return true, that we were able to find such a pattern to place the queens according to the constraints.
    }
    

    //recursive case
    for(int j=0;j<n;j++)        //we are doing work for 1 row and rest of the work is done by recursion
    {
        if(canweplacethequeen(board,i,j,n)==true)   //condition to check whether we could actually place the queen at a particular location
        {
            board[i][j]=1;
            bool areotherqueensplacedcorrectly=nqueen(board,i+1,n);//work of recursion to place the queens in the i+1 row correctly
            if(areotherqueensplacedcorrectly==true) //if recursion is able to place the queens once we have place 1 queen in the above location
            {       //then it returns true to the main method that it has been able to form the combination
                return true;
            }
        }
        board[i][j]=0;      //Backtracking. We place 0 a again if we are not able to place the queen at a particular location
    }
    return false;           //if we scan the entire row and we are not able to place the queen at any location then we return false
}
int main()
{
    int board[50][50]={(0,0)};
    int n;
    cin>>n;
    bool ans=nqueen(board,0,n);
    if(ans==false)
    {
        cout<<"No Solution"<<endl;
    }
}