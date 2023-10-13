#include<iostream>
#include<cstring>
using namespace std;
char s1[100],s2[100];
int lcs(int i,int j)   //i is for s1 and j is for s2
{
    //base case
    if(s1[i]=='\0'||s2[j]=='\0')
    {
        return 0;   //for the length of the subsequence will be 0 if no match
    }


    //recursive case
    if(s1[i]==s2[j])
    {
        return 1+lcs(i+1,j+1);  //the first element for both matches and so we check the second place
    }   //+1 is for the length of the matching first element
    else
    {
        return max(lcs(i+1,j),lcs(i,j+1));  //once we move i and keep j at the same location and in the second case we move j and i constant
    }
}


int bottomUp()
{
    int dp[100][100]={0};
    int n=strlen(s1);
    int m=strlen(s2);
    for(int i=1;i<=n;i++)       //starting from 1 for valid index in i-1 condition
    {
        for(int j=1;j<=m;j++)
        {
            if(s1[i-1]==s2[j-1])    //as we are on the first index but we are checking for 1 index before this therefore we use i-1 and j-1
            {
                dp[i][j]=1+dp[i-1][j-1];    //if it matches then we reduce the length of both the strings and as we have previously calculated for the reduced length  so we use that
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);    //if the elements at the current location are not matching then then we first move i back and then we move j back
            }//s1= aabca  s2=aab then i and j points to a and b at the end respectively so when they don't match then we move back i first and then we move j back and check which is giving max output
        }
    }
    return dp[n][m];
}


int main()
{
    cin>>s1>>s2;
    //cout<<lcs(0,0); //starting index of both the strings


    cout<<endl;
    cout<<"Bottom up approach"<<endl;
    cout<<bottomUp();
}