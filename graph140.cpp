#include<bits/stdc++.h>
using namespace std;
#define NTL -1

class Graph
{
    int V;
    list<int> *adj;
    void isBridgeUtil(int v, bool visited[], int disc[], int low[], int parent[]);
public:
    Graph(int V);
    void addEdge(int v, int w);
    void isBridge();
};

Graph::Graph(int V)
{
    this->V=V;
    adj=new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}

void Graph::isBridgeUtil(int u, bool visited[], int disc[], int low[],int parent[])
{
    static int time=0;
    visited[u]=true;

    disc[u]=low[u]=++time;
    list<int>::iterator i;
    for(i=adj[u].begin();i!=adj[u].end();i++){
        int v=*i;
        if(!visited[v]){
            parent[v]=u;
            isBridgeUtil(v,visited,disc,low,parent);
            low[u]=min(low[u],low[v]);
            if(low[v]>disc[u]){
                cout<<u<<" "<<v<<endl;
            }
        }
        else if(v!=parent[u]){
            low[u]=min(low[u],disc[v]);
        }
    }
}

void Graph::isBridge()
{
    bool *visited=new bool[V];
    int *disc=new int[V];
    int *low=new int[V];
    int *parent=new int[V];

    for(int i=0;i<V;i++){
        visited[i]=false;
        parent[i]=NTL;

    }
    for(int i=0;i<V;i++){
        if(visited[i]==false){
            isBridgeUtil(i,visited,disc,low,parent);
        }
    }
}

int main()
{
    cout<<"Bridges in first graph\n";
    Graph g(5);
    g.addEdge(1,0);
    g.addEdge(0,2);
    g.addEdge(2,1);
    g.addEdge(0,3);
    g.addEdge(3,4);
    g.isBridge();
    return 0;
}