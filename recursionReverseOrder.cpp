#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
string s[]={"zero","one","two","three","four","five","six","seven","eight","nine"};
void convert(int n)
{
    if(n==0)
    {
        return;
    }
    int d=n%10;
    convert(n/10);
    cout<<s[d]<<" ";            //to reverse print order

}
int main()
{
    int n;
    cin>>n;
    convert(n);
    return 0;
}