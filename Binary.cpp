#include <iostream>
#include <cmath>
using namespace std;
int main()
{
   int N;
   cin>>N;
   if(N<=1000)
   {
      int arr[N];
      for(int i=0;i<=N-1;i++)
      {
         arr[i]=0;
      }
      cout<<"Enter the number"<<endl;
      for(int i=0;i<=N-1;i++)
      {
         cin>>arr[i];
      }
      for(int i=0;i<=N-1;i++)
      {
         int count = 0;
         int num = arr[i];
         while(num!=0)
         {
         
            count++;
            num=num/10;
         }
         if(count>16)
         {
            return 0;
         }
      }

      for(int i=0;i<=N-1;i++)
      {
         int num = arr[i];
         int k = 0;
         int sum =0;
         while(num!=0)
         {
            int d = num%10;
            sum = sum+(d*pow(2,k));
            k++;
            num=num/10;
         }
         cout<<sum<<endl;
      }

   }
   
}