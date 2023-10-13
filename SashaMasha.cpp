#include <iostream>
using namespace std;
int main() {
    long long int x,y,z;
    cin>>x>>y>>z;
    long long int extraSasha,extraMasha;
    extraSasha=x%z;
    extraMasha=y%z;
    if(z>x&&z>y)
    {
        cout<<0<<" "<<0;
        return 0;
    }
    long long int noexchange,exSashatoMasha,exMashatoSasha;
    noexchange=(x/z)+(y/z);
    exSashatoMasha=((y+extraSasha)/z)+(x/z);
    exMashatoSasha=((x+extraMasha)/z)+(y/z);
    if(noexchange>=exMashatoSasha&&noexchange>=exSashatoMasha)
    {
        cout<<noexchange<<" "<<0;
    }
    if(exSashatoMasha>noexchange&&exMashatoSasha<noexchange)
    {
        cout<<exSashatoMasha<<" "<<extraSasha;
    }
    else if(exMashatoSasha>noexchange&&exSashatoMasha<noexchange)
    {
        cout<<exMashatoSasha<<" "<<extraMasha;
    }
    else if(exMashatoSasha>noexchange&&exSashatoMasha>noexchange)
    {
        if(exMashatoSasha>exSashatoMasha)
        {
            cout<<exMashatoSasha<<" "<<extraMasha;
        }
        else if(exMashatoSasha<exSashatoMasha)
        {
            cout<<exSashatoMasha<<extraSasha;
        }
        else if(exMashatoSasha==exSashatoMasha)
        {
            if(extraMasha>=extraSasha)
            {
                cout<<exMashatoSasha<<" "<<extraSasha;
            }
            else 
            {
                cout<<exMashatoSasha<<" "<<extraMasha;
            }
        }
    }
    return 0;
}
