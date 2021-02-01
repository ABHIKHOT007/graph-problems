#include <bits/stdc++.h>
using namespace std;
//connected components in unidirected graph.
class Graph
{
    int V;
    list<int> *adj;
    void DFSUtil(int v, bool visited[]);

public:
    Graph(int V);
    ~Graph();
    void addEdge(int v, int w);
    void connectedcomponents();
};

void Graph::connectedcomponents()
{
    bool *visited = new bool[V];
    for (int v = 0; v < V; v++)
    {
        visited[v] = false;
    }

    for (int v = 0; v < V; v++)
    {
        if (visited[v] == false)
        {
            DFSUtil(v, visited);
            cout << "\n";
        }
    }
    delete[] visited;
}

void Graph::DFSUtil(int v, bool visited[])
{
    visited[v] = true;
    cout << v << " ";

    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end();i++)
    {
        if (!visited[*i])
        {
            DFSUtil(*i, visited);
        }
    }
}

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

Graph::~Graph()
{
    delete[] adj;
}

void Graph::addEdge(int u, int w)
{
    adj[u].push_back(w);
    adj[w].push_back(u);
}

int main()
{
    Graph g(5);
    g.addEdge(1, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    cout << "following are the connected components int he graph:" << endl;
    g.connectedcomponents();

        return 0;
}