#include <iostream>
#include <cmath>
using namespace std;
int multiply(int size,int res[],int n)
{
    int carry=0;
    for(int i=0;i<size;i++)
    {
        int product=res[i]*n+carry;
        res[i]=product%10;
        carry=product/10;
    }
    while(carry)
    {
        res[size]=carry%10;
        carry=carry/10;
        size++;
    }
    return size;
}
void fact(int n)
{
    int res[1000];
    int size=1;
    res[0]=1;
    for(int i=2;i<=n;i++)
    {
        size=multiply(size,res,i);
    }
    for(int i=size-1;i>=0;i--)
    {
        cout<<res[i];
    }
}
int main()
{
    int n;
    cin>>n;
    fact(n); 
}

