#include <bits/stdc++.h>
using namespace std;
#define NTL -1

class Graph
{
    int V;
    list<int> *adj;
    bool isBiconnectedUtil(int v, bool visited[], int disc[], int low[], int parent[]);

public:
    Graph(int V);
    void addEdge(int v, int w);
    bool isBiconnected();
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

bool Graph::isBiconnectedUtil(int u, bool visited[], int disc[], int low[], int parent[])
{
    static int time = 0;
    int children = 0;
    visited[u] = true;
    disc[u] = low[u] = ++time;
    list<int>::iterator i;
    for (i = adj[u].begin(); i != adj[u].end(); i++)
    {
        int v = *i;
        if (!visited[v])
        {
            children++;
            parent[v] = u;
            low[u] = min(low[u], low[v]);
            if (parent[u] == NTL && children > 1)
            {
                return true;
            }
            if (parent[u] != NTL && low[v] >= disc[u])
            {
                return true;
            }
        }
        else if (v != parent[u])
        {
            low[u] = min(low[u], disc[v]);
        }
    }
    return false;
}

bool Graph::isBiconnected()
{
    bool *visited = new bool[V];
    int *disc = new int[V];
    int *low = new int[V];
    int *parent = new int[V];

    for (int i = 0; i < V; i++)
    {
        parent[i] = NTL;
        visited[i] = false;
    }

    if (isBiconnectedUtil(0, visited, disc, low, parent) == true)
    {
        return false;
    }
    for (int v = 0; v < V; v++)
    {
        if (visited[v] == false)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    Graph g1(2);
    g1.addEdge(0, 1);
    g1.isBiconnected() ? cout << "YES" << endl : cout << "NO" << endl;

    Graph g2(5);
    g2.addEdge(0, 1);
    g2.addEdge(0, 2);
    g2.addEdge(1, 2);
    g2.addEdge(2, 1);
    g2.addEdge(3, 4);
    g2.addEdge(2, 4);
    g2.isBiconnected() ? cout << "YES" << endl : cout << "NO" << endl;
    Graph g3(3);
    g3.addEdge(0, 1);
    g3.addEdge(1, 2);
    g3.isBiconnected() ? cout << "YES" << endl : cout << "NO" << endl;
    Graph g4(5);
    g4.addEdge(1, 0);
    g4.addEdge(0, 2);
    g4.addEdge(2, 1);
    g4.addEdge(0, 3);
    g4.addEdge(3, 4);
    g4.isBiconnected() ? cout << "YES" << endl : cout << "NO" << endl;
    Graph g5(3);
    g5.addEdge(0, 1);
    g5.addEdge(1, 2);
    g5.addEdge(2, 0);
    g5.isBiconnected() ? cout << "YES" << endl : cout << "NO" << endl;
    return 0;
}