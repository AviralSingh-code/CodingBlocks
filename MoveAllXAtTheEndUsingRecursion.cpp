#include<iostream>
#include<cstring>
using namespace std;
string moveallx(string s)
{
    //base case
    if(s.length()==0)
    {
        return "";
    }

    //recursive case
    string a=s.substr(0,1);
    string chotiProblem=moveallx(s.substr(1));
    string badiProblem="";
    if(a=="x")
    {
        badiProblem=chotiProblem+a;
    }
    else
    {
        badiProblem=a+chotiProblem;
    }
    return badiProblem;
}
int main()
{
   string s;
   cin>>s;
   cout<<moveallx(s);;
   return 0;
}