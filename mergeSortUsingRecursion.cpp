#include<iostream>
#include<cstring>
#include<algorithm>
#define ll long long int
using namespace std;
void mergetwosortedarray(ll *arr, ll s, ll e)		//to form the function to merge the two array formed
{
	int mid=(s+e)/2;		// to find the mid of the sorted array
	int i=s;		//to start the i pointer from the start of the sorted array
	int j=mid+1;		//to start the j pointer from the (mid+1)th position
	ll *temp=new ll[2000000]; //temporary array to merge the two sorted parts
	int k=s;		//pointer defined from the start 
	while(i<=mid&&j<=e)		//condition check to run the i and the j pointer from start to mid and mid+1 to end for the two parts of the array
	{
		if(arr[i]<arr[j]) //placing the smallest element in the temp array first and then the larger element
		{
			temp[k]=arr[i];
			k++;
			i++;
		}
		else
		{
			temp[k]=arr[j];
			k++;
			j++;
		}
	}
	while (i<=mid)		//to place the remaining elements
	{
		temp[k]=arr[i];
		k++;
		i++;
	}
	while (j<=e)		//to place the remaining elements
	{
		temp[k]=arr[j];
		k++;
		j++;
	}
	for(int i=s;i<=e;i++)		//copying the elements in the original array
	{
		arr[i]=temp[i];
	}
	delete [] temp;  //deleting the temporary array after use
}
void mergesort(ll *arr, ll s, ll e)
{
	//base case
	if(s>=e)			//when start = s becomes greater than end
	{
		return;
	}
	//recursive case
	int mid=(s+e)/2;		//to calculate the mid for the array
	mergesort(arr,s,mid);		//to sort the first half part
	mergesort(arr,mid+1,e);		//to sort the second half part
	mergetwosortedarray(arr,s,e);		//to merge the two sorted parts
}
int main()
{
	int n;
	cin>>n;
	ll *arr=new ll[2000000];		//dynamic formation of array to form array of the size greater than can be formed directly
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	mergesort(arr,0,n-1);
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	delete []arr;				//to delete the array formed as it is not deleted on its own
	return 0;
}