#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int countdigit(int num)
{
    int count=0;
    while(num!=0)
    {
        count++;
        num=num/10;
    }
    return count;
}
int main()
{
    int t;
    cin>>t;
    string ans[200];
    int k=0;
    while (t--)
    {
        int n;
        cin>>n;
        int arr[200];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        for(int i=0;i<=n-2;i++)
        {
            for(int j=0;j<=n-2-i;j++)
            {
                int a=arr[j];
                int b=arr[j+1];
                int digitcounta=countdigit(a);
                int digitcountb=countdigit(b);
                int no1=a*pow(10,digitcountb)+b;
                int no2=b*pow(10,digitcounta)+a;
                if(no1>no2)
                {
                    swap(arr[j],arr[j+1]);
                }

            }
        }
        string number="";
        for(int i=n-1;i>=0;i--)
        {
            number=number+to_string(arr[i]);
        }
        ans[k]=number;
        k++;
    }
    for(int i=0;i<k;i++)
    {
        cout<<ans[i]<<endl;
    }   
}