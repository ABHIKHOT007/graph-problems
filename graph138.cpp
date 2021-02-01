#include <bits/stdc++.h>
using namespace std;
//kosaraju algorithm for stringly connected compomnents.

class Graph
{
    int V;
    list<int> *adj;
    void DFSUtil(int v, bool visited[]);

public:
    Graph(int V)
    {
        this->V = V;
        adj = new list<int>[V];
    }
    ~Graph()
    {
        delete[] adj;
    }

    void addEdge(int v, int w);
    bool isconnected();
    Graph getTranspose();
};

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

Graph Graph::getTranspose()
{
    Graph g(V);
    for (int v = 0; v < V; v++)
    {
        for (auto i = adj[v].begin(); i != adj[v].end(); i++)
        {
            g.adj[*i].push_back(v);
        }
    }
    return g;
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

bool Graph::isconnected()
{
    bool visited[V];
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
    }

    DFSUtil(0, visited);

    for (int i = 0; i < V; i++)
    {
        if (visited[i] == false)
        {
            return false;
        }
    }

    Graph gr = getTranspose();

    for (int i = 0; i < V; i++)
    {
        visited[i] = true;
    }

    gr.DFSUtil(0, visited);

    for (int i = 0; i < V; i++)
    {
        if (visited[i] == false)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 0);
    g.addEdge(2, 4);
    g.addEdge(4, 2);
    g.isconnected() ? cout << "YES" : cout << "NO";

    return 0;
}