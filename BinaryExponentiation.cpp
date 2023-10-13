#include <iostream>
#include <cmath>
#include<climits>
using namespace std;
int main()
{
    long long int a;
    cin>>a;
    long long int b;
    cin>>b;
    long long int carry=1;
    while (b>1)
    {
        if(b%2==0)
        {
            a=a*a;
            b=b/2;
        }
        else
        {
            carry=carry*a;
            a=a*a;
            b=(b-1)/2;
        }
    }
    cout<<(a*carry);
    
    return 0;
    
}