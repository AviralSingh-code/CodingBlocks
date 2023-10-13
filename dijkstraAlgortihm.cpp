#include<iostream>
#include<cstring>
#include<unordered_map>
#include<list>
#include<queue>
#include<climits>
#include<set> 
using namespace std;
//---------------------------------------------
//TC O(ElogV)
vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> dist(V, 1e9);
        
        dist[S] = 0;
        pq.push({0,S});
        
        while(!pq.empty())
        {
            int distanceNode = pq.top().first;
            int Node = pq.top().second;
            pq.pop();
            
            for(auto nbr : adj[Node])
            {
                int distChild = nbr[1];
                int childNode = nbr[0];
                
                if(distanceNode + distChild < dist[childNode])
                {
                    dist[childNode] = distanceNode + distChild;
                    pq.push({dist[childNode], childNode});
                }
            }
        }
        return dist;
    }
//---------------------------------------------

// time complexity O((V+E)logV)
template<typename T>
class graph{
    unordered_map<T,list<pair<T,int> > > h;     //this map is used for storing the name of the city and the list stores a pair of the other city and the distance in the type int
    public:


    void addedge(T src,T des,int distance,bool biDirectional=true)
    {
        h[src].push_back(make_pair(des,distance));      //we push a pair in the hashmap --> to make pair we use the make_pair function
        if(biDirectional)
        {
            h[des].push_back(make_pair(src,distance));  //to make bidirectional link
        }
    }


    void print()
    {
        for(auto node:h)
        {
            cout<<node.first<<" --> ";      //this wil give the key
            for(auto neighbour:node.second) //as the second value of the hashmap is a linked list so we have to iterate on the linked list
            {   //neighbour.first --> gives the first element of the pair  neighbour.second --> gives the second element of the pair
                cout<<"("<<neighbour.first<<" "<<neighbour.second<<") , ";

            }
            cout<<endl; 
        }
    }


    void dijkstra(T src)
    {
        unordered_map<T,int> distance;  //to store distance of node
        for(auto node:h)
        {
            distance[node.first]=INT_MAX;   //initializing the distance of every city to INT_MAX --> as we have to get min
        }
        distance[src]=0;    //putting the distance of the source to 0
        set<pair<int,T> > s;    //to store the set of pair --> int is for distance and T is for key
        s.insert(make_pair(0,src)); //set sorts the value according to the first argument and as we have taken int so it will sort the pair according to distance

        while(!s.empty())     //we will do the work till the set gets empty
        {   
            //as after every loop the value of the first element may get changed as it is always sorted in a set therefore for the min element we take the first element and iterate on its children
            auto node = *(s.begin());   //s.begin returns address of the first node and * is used to de-refer the address
            s.erase(s.begin()); //to erase the value as we have stored it in node
            int parentDist= node.first;
            T Parent = node.second; //as node is something like (0,A) --> 0 is the distance and A is the name 
            for(auto children:h[Parent])    //to iterate children of the parent
            {
                int edgeDist=children.second;   //to store the edge distance of the child from parent
                if(distance[children.first]>(parentDist+edgeDist))      //if distance of child is > than the sum of the distance of the parent and the edge distance then we need to put the min of the two i.e the sum to be the new distance of the child
                {
                    auto f = s.find(make_pair(distance[children.first],children.first));   //we get the address of the node if it exists in the set already as we need to update that so we have to remove that

                    if(f!=s.end())  //means when we want to go to till the end but we are not able to reach there it means that the address exists
                    {
                        s.erase(f); //erasing the value at the address --> doing this removes the previous value of the node so that we can assign the new value to the set
                    }


                    distance[children.first]=parentDist+edgeDist;   //so we update it to be minimum
                    s.insert(make_pair(distance[children.first],children.first));       //we need to sort the result according to the distance and so using the property of the set we push it into the set to get sorted
                }
            }
        }

        for(auto node:distance) //to print the final distance of all the nodes
        {
            cout<<"Minimum distance of "<<node.first<<" from source is : "<<node.second<<endl;
        }


    }
};
int main()
{
    graph<string> g;
    g.addedge("Amritsar","Agra",1); //distance of agra from amritsar
    g.addedge("Amritsar","Jaipur",4);
    g.addedge("Delhi","Jaipur",2);
    g.addedge("Delhi","Agra",1);
    g.addedge("Bhopal","Agra",2);
    g.addedge("Bhopal","Mumbai",3);
    g.addedge("Jaipur","Mumbai",8);


    // g.print();


    cout<<"The min distance using dijkstra is :"<<endl;
    g.dijkstra("Amritsar"); //the source of the graph is taken to be Amritsar

    return 0;
}