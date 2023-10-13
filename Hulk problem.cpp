#include <iostream>
#include <cmath>
using namespace std;
int main()
{           // Hint to use set bits is that hulk jumps in steps multiple of 2
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++)          //To enter the level of the enemy
  {
    cin>>arr[i];
  }
  for(int i=0;i<n;i++)
  {
    int value=arr[i];
    int count=0;
    while(value)            //To get the number of steps the number of set bits in the binary format of the number 
    {
      if(value & 1)      //Standard way to calculate the number  of set bits in the binary format
       {           
        count++;
      }
      value=value>>1;
    }
    cout<<count<<endl;
  }

}
