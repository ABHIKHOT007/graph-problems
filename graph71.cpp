#include<bits/stdc++.h>
using namespace std;
//longest path in directed acycle path.
#define NINF INT_MIN

class AdjListNode
{
    int v;
    int weight;
public:
    AdjListNode(int _v, int _w){
        v= _v;
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
    void  topologicalsortUtil(int v, bool visited[], stack<int> &s);
public:
    Graph(int V);
    ~Graph();
    void addEdge(int u, int v, int weight);
    void longestpath(int s);
};

Graph::Graph(int V)
{
    this->V=V;
    adj=new list<AdjListNode>[V];
}
Graph::~Graph()
{
    delete []adj;
}
void Graph::addEdge(int u, int v, int weight)
{
    AdjListNode node(v,weight);
    adj[u].push_back(node);
}
void Graph::topologicalsortUtil(int v, bool visited[], stack<int> &q)
{
    visited[v]=true;

    list<AdjListNode>::iterator i;
    for(i = adj[v].begin(); i!=adj[v].end(); i++){
        AdjListNode node = *i;
        if(!visited[node.getV()]){
            topologicalsortUtil(node.getV(),visited,q);
        }
    }
    q.push(v);
}
void Graph::longestpath(int s)
{
    stack<int> q;
    int dist[V];

    bool *visited = new bool[V];
    for(int i=0;i<V;i++){
        if(visited[i]==false){
        topologicalsortUtil(i,visited,q);
    }

    for(int i=0;i<V;i++){
        dist[i]=NINF;
        dist[q]=i;
    }
   

    while(q.empty()==false){
        int u=q.top();
        q.pop();

        list<AdjListNode>::iterator i;
        if(dist[u]!=NINF){
            for(i=adj[u].begin(); i!=adj[u].end(); i++){
                if(dist[i->getV()] < dist[u]+i->getweight()){
                     dist[i->getV()] = dist[u]+i->getweight();
                }
            }
        }
    }
    for(int i=0;i<V;i++){
        (dist[i]==NINF)?cout<<"NIF":cout<<dist[i]<<" ";
    }
    delete[]visited;
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
    cout<<"following are the longeset distance from source vertex"<<endl;
    g.longestpath(s);
    return 0;
}
