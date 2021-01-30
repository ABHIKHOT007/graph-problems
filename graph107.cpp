#include <bits/stdc++.h>
#define NTL -1
using namespace std;
//bridge between graphs.

class Graph
{
    int V;
    list<int> *adj;
    void isBridgeUtil(int v, bool visited[], int disc[], int low[], int parent[]);

public:
    Graph(int V);
    void addEdge(int v, int w);
    void isBridge();
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

void Graph::isBridgeUtil(int u, bool visited[], int disc[], int low[], int parent[])
{
    static int time = 0;
    visited[u] = true;
    disc[u] = low[u] = ++time;

    list<int>::iterator i;
    for (i = adj[u].begin(); i != adj[u].end(); i++)
    {
        int v = *i;
        if (!visited[v])
        {
            parent[v] = u;
            isBridgeUtil(v, visited, disc, low, parent);

            low[u] = min(low[u], low[v]);

            if (low[v] > disc[u])
            {
                cout << u << " " << v << endl;
            }
        }
        else if (v != parent[u])
        {
            low[u] = min(low[u], disc[v]);
        }
    }
}

void Graph::isBridge()
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

    for (int i = 0; i < V; i++)
    {
        if (visited[i] == false)
        {
            isBridgeUtil(i, visited, disc, low, parent);
        }
    }
}

int main()
{
    cout << "Bridge in first graph\n";
    Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 1);
    g1.addEdge(0, 3);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    g1.isBridge();
    cout << "\n";

    cout << "Bridge in second graph\n";
    Graph g2(4);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.addEdge(2, 3);
    g2.isBridge();
    cout << "\n";

    cout << "Bridge in third graph\n";
    Graph g3(7);
    g3.addEdge(0, 1);
    g3.addEdge(1, 2);
    g3.addEdge(2, 0);
    g3.addEdge(1, 3);
    g3.addEdge(1, 4);
    g3.addEdge(1, 6);
    g3.addEdge(3, 5);
    g3.addEdge(4, 5);
    g3.isBridge();

    return 0;
}