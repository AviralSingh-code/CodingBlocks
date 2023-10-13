#include<iostream>
#include<algorithm> 
#include<climits>
#define ll long long
using namespace std; 
int main()
{
	int t;
	cin>>t;
	string ans[t];
	int k=0;
	while (t)
	{
	int n;
	cin>>n;
	string str[n];
	for(int i=0;i<n;i++)
	{
		cin>>str[i];
	}
	for(int i=0;i<n-1;i++)
	{
		for(int j=i;j<n;j++)
		{
			string ab=str[i]+str[j];
			string ba=str[j]+str[i];
			if(ab.compare(ba)<0)                    //if ab <ba then the result is (<0)
			{
				string temp=str[i];
				str[i]=str[j];
				str[j]=temp;
			}
		}
	}
	string number="";
	for(int i=0;i<n;i++)
	{
		number=number+str[i];
	}
	ans[k]=number;
	k++;
	t--;
	}
	for(int i=0;i<k;i++)
	{
		cout<<ans[i]<<endl;
	}
	
}

