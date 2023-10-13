#include<iostream>
#include<vector>
using namespace std;
int longestincreasingSubsequence(int *a,int n)
{
    int dp[1000]={0};
    for(int i=0;i<1000;i++)
    {
        dp[i]=1;    //because min for 1 element we have 1 subsequence
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(a[i]>a[j])
            {
                dp[i]=max(dp[i],dp[j]+1);   //if element at j is incuded then we get the dp of the element at jth location and we add 1 for the addition of the ith element to the dp
            }
        }
    }
    int ans=1;  //as we know min subseq. length is 1
    int i=0;
    for(int j=0;j<n;j++)
    {
        if(ans<dp[j])
        {
            ans=dp[j];
            i=j;
        }
    }
    vector<int>v;
    int len=ans;    //length of subsequence to be printed
    v.push_back(a[i]);  //pushing the first element --> the element at which i points is the max so we place it
    len--;
    for(int j=i-1;j>=0;j--)
    {
        if(dp[j]==len&&v[v.size()-1]>a[j])  //if the dp of j hold no equal to length then that element is able to form subsequence of the length equal to the value at dp[j] and that element should be smaller than the last element pushed to form reverse of the subsequence
        {
            v.push_back(a[j]);
            len--;
            if(len==0)
            {
                break;
            }
        }
    }

    //to print the largest increasing subsequence
    for(int i=v.size()-1;i>=0;i--)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;

    return ans;
}
int main()
{
    int a[]={1,3,2,6,4,7,3,8};
    int n=sizeof(a)/sizeof(int);
    cout<<longestincreasingSubsequence(a,n);
}