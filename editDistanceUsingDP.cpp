#include<iostream>
#include<cstring>
using namespace std;
int editDistance(char *s1,char *s2,int i,int j, int dp[][100])
{
    //base case
    if(i==0&&j!=0)      //i is length of s1
    {
        return dp[i][j]=j;// we will have to insert or delete the length of the second array if the first one is totally exhausted so we return j
    }
    if(i!=0&&j==0)  //if s1 is not empty and s2 is empty then we have to convert the s2 to s1 and so we need to perform add all the elements s1 left to s2 --> and so the cost is equal to the number of element 
    {
        return dp[i][j]=i;  //if the first string is empty then to transform the second to first we can del the elements
    }

    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }

    // recursive case
    if(s1[i-1]==s2[j-1])
    {
        return editDistance(s1,s2,i-1,j-1,dp); //if both same we move both the pointers 
    }
    else
    {
       int op1=editDistance(s1,s2,i-1,j-1,dp)+1;      //replace --> +1 as we have performed 1 operation and then we pass the rest of the string to recursion
       int op2=editDistance(s1,s2,i,j-1,dp)+1;   //insert
       int op3=editDistance(s1,s2,i-1,j,dp)+1;       //delete

       return dp[i][j]=min(op1,min(op2,op3));
    }
}


int bottomUp(char*s1,char*s2,int i,int j)
{
    int dp[100][100];
    dp[0][0]=0;     //initialization
    for(int k=1;k<=i;k++)
    {
        dp[0][k]=dp[0][k-1]+1;
    }
    for(int k=1;k<=i;k++)
    {
        dp[k][0]=dp[k-1][0]+1;
    }
    for(int k=1;k<=i;k++)
    {
        for(int l=1;l<=j;l++)
        {
            if(s1[i-1]==s2[j-1])
            {
                dp[i][j]=dp[i-1][j-1];
            }
            else
            {
                min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j]));
            }
        }
    }

    cout<<"The dp is:"<<endl;


    for(int k=1;k<=i;k++)
    {
        for(int l=1;l<=j;l++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    return dp[i][j];
}


int main()
{
    char s1[1000],s2[1000];
    cin>>s1>>s2;
    int dp[100][100];
    memset(dp,-1,sizeof(dp));
    int i=strlen(s1);
    int j=strlen(s2);
    cout<<editDistance(s1,s2,i,j,dp);


    cout<<endl;
    cout<<"The botton up approach is :"<<endl;
    cout<<bottomUp(s1,s2,i,j);

    return 0;
}