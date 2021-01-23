#include<bits/stdc++.h>
using namespace std;

class AdjListNode
{
    int v;
    int weight;
public:
    AdjListNode(int _v, int _w){
        v=_v;
        weight = _w;
    }
    int getV(){
        return v;
    }
    int getweight(){
        return weight;
    }
};

class Graph
{
    int V;
    list<AdjListNode> *adj;
    void longestpathUtil(int,vector<bool>&,stack<int> &);
public:
    Graph(int);
    ~Graph();
    void addEdge(int,int,int);
    void longestpath(int s);
};

Graph::Graph(int V)
{
    this->V=V;
    adj = new list<AdjListNode>[V];
}

Graph::~Graph()
{
    delete[] adj;
}
void Graph::addEdge(int u, int v, int weight)
{
    AdjListNode node(v,weight);
    adj[u].push_back(node);
}

void Graph::longestpathUtil(int v, vector<bool> &visited, stack<int> &a)
{
    visited[v]=true;

    for(AdjListNode node : adj[v]){
        if(!visited[node.getV()]){
            longestpathUtil(node.getV(),visited,a);
        }
    }
    a.push(v);
}

void Graph::longestpath(int s)
{
    int dist[V];
    for(int i=0;i<V;i++){
        dist[i]=INT_MAX;
    }
    dist[s]=0;

    stack<int> a;
    vector<bool> visited(V,false);
    for(int i=0;i<V;i++){
        if(visited[i]==false){
            longestpathUtil(i,visited,a);
        }
    }
    while(!a.empty())
    {
        int u=a.top();
        a.pop();

        if(dist[u]!=INT_MAX)
        {
            for(AdjListNode v : adj[u])
            {
                if(dist[v.getV()] > dist[u]+v.getweight() * -1)
                {
                    dist[v.getV()]=dist[u]+v.getweight()*-1;
                }
            }
        }
    }

    for(int i=0;i<V;i++)
    {
        if(dist[i]==INT_MAX){
            cout<<"INT_MAX"<<endl;
        }
        else{
            cout<<(dist[i]*-1)<<" ";
        }
    }
}

int main()
{
    Graph g(6);
    g.addEdge(0,1,5);
    g.addEdge(0,2,3);
    g.addEdge(1,3,6);
    g.addEdge(1,2,2);
    g.addEdge(2,4,4);
    g.addEdge(2,5,2);
    g.addEdge(2,3,7);
    g.addEdge(3,5,1);
    g.addEdge(3,4,-1);
    g.addEdge(4,5,-2);

    int s=1;
    cout<<"following are the longest distacne from soure to vertex"<<s<<"\n";
    g.longestpath(s);
    return 0;
}