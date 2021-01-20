#include<bits/stdc++.h>
using namespace std;
//cycle detection in graph coloring method.
enum Color {WHITE,GREAY,BLACK};

class Graph
{
    int V;
    list<int> *adj;
    bool DFSUtil(int v, int color[]);
public:
    Graph(int V);
    void addEdge(int v, int w);
    bool iscyclic();
};

Graph::Graph(int V)
{
    this->V=V;
    adj=new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

bool Graph::DFSUtil(int u, int color[])
{
    color[u]=GREAY;

    list<int>::iterator i;
    for(i=adj[u].begin();i!=adj[u].end();i++){
        int v=*i;
        if(color[v]==GREAY){
            return true;
        }
        if(color[v]==WHITE && DFSUtil(v,color)){
            return true;
        }
    }
}

bool Graph::iscyclic()
{
    int *color=new int[V];
    for(int i=0;i<V;i++){
        color[i]=WHITE;
    }

    for(int i=0;i<V;i++){
        if(color[i]==WHITE){
            if(DFSUtil(i,color)==true){
                return true;
            }
        }
    }
    return false;
}

int main()
{
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(2,0);
    g.addEdge(2,3);
    g.addEdge(3,3);

    g.iscyclic()?cout<<"YES":cout<<"NO";
    return 0;
}