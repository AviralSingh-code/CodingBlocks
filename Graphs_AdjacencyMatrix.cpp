#include<iostream>
using namespace std;

class node{
    public:
    int v;  //number of vertices
    int e; //number of edges
    int **adj;  //for double dimension matrix

    node(int vert,int edge)
    {
        v=vert;
        e=edge;
        adj = new int*[v];      //for assigning v pointers
        for(int i=0;i<v;i++)
        {
            adj[i] = new int[v];        //for assigning a space of v to every pointer making it vxv matrix
        }
    }
};


int main()
{
    node * temp = NULL;         //for making a pointer
    cout<<"Enter the number of vertices and edges"<<endl;
    int vert,edges;
    cin>>vert>>edges;

    node *n = new node(vert,edges);     //for making a node

    temp = n;//this is how we use it we make a pointer and a node and then we point the pointer to the node so that we can use the arrow operator

    cout<<"Reading edges"<<endl;
    int u,v;

    for(int i=0;i<vert;i++)
    {
        for(int j=0;j<vert;j++)
        {
            temp->adj[i][j]=0;
        }
    }

    for(int i=0;i<edges;i++)
    {
        cin>>u>>v;
        temp->adj[u][v]=1;  //assigning 1 where edge exists
        temp->adj[v][u]=1;
    }


    //printing the adjacency matrix

    cout<<"The adjecency matrix is : "<<endl;

    for(int i=0;i<vert;i++)
    {
        for(int j=0;j<vert;j++)
        {
            cout<<temp->adj[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;

}