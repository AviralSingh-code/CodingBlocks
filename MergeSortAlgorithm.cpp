#include <bits/stdc++.h>
using namespace std;

void merge(int *a,int s,int e)
{
    int mid = (s+e)/2;
    int i = s;
    int j = mid+1;
    int k = s;
    int temp[100];
    while(i<=mid&&j<=e)
    {
        if(a[i]<a[j])
        {
            temp[k++] = a[i++];
        }
        else
        {
            temp[k++] = a[j++];
        }
    }
    while(i<=mid)
    {
        temp[k++] = a[i++];
    }
    while(j<=e)
    {
        temp[k++] = a[j++];
    }

    //copying it in the original array
    for(int i = s;i<=e;i++)
    {
        a[i] = temp[i];
    }
}
void mergesort(int a[],int s,int e)
{
    //base case
    if(s>=e)
    {
        return;
    }

    //1. finding the mid point of the array
    int mid = (s+e)/2;  //---> modified s-(s-e)/2

    //splitting the array
    mergesort(a,s,mid);
    mergesort(a,mid+1,e);


    //merging the two array
    merge(a,s,e);

}
int main()
{
    int a[]={2,1,4,3};
    int l = sizeof(a)/sizeof(int);
    mergesort(a,0,l-1);
    for(int i = 0;i<l;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}