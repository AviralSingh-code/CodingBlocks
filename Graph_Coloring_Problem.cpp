#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int v,e;
    cin>>v>>e;
    map<int,vector<int> > g;
    for(int i = 0;i<e;i++)
    {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int res[v]; //to store the final coloring of the nodes
    bool available[v];
    res[0] = 0;
    for(int i = 1;i<v;i++)
    {
        res[i] = -1;    //initially no color so set to -1
        available[i] = false;   //all colors are available
    }

    int cn = 0; //chromatic number
    for(int i = 1;i<v;i++)
    {
        for(auto x:g[i])
        {
            if(res[x]!=-1)//means adjacent node is colored
            {
                available[res[x]] = true;//means color is used up so cannot be used again
            }
        }
        int cr;
        for(cr = 0;cr<v;cr++)
        {
            if(available[cr]==false)
            {
                break;
            }
        }
        res[i] = cr;
        cn = max(cn,cr+1);
        //this is to reset the available colors as we are now going to check the next node
        for(auto x:g[i])
        {
            if(res[x]!=-1)
            {
                available[res[x]] = false;
            }
        }
    }
    cout<<cn<<endl;
    for(int i = 0;i<v;i++)
    {
        cout<<res[i]<<" ";
    }
}
int main() {
    solve();
    return 0;
}
