#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
char keys[10][10]={ " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz"};
bool smart(char *input,int i,int j,char *out)
{
    //base case
    if(input[i]=='\0')
    {
        out[j]='\0';
        cout<<out<<endl;
        return;
    }


    //recursive case
    int digit= input[i]-'0';
    for(int k=0;keys[digit][k]!='\0';k++)
    {
        out[j]=keys[digit][k];
        smart(input,i+1,j+1,out);
    }

}
int main()
{
    char input[100];
    cin>>input;
    char out[100];
    smart(input,0,0,out);
}