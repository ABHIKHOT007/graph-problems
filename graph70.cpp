#include<bits/stdc++.h>
#define INF INT_MAX
using namespace std;
//shortest path in directed acyclic graph.
class AdjListNode
{
    int v;
    int weight;
public:
    AdjListNode(int _v, int _w){
        v=_v;
        weight=_w;
    }
    int getv(){
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
    void topologicalsortUtil(int v, bool visited[], stack<int> &s);
public:
    Graph(int V);
    void addEdge(int u, int v, int weight);
    void shortestpath(int s);
};

Graph::Graph(int V)
{
    this->V=V;
    adj = new list<AdjListNode>[V];
}

void Graph::addEdge(int u, int v, int weight)
{
   AdjListNode node(v,weight);
   adj[u].push_back(node);
}

void Graph::topologicalsortUtil(int v, bool visited[], stack<int> &s)
{
    visited[v]=true;
    list<AdjListNode>::iterator i;
    for(i=adj[v].begin(); i!=adj[v].end(); i++){
        AdjListNode node = *i;
        if(!visited[node.getv()]){
            topologicalsortUtil(node.getv(),visited,s);
        }
    }
    s.push(v);
}

void Graph::shortestpath(int s)
{
    stack<int> z;
    int dist[V];

    bool *visited = new bool[V];
    for(int i=0;i<V;i++){
        visited[i]=false;
    }
    for(int i=0;i<V;i++){
        if(visited[i]==false){
            topologicalsortUtil(i,visited,z);
        }
    }
    for(int i=0;i<V;i++){
        dist[i]=INF;
    }
    //dist[i] = 0;

    while(z.empty()==false){
        int u=z.top();
        z.pop();
        list<AdjListNode>::iterator i;
        if(dist[u]!=INF){
            for(i=adj[u].begin(); i!=adj[u].end(); i++){
                if(dist[i->getv()]>dist[u]+i->getweight()){
                    dist[i->getv()]=dist[u]+i->getweight();
                }
            }
        }
    }
    for(int i=0;i<V;i++){
        (dist[i]==INF)?cout<<"INF":cout<<dist[i]<<" ";
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
    g.addEdge(2,3,7);
    g.addEdge(3,4,-1);
    g.addEdge(4,5,-2);

    int s=1;
    cout<<"following are shortest distacne from source"<<s<<"\n";
    g.shortestpath(s);
    return 0;
}