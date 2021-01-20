#include<bits/stdc++.h>
using namespace std;

//floyd warshell algorithm
#define V 4
#define INF 99999

void printshortestpath(int dist[][V]);

void flyodwarshell(int graph[][V])
{
    int dist[V][V],i,j,k;

    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            dist[i][j]=graph[i][j];
        }
    }

    for(int k=0;k<V;k++){
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(dist[i][k]+dist[k][j] < dist[i][j]){
                    dist[i][j]=dist[i][k]+dist[k][j];
                }
            }
        }
    }
    printshortestpath(dist);
}

void printshortestpath(int dist[][V])
{
    cout<<"The following matrix shows distance between every pair of the vertices"<<endl;

    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if(dist[i][j]==INF){
                cout<<"INF"<<endl;
            }
            else{
                cout<<dist[i][j]<<" ";
            }
        }
    }
}

int main()
{
    int graph[V][V]={{0,5,INF,10},{INF,0,3,INF},{INF,INF,0,1},{INF,INF,INF,0}};
    flyodwarshell(graph);
    return 0;
}