 #include<iostream>
#include<list>
// #include<bits/stdc++.h>
using namespace std;
class graph{
    public:
    list<int>*l;        //list type ka pointer ----> will store the address of the array of list
    int n;      //total no of edges
    graph(int N)
    {
        n=N;
        l=new list<int>[N]; //this will assign memory to the array of lists and as it is of type list so we have to write it as list<int> --> list of type int
    }


    void addEdge(int u,int v,int biDirectional=true)
    {
        l[u].push_back(v);
        if(biDirectional)
        {
            l[v].push_back(u);  //if it is bidirectional then we put a into b and we put b into a
        }
    }



    void print()
    {
        for(int i=0;i<n;i++)
        {
            cout<<i<<" --> ";
            for(auto n:l[i])    //l is an array of linked list so we do l[i] to access the linked list at ith index
            {
                cout<<n<<" ";
            }
            cout<<endl;
        }
    }
};

int main()
{
    int ne,nn;
    cin>>nn>>ne; //nn --> no of nodes ne--> no of edges
    graph g(nn);
    for(int i=0;i<ne;i++)
    {
        int u,v;
        cin>>u>>v; //u and v denote from where to where the edge is to be formed
        g.addEdge(u,v);
    }
    g.print();

    return 0;
}