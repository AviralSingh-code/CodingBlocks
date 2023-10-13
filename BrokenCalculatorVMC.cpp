#include<iostream>
#include<algorithm> 
#include<climits>
using namespace std;

//time complexity of this function is O(n log n!)

//reference of n is passed to hold the change
void multiply(int *a,int &n,int no)	//to maintain the change in we pass it by reference
{
	int carry=0;
	for(int i=0;i<n;i++)
	{
		int product=a[i]*no+carry;
		a[i]=product%10;
		carry=product/10;
	}
	while(carry)	//to add the carry to the answer array
	{
		a[n]=carry%10;	//carry can be more than one digits
		carry=carry/10;
		n++;
	}
}
void factorial(int num)
{
	int arr[1000]={0};	//created an array
	arr[0]=1;		//to initialize the first the first element as 1
	int n=1;
	for(int i=2;i<=num;i++)
	{
		multiply(arr,n,i);		//arr is the array , n is the laces of the number , current number
	}
	for(int i=n-1;i>=0;i--)
	{
		cout<<arr[i];	//as reference of the array is passed so the change is there in the original array
	}
}
int main()
{
	int n;
	cin>>n;
	factorial(n);	//passing the number
	return 0;
}

