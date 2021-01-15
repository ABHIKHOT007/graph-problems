#include<bits/stdc++.h>
using namespace std;

//o(V+E)

/*void addEdge(vector<int>adj[], int v, int u)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}*/

void addEdge(vector<int> adj[], int v, int u)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

/*void DFS(int u,vector<int> adj[],vector<bool> &visited)
{
    visited[u]=true;
    for(int i=0; i<adj[u].size(); i++){
        DFS(adj[u][i],adj,visited);
    }
}*/

void DFS(int u,vector<int> adj[],vector<bool> &visited)
{
    visited[u]=true;
    for(int i=0;i<adj[u].size();i++){
        DFS(adj[u][i],adj,visited);
    }
}

int countTrees(vector<int> adj[], int V)
{
    vector<bool> visited(V,false);
    int res=0;
    for(int u=0;u<V;u++){
        if(visited[u]==false){
            DFS(u,adj,visited);
            res++;
        }
    }
    return res;
}

/*int countTrees(vector<int> adj[], int V)
{
    vector<bool> visited(V,false);
    int res=0;
    for(int u=0;u<V;u++){
        if(visited[u]==false){
            DFS(u,adj,visited);
        }
    }
}*/

int main()
{
    int V=5;
    vector<int> adj[V];
    addEdge(adj,0,1);
    addEdge(adj,0,2);
    addEdge(adj,3,4);
    cout<<"No of the trees are:"<<endl;
    cout<<countTrees(adj,V);
    return 0;
}