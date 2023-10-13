#include<iostream>
#include<cstring>
using namespace std;
void toh(int n , char src , char helper , char dest)
{
    //base case
    if(n==0)
    {
        return;
    }
    // Recursive case
    toh(n-1,src,dest,helper);       //recursion work to place all n-1 discs on the helper tower leaving the nth disc at source
    cout<<"Take "<<n<<" from "<<src<<" to "<<dest<<endl;       //placing the nth disc on the destination tower
    toh(n-1,helper,src,dest);       //to place n-1 discs from the helper tower to the destination tower
}
int main()
{
    int n;
    cin>>n;
    toh(n,'A','B','C');     //A is taken as the source, B as the helper tower, C as the destination
    return 0;
}