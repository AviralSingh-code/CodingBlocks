#include<iostream>
#include<algorithm> 
#include<climits>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int height[n];
	int leftMax[n];
	int rightMax[n];
	for(int i=0;i<n;i++)
	{
		cin>>height[i];
	}
	leftMax[0]=height[0];
	for(int i=1;i<n;i++)
	{
		leftMax[i]=max(height[i],leftMax[i-1]);	//to get the max height to the left
	}
	rightMax[n-1]=height[n-1];
	for(int i=n-2;i>=0;i--)
	{
		rightMax[i]=max(height[i],rightMax[i+1]);//to get the max height to the right of the current building
	}
	int water=0;
	for(int i=0;i<n;i++)
	{
		water +=min(leftMax[i],rightMax[i])-height[i];
	}
	cout<<water;
}

