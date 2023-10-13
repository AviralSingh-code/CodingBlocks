#include<iostream>
#include<climits>
using namespace std;
int main()
{
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++)
  {
    cin>>arr[i];
  }
  for(int i=1;i<=n-1;i++)
  {
      int count=0;
    for(int j=0;j<=n-i-1;j++)               //Notice the n-i-1 for the j loop
    {
      if(arr[j]>arr[j+1])
      {
        arr[j]=arr[j]+arr[j+1];
        arr[j+1]=arr[j]-arr[j+1];
        arr[j]=arr[j]-arr[j+1];
        count++;                   //if this loop gets executed count gets increased by one and so this indicates that the array is not sorted
      }
    }
    if(count==0)                            //This is to end the loop as soon as the array gets sorted
    {
      break;
    }
  }
  for(int i=0;i<n;i++)
  {
    cout<<arr[i]<<" ";
  }

}