#include<iostream>
#include<unordered_map>
#include<cstring>
#include<list>
#include<queue>
using namespace std; 
template<typename T>        //to make graph generic
class graph{
    private:    //as we don't want the user to use the functionallity of the maps
    unordered_map<T,list<T> >h;   //this map has key --> string and values --> are of the type list of string --> list<string>

    public:
    void addedge(T u, T v,bool bidirectional=true)  //T is the data type
    {
        h[u].push_back(v);
        if(bidirectional)
        {
            h[v].push_back(u);
        }
    }

    void printlist()
    {
        for(auto n:h)   //n has two value --> key and value 
        {
            cout<<n.first<<" --> "; //refers to the key of the hashmap
            for(auto node:n.second) //refers to the linked list at a particular key and then starts printing the data of the linked list
            {
                cout<<node<<" ";    //printing the value of the node --> value at linked list
            }
            cout<<endl;
        }

    }


    void bfs(T start)   //starting node of the tree
    {
        queue<T>q;
        unordered_map<T, bool> visited; //T is the data type of the key and bool is the data type of value --> as we have to store true if visited the element before and false if the element is not visited
        q.push(start);
        visited[start]=true;    //that we have visited the starting node
        unordered_map<T,int> distance;  //map to get min distance of destination from the source --> destination key if of type T and the unit of distance is int
        distance[start]=0;      //distance of start from itself is 0
        while (!q.empty())
        {
            T node=q.front();
            q.pop();
            cout<<node<<" ";
            for(auto children:h[node])  //to get the children of the node --> and push it in the queue --> when it is not visited
            {   //hashmap h cointains the neighbours of every node so to get children we do h[node] --> but we use for each function as we get a linked list and so we need to iterate over it
                if(!visited[children])  //if children is not visited
                {
                    q.push(children);
                    visited[children]=true;
                    distance[children]=distance[node]+1;    //distance of every child from the parent is 1 and distance of every parent from source is distance[node]
                }
            }
        }
        cout<<endl;
        for(auto temp:distance)
        {
            cout<<"Min distance of "<<temp.first<<" from source is : "<<temp.second<<endl;
        }
    }



    int singleSourceShortestPath(T start,T des)   //starting node of the tree
    {
        queue<T>q;
        unordered_map<T, bool> visited; //T is the data type of the key and bool is the data type of value --> as we have to store true if visited the element before and false if the element is not visited
        q.push(start);
        visited[start]=true;    //that we have visited the starting node
        unordered_map<T,int> distance;  //map to get min distance of destination from the source --> destination key if of type T and the unit of distance is int
        unordered_map<T,T> parent;  //to remember the parent of each node
        parent[start]=start;    //parent of start is start
        distance[start]=0;      //distance of start from itself is 0
        while (!q.empty())
        {
            T node=q.front();
            q.pop();
            for(auto children:h[node])  //to get the children of the node --> and push it in the queue --> when it is not visited
            {   //hashmap h cointains the neighbours of every node so to get children we do h[node] --> but we use for each function as we get a linked list and so we need to iterate over it
                if(!visited[children])  //if children is not visited
                {
                    q.push(children);
                    visited[children]=true;
                    distance[children]=distance[node]+1;    //distance of every child from the parent is 1 and distance of every parent from source is distance[node]
                    parent[children]=node;  //to put parent of every child is node
                }
            }
        }
        T temp=des;
        while (temp!=parent[temp])  //i.e if the node becomes parent itself then we have reached the start
        {
            cout<<temp<<" ";
            temp=parent[temp];
        }
        cout<<temp<<endl;   //to print the last element of the path
        return distance[des];   //will return the distance of the destination of the source
    }


    void depthFirstSearch(T src,unordered_map<T,bool>&visited)  //as we are using recursive call and we want the change to persist and so we pass by reference
    {
        visited[src]=true;  //handling the first element
        cout<<src<<" "; //printing the src
        for(auto c:h[src])  //as hashmap contains the children of the src so to iterate on the children
        {
            if(!visited[c]) //if c is not visited
            {//because of this recursive call we pass visited by reference and not by value beacuse we want the chane to presist
                depthFirstSearch(c,visited);    //making c src 
            }
        }
    }



    int noOfComponents(T src,unordered_map<T,bool> &visited,int &compNumber)
    {
        visited[src]=true;
        for(auto c:h[src])
        {
            if(!visited[c])
            {
                noOfComponents(c,visited,compNumber);       //using depth first to go down the graph
            }
        }


        for(auto node:h)  //checking the hashmap to check if there is any key that is not visited
        {
            if(!visited[node.first])   //if any key is left that means it is not connected to the previous graph
            {
                compNumber++;   //we have a new graph so we increase the number of components
                noOfComponents(node.first,visited,compNumber);  //we iterate on the next graph
            }
        }


        return compNumber;  //returns the number of components of the graph
    }



};
int main()
{
    // graph<string> g;
    // g.addedge("Putin","Trump"); //putin follows trump but trump doesn't follow putin
    // g.addedge("Putin","Modi");
    // g.addedge("Putin","Pope");
    // g.addedge("Modi","Trump",true); //true --> modi follows trump and trump follows modi
    // g.addedge("Modi","Yogi",true);
    // g.addedge("Yogi","Prabhu");
    // g.addedge("Prabhu","Modi");


    // g.printlist();



    // cout<<endl;
    // cout<<"Breadth first search : "<<endl;
    // g.bfs("Putin"); //start node of the graph


    // cout<<endl;
    // cout<<"Single Source Shortest Path :"<<endl;
    // cout<<g.singleSourceShortestPath("Putin","Prabhu"); //this give the shortest path between source and destination



    // cout<<endl;
    // cout<<"Result of the depth first search :"<<endl;
    // unordered_map<string,bool> visited;    //int is the data type of the key and bool is the data type of the state --> visited or not
    // g.depthFirstSearch("Prabhu",visited);


    cout<<endl;
    graph<int> gr;  //new graph for integers
    unordered_map<int,bool> visited1;
    int node,edges;
    cin>>node>>edges;
    for(int i=1;i<=edges;i++)
    {
        int u,v;
        cin>>u>>v;
        gr.addedge(u,v); //u and v are the points between which the node is to be formed
    }

    cout<<"The no of components of the graph is :"<<endl;
    int compNumber=1;
    cout<<gr.noOfComponents(1,visited1,compNumber);

    return 0;
}