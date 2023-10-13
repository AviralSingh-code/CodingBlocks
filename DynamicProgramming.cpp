#include<iostream>
using namespace std;
/*  USING DP REDUCES TIME COMPLEXITY FROM O(2^N) TO O(N)*/
int topDownfibo(int n,int *arr) //uses top down approach
{
    //base case
    if(n==0||n==1)
    {
        arr[n]=n;   //store before returning 
        return n;   //we can do it like this return arr[n]=n; --> this will store it before returning it 
    }




    //before calculating check
    if(arr[n]!=-1)  //n is the number whose fibonacci needs to be calculated
    {
        return arr[n];  //if it is already present then return that instead of calculating
    }

    //recursive case
    //before return store
    arr[n]=topDownfibo(n-1,arr)+topDownfibo(n-2,arr); //to store it if it is not present
    return topDownfibo(n-1,arr)+topDownfibo(n-2,arr);
}


int bottomUp(int n)//memorization is not used 
{
    int *arr=new int[n+1];
    //initialization
    arr[0]=0;   //the base case in top down approach becomes initialization condition in the bottom up approach
    arr[1]=1;
    //loop
    for(int i=2;i<=n;i++)
    {
        arr[i]=arr[i-1]+arr[i-2];
    }
    int ans=arr[n]; //to store the required element in ans
    delete []arr; //as it was created using DMA
    return ans;
}


int main()
{
    int n;
    cin>>n;
    int *arr=new int[n+1];  //to store the things already calculated
    for(int i=0;i<n+1;i++)
    {
        arr[i]=-1;          //initially we put -1
    }
    cout<<topDownfibo(n,arr)<<endl;

    cout<<endl;
    cout<<"Bottom up approach result : "<<endl;
    cout<<bottomUp(n)<<endl;


    return 0; 
}