#include<iostream>
#include<cstring>
#include<algorithm>
#define ll long long int
using namespace std;
void subsequence(char *in,int i,char *out,int j)            //to find subsequence
{
    //base case
    if(in[i]=='\0')             //when the i th counter reaches the end of the input array it finds null character
    {
        out[j]='\0';            //to print the stored result when null is encountered
        cout<<out<<endl;
        return;
    }
    //recursive case

    //exclude
    subsequence(in,i+1,out,j);      /*to exclude a particular array element eg. in abc\0 we exclude a to get the subsequences as 
                                        " " c b bc */
     //include a particular element
    out[j]=in[i];
    subsequence(in,i+1,out,j+1);/*to include the excluded element to get the subsequences eg. a ac ab abc */
}
int main()
{
	char input[100];            //input array
    cin>>input;     //important way to take input in case of character array
    char output[100];           //to store the output in each case
    subsequence(input,0,output,0);      //passing input and output array and the value of i = 0 and j = 0
}