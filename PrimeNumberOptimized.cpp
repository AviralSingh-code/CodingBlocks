#include <iostream>
#include <cmath>
#include<climits>
using namespace std;
int main()
{
    long long int n;
    cin>>n;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            cout<<"Not Prime : "<<n;
            return 0;
        }
    }
    cout<<"Number is Prime :"<<n;
    return 0;
}