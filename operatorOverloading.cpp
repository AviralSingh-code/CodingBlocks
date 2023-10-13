#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std; 
class Pair{
    public:
    int a;
    int b;

    Pair(int a,int b)
    {
        this->a=a;
        this->b=b;
    }

    bool operator>(Pair &y)     //method to pass a member of the class
    {
        if(a>y.a&&b>y.b)        //method to compare the a of x to a of y
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
int main()
{
    Pair x(20,30);
    Pair y(10,15);
    if(x>y)     //normal condition
    {
        cout<<"X is greater than Y"<<endl;
        cout<<x.a<<" "<<x.b<<"      "<<y.a<<" "<<y.b<<endl;
    }
    else
    {
        cout<<"Y is greater than X"<<endl;
        cout<<y.a<<" "<<y.b<<"      "<<x.a<<" "<<x.b<<endl;
    }
}