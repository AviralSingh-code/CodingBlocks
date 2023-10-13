#include <iostream>
#include <cmath>
#include<algorithm>
#include<climits>
using namespace std;
int main()                              //To get the max subarray sum
{
   int arr[100];
   int n;
   cin>>n;
   int currSum=0;
   int maxSum=0;
   for(int i=0;i<n;i++)         //This algorithm fails when all the elemnets in the array are negative
   {
       cin>>arr[i];
   }
   for(int i=0;i<n;i++)
   {
       currSum=currSum+arr[i];              //We keep on storing the value in sum unless it becomes negative 
       if(currSum<0)
       {
           currSum=0;
       }
       maxSum=max(maxSum,currSum);              //We keep on maintaining the max sum
   }
   cout<<maxSum;
}