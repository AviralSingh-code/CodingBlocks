#include<iostream>
#include<algorithm>
using namespace std;
bool canweplacethecows(int *arr,int n,int cows,int distance)
{
    int cp=1;               //min we will place one cow
    int prev=arr[0];        //the first cow is placed at the first slot
    for(int i=1;i<n;i++)//checking all the slots and if the distance of the slot is greater than the max distance allowed then we place a cow 
    {
        if(arr[i]-prev>=distance)
        {
            cp++;
            prev=arr[i];
            if(cp==cows)
            {
                return true;
            }
        }
    }
    if(cp<cows)
    {
        return false;
    }
    return true;
}
int main()
{
    int n,c;
    cin>>n>>c;
    int arr[n];
    int ans=0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n);            //tc O(nlogn)
    int si=0;
    int ei=arr[n-1];
    while (si<=ei)
    {
        int mid=(si+ei)/2;
        if(canweplacethecows(arr,n,c,mid)==true)
        {
            ans=mid;
            si=mid+1;
        }
        else
        {
            ei=mid-1;
        }
    }
    cout<<ans;
    return 0;
}