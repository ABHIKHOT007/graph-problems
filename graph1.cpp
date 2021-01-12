#include<bits/stdc++.h>
using namespace std;

//representation of graph by adjency list.

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
}

void printgraph(vector<int> adj[], int V)
{
    for(int v=0;v<V;v++){
        for(auto x:adj[v]){
            cout<<"="<<x;
        }
        cout<<endl;
    }
}

int main()
{
    int V=5;
    vector<int> adj[V];
    addEdge(adj,0,1);
    addEdge(adj,0,1);
    addEdge(adj,1,2);
    addEdge(adj,1,3);
    addEdge(adj,2,4);
    addEdge(adj,3,4);
    printgraph(adj,V);
    return 0;
}