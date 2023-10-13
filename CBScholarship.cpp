#include<iostream>
using namespace std;
long long int n,m,x,y;
long long int ans;
bool wecandothis(int mid)
{
    return (mid*x<=m+(n-mid)*y);        //to add the number of coupons to the total number of coupons of those who perform badly
}
int main()
{
    cin>>n>>m>>x>>y;
    long long int si=0;
    long long int ei=n;
    while (si<=ei)
    {
        long long int mid=(si+ei)/2;
        if(wecandothis(mid)==true)
        {
            ans=mid;
            si=mid+1;
        }
        else
        {
            ei=mid-1;
        }
    }
    cout<<ans;
    return 0;
}