#include<bits/stdc++.h>
using namespace std;

class Graph
{
public:
    int V;
    list<int> *adj;
    Graph(int V);
    void addEdge(int u, int v);
    vector<int> BFS(int comnum, int s, int visited[]);
};

Graph::Graph(int V)
{
    this->V=V;
    adj=new list<int>[V];
}

void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

vector<int> Graph::BFS(int comnum, int s, int visited[])
{
    queue<int> queue;
    queue.push(s);
    visited[s]=comnum;
    vector<int> reachablenodes;
    while(!queue.empty()){
        int u=queue.front();
        queue.pop();
        reachablenodes.push_back(u);
        for(auto itr=adj[u].begin();itr!=adj[u].end();itr++){
            if(!visited[*itr]){
                visited[*itr]=comnum;
                queue.push(*itr);
            }
        }
    }
    return reachablenodes;
}

void displayreachablenodes(int n, unordered_map<int,vector<int>> hash)
{
    vector<int> temp=hash[n];
    for(int i=0;i<temp.size();i++){
        cout<<temp[i]<<" ";
    }
    cout<<endl;
}

void findreachablenodes(Graph g, int arr[], int n)
{
    int V=g.V;
    int visited[V+1];
    unordered_map<int,vector<int>> hash;
    int comnum=0;
    for(int i=0;i<n;i++){
        int u=arr[i];
        if(!visited[u]){
            hash[visited[u]]=g.BFS(comnum,u,visited);
        }
        cout<<"rechable nodex from"<<u<<"are\n";
        displayreachablenodes(visited[u],hash);
    }
}
int main()
{
    int V=7;
    Graph g(V);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(3,1);
    g.addEdge(5,6);
    g.addEdge(5,7);
    int arr[]={2,4,5};
    int n=sizeof(arr)/sizeof(int);

}