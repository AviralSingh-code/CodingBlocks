#include<iostream>
#define ll long long int
using namespace std;
/*if n is even, our triplets are calculated by formula (n^2/4 - 1)^2 + n^2 = (n^2/4 + 1)^2 
if n is odd, our triplets are calculated by formula (n^2-1)^2/2 + n^2 = (n^2+1)^2/2 */
void caltriplet(ll n)
{
    if(n==1||n==2)      //pythagoras triplets exists for every number other than 1 and 2
    {
        cout<<-1;
        return;
    }
    
    if(n%2==0)
    {
        ll var = n*n/4;
        cout<<var-1<<" "<<var+1;
    }

    if(n%2!=0)
    {
        ll var=n*n+1;
        cout<<var/2-1<<" "<<var/2;
    }
}

int main()
{
    ll n;
    cin>>n;
    caltriplet(n);
}