#include <iostream>
#include <cmath>
using namespace std;
int main()
{
int t;
cin>>t;
int hold=t;
int ans[t];
int count=0;
while(t)
{
    int c1,c2,c3,c4;
    cin>>c1>>c2>>c3>>c4;
    int n,m;
    cin>>n>>m;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];   
    }
    int b[m];
    for(int i=0;i<m;i++)
    {
        cin>>b[i];
    }
    int costOfCabs=0;
    for(int i=0;i<m;i++)
    {
        costOfCabs=costOfCabs+std::min(b[i]*c1,c2);
    }
    int cabFinal=std::min(costOfCabs,c3);
    int costOfRick=0;
    for(int i=0;i<n;i++)
    {
        costOfRick=costOfRick+std::min(a[i]*c1,c2);
    }
    int rickFinal=std::min(costOfRick,c3);
    int finalPrice=std::min(c4,cabFinal+rickFinal);
    ans[count]=finalPrice;
    count++;
    t--;
}
for(int i=0;i<hold;i++)
{
    cout<<ans[i]<<endl;
}
}
