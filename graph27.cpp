#include<bits/stdc++.h>
using namespace std;

long long count_color[2];

void DFS(vector<int> adj[], int node, int parent, int color)
{
    count_color[color]++;

    for(int i=0;i<adj[node].size();i++){
        if(adj[node][i]!=parent){
            DFS(adj,adj[node][i],node,!color);
        }
    }
}

int findmaxedge(vector<int> adj[], int n)
{
    DFS(adj,1,0,0);
    return count_color[0]*count_color[1]-(n-1);
}

int main()
{
    int n=5;
    vector<int> adj[n+1];
    adj[1].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(4);
    adj[3].push_back(5);
    cout<<findmaxedge(adj,n);
    return 0;
}