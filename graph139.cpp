#include <bits/stdc++.h>
using namespace std;
//finding brideges in graph using DFS algorithm.
class Graph
{
    int V;
    list<int> *adj;
    void DFSUtil(int v, bool visited[]);

public:
    Graph(int V);
    void addEdge(int v, int w);
    bool isconnected();
    bool isBridge(int u, int v);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void Graph::DFSUtil(int v, bool visited[])
{
    visited[v] = true;
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); i++)
    {
        if (!visited[*i])
        {
            DFSUtil(*i, visited);
        }
    }
}

bool Graph::isconnected()
{
    bool visited[V];
    memset(visited, false, sizeof(visited));
    DFSUtil(0, visited);

    for (int i = 1; i < V; i++)
    {
        if (visited[i] == false)
        {
            return false;
        }
    }
    return true;
}

bool Graph::isBridge(int u, int v)
{
    adj[u].remove(v);
    adj[v].remove(u);

    bool res = isconnected();
    addEdge(u, v);
    return (res == false);
}

int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.isBridge(1, 2) ? cout << "YES" : cout << "NO";
    return 0;
}