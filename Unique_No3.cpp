#include <iostream>
using namespace std;
#include <cmath>
int main()
{
    int n;
    cin>>n;
    int arr[n];
    int freq[32];                   //To hold the set bits of the numbers in the array in their respective position
    for(int i=0;i<32;i++)
    {
        freq[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(int i=0;i<n;i++)
    {
        int value=arr[i];
        int position=0;
        while (value)
        {
            if(value & 1)
            {
                freq[position]++; //To add 1 to the corresponding positions in the frequency array corresponding to the position of set bits in the binary format of the number
            }
            value=value>>1;
            position++;
        }
        
    }
    for(int i=0;i<32;i++)           //To remove the bits corresponding to the number that has been added three times
    {
        freq[i]=freq[i]%3;          //1 added 3 times to a position gives 3 and 3%3 is 0 but if there is a number that has been added only once then it will add 1, 1 time and that extra 1 will be shown when % is taken with 3
    }
    int num=0;
    for(int i=0;i<32;i++)
    {
        num=num+freq[i]*pow(2,i);   // To multiply the left elements with power of two to get the corresponding elements in the decimal format
    }                               //This works because the set bits have been added to the corresponding positions
    cout<<num;
}