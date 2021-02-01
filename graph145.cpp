#include <bits/stdc++.h>
using namespace std;

//vertex cover problem.

class Graph
{
    int V;
    list<int> *adj;

public:
    Graph(int V);
    void addEdge(int v, int w);
    void printcoververtex();
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}

void Graph::printcoververtex()
{
    bool visited[V];
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
    }

    for (int u = 0; u < V; u++)
    {
        if (visited[u] == false)
        {
            for (auto i = adj[u].begin(); i != adj[u].end(); i++)
            {
                int v = *i;
                if (visited[v] == false)
                {
                    visited[v] = true;
                    visited[u] = true;
                    break;
                }
            }
        }
    }
    for (int i = 0; i < V; i++)
    {
        if (visited[i] != false)
        {
            cout << i << " ";
        }
    }
}

int main()
{
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);

    g.printcoververtex();
    return 0;
}