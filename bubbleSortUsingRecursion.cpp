#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
void bubbleSort(int *arr,int n, int i)
{
    //base case
    if(i==n-1)
    {
        return;
    }
    //recursive case
    for(int j=0;j<=n-2-i;j++)
    {
        if(arr[j]>arr[j+1])
        {
            swap(arr[j],arr[j+1]);
        }
    }
    bubbleSort(arr,n,i+1);
}
int main()
{
    int arr[1000];
    cout<<"Enter the number of elements : "<<endl;
    int n;
    cin>>n;
    cout<<"Enter the elements : "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    bubbleSort(arr,n,0);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}