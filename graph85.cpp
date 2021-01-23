#include<bits/stdc++.h>
using namespace std;
#define V 9

int minimumdist(int dist[], bool visited[])
{
    int min=INT_MAX;
    int min_index;

    for(int v=0;v<V;v++){
        if(visited[v]==false && dist[v]<=min){
            min=dist[v];
            min_index=v;
        }
    }
    return min_index;
}

void printsolution(int dist[])
{
    cout<<"Vertex \t\t Distance from source\n";
    for(int i=0;i<V;i++){
        cout<<"%d \t\t %d\n"<<i<<dist[i];
    }
}

void dijkstras(int graph[V][V], int s)
{
    int dist[V];
    bool visited[V];

    for(int i=0;i<V;i++){
        dist[i]=INT_MAX;
        visited[i]=false;
    }
    dist[0]=0;

    for(int count=0;count<V-1;count++){
        int u=minimumdist(dist,visited);
        visited[u]=true;
        for(int v=0;v<V;v++){
            if(!visited[v] && graph[u][v] && dist[u]!=INT_MAX && dist[u]+graph[u][v] < dist[v]){
                dist[v]=dist[u]+graph[u][v];
            }
        }
    }
    printsolution(dist);
}

int main()
{
    int graph[V][V]={ { 0, 4, 0, 0, 0, 0, 0, 8, 0 }, 
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 }, 
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 }, 
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 }, 
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 }, 
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 }, 
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 }, 
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 }, 
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } }; 
  dijkstras(graph,0);
  return 0;
}