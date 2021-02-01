#include <bits/stdc++.h>
using namespace std;

//graph colouring problem.

class Graph
{
    int V;
    list<int> *adj;

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
    void greedalgorithm();
};

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}

void Graph::greedalgorithm()
{
    int result[V];
    result[0] = 0;

    for (int i = 1; i < V; i++)
    {
        result[i] = -1;
    }

    bool available[V];
    for (int r = 0; r < V; r++)
    {
        available[r] = false;
    }

    for (int u = 0; u < V; u++)
    {
        list<int>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); i++)
        {
            if (result[*i] != -1)
            {
                available[result[*i]] = true;
            }
        }

        for (i = adj[u].begin(); i != adj[u].end(); i++)
        {
            if (result[*i] != -1)
            {
                available[result[*i]] = false;
            }
        }
    }
    for (int u = 0; u < V; u++)
    {
        cout << u << "->" << result[u] << endl;
    }
}

int main()
{
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    g.greedalgorithm();
    return 0;
}