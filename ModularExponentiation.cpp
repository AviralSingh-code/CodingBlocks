#include <iostream>
#define m 1000000007
using namespace std;
long long int calpower(long long int a,long long int b)
{
    if(b==0)
    {
        return 1;
    }

    if(b%2==0)
    {
        return calpower((a*a)%m,b>>1)%m;
    }
    else
    {
        return (a* calpower((a*a)%m,b>>1)%m);
    }
}
int main() {
    int a,b;
    cin>>a>>b;
    cout<<calpower(a,b);
}
