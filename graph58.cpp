#include<bits/stdc++.h>
using namespace std;

#define V 4
#define INF 9999

void prinshortestpath(int dist[][V]);

bool negcycleswarshell(int graph[][V])
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
    for(int i=0;i<V;i++){
        if(dist[i][i]<0){
            return true;
        }
    }
    return false;
}

int main()
{
    int graph[V][V]={{0,1,INF,INF},{INF,0,-1,INF},{INF,INF,0,-1},{-1,INF,INF,0}};
    negcycleswarshell(graph)?cout<<"YES":cout<<"NO";
    return 0;
}