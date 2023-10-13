#include<iostream>
using namespace std;

int power(int x,int n)      //as we are dividing the value of n with 2 every step so the steps required is logn --> O(logN)
{
    //base case
    if(n==0)
    {
        return 1;
    }
    
    //recursive case
    int temp=power(x,n/2);
    if(n%2==0)
    {
        return temp*temp;    //for eg if we have to get 5^10 ----> we can use divide and conquer to get 5^5 and to get 5^10 we do 5^5 * 5^5 --> temp*temp
    }
    else
    {
        return x*temp*temp;   //for odd values of n eg 5^11 we do 5^5*5^5*5 --> temp*temp*x;  
    }

}

int main()
{
    int x;
    cin>>x;
    int n;
    cin>>n;
    cout<<power(x,n);
}