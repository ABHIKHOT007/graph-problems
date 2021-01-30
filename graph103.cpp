#include <bits/stdc++.h>
using namespace std;
#define NTL -1

class Graph
{
    int V;
    list<int> *adj;
    void APUtil(int v, bool visited[], int disc[], int low[], int parent[], bool ap[]);

public:
    Graph(int V);
    void addEdge(int v, int w);
    void ap();
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

void Graph::APUtil(int u, bool visited[], int disc[], int low[], int parent[], bool ap[])
{
    static int time = 0;
    visited[u] = time;
    int children = 0;
    disc[u] = low[u] = ++time;
    list<int>::iterator i;
    for (i = adj[u].begin(); i != adj[u].end(); i++)
    {
        int v = *i;
        if (!visited[v])
        {
            children++;
            parent[v] = u;
            APUtil(v, visited, disc, low, parent, ap);
            low[u] = min(low[u], low[v]);
            if (parent[u] = NTL && children > 1)
            {
                ap[u] = true;
            }
            if (parent[u] != NTL && low[v] >= disc[u])
            {
                ap[u] = true;
            }
        }
        else if (v != parent[u])
        {
            low[u] = min(low[u], disc[v]);
        }
    }
}

void Graph::ap()
{
    bool *visited = new bool[V];
    int *disc = new int[V];
    int *low = new int[V];
    int *parent = new int[V];
    bool *ap = new bool[V];

    for (int i = 0; i < V; i++)
    {
        if (visited[i] == false)
        {
            APUtil(i, visited, disc, low, parent, ap);
        }
    }

    for (int i = 0; i < V; i++)
    {
        if (ap[i] == true)
        {
            cout << i << " ";
        }
    }
}

int main()
{
    cout << "Articulation points in first\n";
    Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 1);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    g1.ap();
    cout << "\n";
    cout << "Articulation points in second graph\n";
    Graph g2(4);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.addEdge(2, 3);
    g2.ap();

    return 0;
}