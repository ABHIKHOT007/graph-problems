#include<bits/stdc++.h>
using namespace std;

class Edge
{
    public:
    int s,d;
};

class Graph
{
    public:
    int V, E;
    Edge *edge;
};

Graph *createGraph(int V, int E)
{
    Graph *graph = new Graph();
    graph->V=V;
    graph->E=E;
    graph->edge=new Edge[graph->E *sizeof(Edge)];
    return graph;
}

int find(int parent[], int i)
{
    if(parent[i]==-1){
        return i;
    }
    else{
        return find(parent,parent[i]);
    }
}

void Union(int parent[], int x, int y)
{
    parent[x]=y;
}

int iscycle(Graph *graph)
{
    int *parent=new int[graph->V *sizeof(int)];
    memset(parent,-1,sizeof(int) *graph->V);
    for(int i=0;i<graph->E;i++){
        int x=find(parent,graph->edge[i].s);
        int y=find(parent,graph->edge[i].d);

        if(x==y){
            return 1;
        }

        Union(parent,x,y);
    }
    return 0;
}

int main()
{
    int V=3,E=3;

    Graph *graph = createGraph(V,E);

    graph->edge[0].s=0;
    graph->edge[0].d=1;

    graph->edge[1].s=1;
    graph->edge[1].d=2;

    graph->edge[2].s=0;
    graph->edge[2].d=2;
     
     iscycle(graph)?cout<<"YES":cout<<"NO";
     return 0;
}