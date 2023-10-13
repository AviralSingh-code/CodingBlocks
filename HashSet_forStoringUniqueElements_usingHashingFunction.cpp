#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    unordered_set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(4);
    s.insert(78);
    s.insert(45);
    s.insert(6);
    s.insert(3);

    int key = 23;
    int key2 = 78;

    if(s.find(key)==s.end())
    {
        cout<<key<<" not found"<<endl;
    }
    else
    {
        cout<<key<<" found"<<endl;
    }

    if(s.find(key2)==s.end())
    {
        cout<<key2<<" not found"<<endl;
    }
    else
    {
        cout<<key2<<" found"<<endl;
    }
    return 0;
}