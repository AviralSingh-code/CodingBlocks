#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#define ll long long
using namespace std;
int main()
{
    ll n;
    cin>>n; 
    ll a[n];
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
    }
    ll k;
    cin>>k;
    sort(a,a+n);    //to sort the element for it to be internally sorted
    vector<vector<ll>>ans;//creating a 2D vector
    ll m=pow(2,n);//1<<n --> we can use this  --> to get the max no of subsequence
    for(ll i=1;i<m;i++)    //leaving out the  0 0 0 susequence
    {
        ll c=i;    //to prevent i from getting changed
        ll j=0;        //pointer of the array
        ll cnt=0; //to get the current sum
        vector<ll>v;   //to hold the temp subsequence
        while(c>0)      //to get set bit --> so that we can get the subsequence
        {
            if(c&1)
            {
                cnt=cnt+a[j];
                v.push_back(a[j]);
            }
            c=c>>1;
            j++;
        }
        if(k==cnt)  //if sum of the elements gets equal to target
        {
            if(binary_search(ans.begin(),ans.end(),v)==1)   //if that vector is already present in the ans then continue
            {
                continue;
            }
            ans.push_back(v);//otherwise push it into the ans array
            sort(ans.begin(),ans.end());
        }
    }
    for(ll i=0;i<ans.size();i++)   //for vertical motion
    {
        for(ll j=0;j<ans[i].size();j++)        //for horizontal motion
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}