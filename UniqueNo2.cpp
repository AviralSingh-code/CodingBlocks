#include <iostream>
#include <cmath>
using namespace std;
int main()
{
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++)
  {
      cin>>arr[i];
  }
  int xorr=0;
  int pos=0;
  //Step 1: Take xor of the entire sequence
  for(int i=0;i<n;i++)              //To create a number , where the number has set bit we have a difference in the bits of the two numbers
  {
      xorr=xorr^arr[i];
  }
  //Step 2: Get the position of the rightmost set bit 
  while(xorr)                //To get the rightmost set bit in xorr
  {
      if(xorr&1)
      {
          break;
      }
      pos++;
      xorr=xorr>>1;
  }
  //Step 3:To creat a mask by left shifting (1<<p)
  int mask=1<<pos;
  int num1=0;
  int num2=0;
  //Step 4: To exclude one number of the two different number and to get the other one
  for(int i=0;i<n;i++)//Those numbers that are repeated twice gets cancelled out
  {//The number with respect to which we create the mask gets excluded and the other number remains
    if(mask&arr[i])
    {
      num1=num1^arr[i];
    }
  }
  num2=xorr^num1;
  if(num1>num2)
  {
      cout<<num2<<" "<<num1;
  }
  else
  {
      cout<<num1<<" "<<num2;
  }
  
 
}
