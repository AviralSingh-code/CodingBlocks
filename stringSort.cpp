#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
bool compare(string a,string b)         //comparator function to get the sorting in a particular way
{
    if(a<b)             //to get it in the lexicographical order
    {
        return true;
    }
    else if(a.length()>=b.length()&&(a.substr(0,b.length())==b))        //to get if the string is prefix of the other
    {
        return true;
    }
    return false;           //as we have defined a return type then it is important to define a return type outside the if condition
}
int main()
{
    int n;
    cin>>n;
    string arr[1005];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n,compare);        //use of comparator function
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<endl;
    }
}