#include<iostream>
using namespace std;
/* the best thing about this approach is that even
when all the numbers in the array are negative then also this can be used
that is when the Kadence algorithm fails*/
int max_Subarry_Sum(int *arr,int n)   //finding the max subarry sum using dynamic programming
{
    int curr_max = arr[0];
    int max_so_far = arr[0];
    for(int i = 1;i<n;i++)
    {
        curr_max = max(arr[i],curr_max+arr[i]);
        max_so_far = max(curr_max,max_so_far);
    }
    return max_so_far;
}
int main()
{
    cout<<"Enter the size of the array"<<endl;
    int s;
    cin>>s;
    cout<<"Enter the elements of the array"<<endl;
    int arr[s];
    for(int i = 0;i<s;i++)
    {
        cin>>arr[i];
    }
    cout<<"The max sum of the subarry is : "<<max_Subarry_Sum(arr,s);
    return 0;
}