#include<bits/stdc++.h>
using namespace std;
//decting negative edge cycle in disconnected graph using bellman ford.

struct Edge
{
    int s,d,w;
};

struct Graph
{
    int V;
    int E;
    struct Edge *edge;
};

struct Graph *createGraph(int V, int E)
{
    struct Graph *graph = new Graph;
    graph->V=V;
    graph->E=E;
    graph->edge=new Edge[graph->E];
    return graph;
}

bool isnegative(struct Graph *graph, int s, int dist[])
{
    int V=graph->V;
    int E=graph->E;

    for(int i=0;i<V;i++){
        dist[i]=INT_MAX;
    }
    dist[s]=0;

    for(int i=1;i<V-1;i++){
        for(int j=0;j<E;j++){
            int u=graph->edge[j].s;
            int v=graph->edge[j].d;
            int w=graph->edge[j].w;
            if(dist[u]!=INT_MAX && dist[u]+w < dist[u]){
                dist[u]=dist[u]+w;
            }
        }
    }

    for(int i=0;i<E;i++){
        int u=graph->edge[i].s;
        int v=graph->edge[i].d;
        int w=graph->edge[i].w;
        if(dist[u]!=INT_MAX && dist[u]+w < dist[v]){
            return true;
        }
    }
    return false;
}

bool isnegativedisconnected(struct Graph *graph)
{
    int V=graph->V;
    bool visited[V];
   // bool visited[]={V,0};
    memset(visited,0,sizeof(visited));

    int dist[V];

    for(int i=0;i<V;i++){
        if(visited[i]==false){
            if(isnegative(graph,i,dist)){
                return true;
            }
            for(int i=0;i<V;i++){
                if(dist[i]!=INT_MAX){
                    visited[i]=true;
                }
            }
        }
    }
    return false;
}

int main()
{
    int V=5;
    int E=8;
    struct Graph *graph = createGraph(V,E);

    graph->edge[0].s=0;
    graph->edge[0].d=1;
    graph->edge[0].w=-1;

    graph->edge[1].s=0;
    graph->edge[1].d=2;
    graph->edge[1].w=4;

    graph->edge[2].s=1;
    graph->edge[2].d=2;
    graph->edge[2].w=3;

    graph->edge[3].s=1;
    graph->edge[3].d=3;
    graph->edge[3].w=2;

    graph->edge[4].s=1;
    graph->edge[4].d=4;
    graph->edge[4].w=2;

    graph->edge[5].s=3;
    graph->edge[5].d=2;
    graph->edge[5].w=5;

    graph->edge[6].s=3;
    graph->edge[6].d=1;
    graph->edge[6].w=-3;

    graph->edge[7].s=4;
    graph->edge[7].d=3;
    graph->edge[7].w=-3;

    isnegativedisconnected(graph)?cout<<"YES":cout<<"NO";
    return 0;    
}