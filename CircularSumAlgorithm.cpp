#include<iostream>
#include<algorithm> 
#include<climits>
using namespace std;
int main()
{
	  int t;
	  cin>>t;
	  int ans[t];
	  int k=0;
	  while (t--)
	  {
		  int n;
		  cin>>n;
		  int a[n];
		  int b[n];
		  int csum=0;
		  for(int i=0;i<n;i++)
		  {
			  cin>>a[i];
			  b[i]=a[i]*(-1);
			  csum +=a[i];
		  }
		  int cSum=0;
		  int maxSum=INT_MIN;
		  for(int i=0;i<n;i++)
		  {
			  cSum=cSum+a[i];
			  if(cSum<0)
			  {
				  cSum=0;
			  }
			  maxSum=max(maxSum,cSum);
		  }
		  int candidate1=maxSum;
		  cSum=0;
		  maxSum=INT_MIN;
		  for(int i=0;i<n;i++)
		  {
			  cSum=cSum+b[i];
			  if(cSum<0)
			  {
				  cSum=0;
			  }
			  maxSum=max(maxSum,cSum);
		  }
		  int hold=maxSum;
		  int candidate2=csum-(-hold);
		  ans[k]=max(candidate1,candidate2);
		  k++;
	  }
	  for(int i=0;i<k;i++)
	  {
		  cout<<ans[i]<<endl;
	  }
}

