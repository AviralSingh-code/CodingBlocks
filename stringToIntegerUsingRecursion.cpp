#include<iostream>
#include<cstring>
using namespace std;
int stringToInteger(char *n,int l)     //recursive function takes character array as input and length of the array
{
    //base case
    if(l==0)        //when length reduces to 0 that means no number is left in the array
    {
        return 0;
    }


    //recursive case
    int digit=(int)n[l-1]-(int)'0';     //takes out the digit for the array and converts it into ASCII value
    //the difference in the ASCII value is the number itself ASCII value of 0 is 49
    return(stringToInteger(n,l-1)*10+digit);        //recursive call as it is removing out the last character of the array every time
}//multiplying with 10 adjusts the place value of the number formed and then adding the digit at last
int main()
{
    char n[100];
    cin>>n;             //important method to take input
    int value=stringToInteger(n,strlen(n));         //strlen to find the length of character array and NOT STRING
    cout<<endl;
    cout<<value+100;        //check for integer conversion
}