#include <iostream>
#include <cmath>
using namespace std;
int main()
{
   int n;
   cin>>n;
   int arr[n];
   int j=0;
   for(int i=0;i<n;i++)
   {
       cin>>arr[i];
   }
   for(int i=1;i<n;i++)
   {
       int curr=arr[i];
       for(j=i-1;j>=0&&arr[j]>curr;j--)
       {
           arr[j+1]=arr[j];
       }
       arr[j+1]=curr;
   }
   for(int i=0;i<n;i++)
   {
       cout<<arr[i]<<" ";
   }
}

