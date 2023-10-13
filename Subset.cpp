#include <iostream>
#include <cmath>
using namespace std;
int main()
{
 int t;
 cin>>t;
 int hold=t;
 string ans[t];
 int count=0;
 while(t)
 {
     int n;
     cin>>n;
     int arr[n];
     for(int i=0;i<n;i++)           //Initializing the array
     {
         cin>>arr[i];
     }
     int a=((int)pow(2,n))-1;       //To get the number of NON Empty subsets
     for(int i=1;i<=a;i++)      //To get the numbers from 1 to the number of subsets
     {
         int sum=0;
         int pos=0;
         int value=i;
         while(value)               //To find the set bit of the number 
         {
             if(value&1)
             {
                 sum=sum+arr[pos];      //The corresponding element from the array is added to the sum where we get a set bit
             }
             pos++;
             value=value>>1;
         }
         if(sum==0)
         {
             ans[count]="Yes";
             count++;
             break;
         }
         else if(sum!=0&&i==a)
         {
             ans[count]="No";
             count++;
             break;
         }
     }
     t--;
 }
 for(int i=0;i<hold;i++)
 {
     cout<<ans[i]<<endl;
 }
}
