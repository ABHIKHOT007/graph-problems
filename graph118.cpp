#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int> *adj;
    bool iscycleUtil(int v, bool visited[], int parent);

public:
    Graph(int V);
    void addEdge(int v, int w);
    bool isTree();
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

bool Graph::iscycleUtil(int v, bool visited[], int parent)
{
    visited[v] = true;

    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); i++)
    {
        if (!visited[*i])
        {
            if (iscycleUtil(*i, visited, v))
            {
                return true;
            }
        }
        else if (*i != parent)
        {
            return true;
        }
    }
    return false;
}

bool Graph::isTree()
{
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
    }

    if (iscycleUtil(0, visited, -1))
    {
        return false;
    }

    return true;
}

int main()
{
    Graph g(5);
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(3, 4);
    g.isTree() ? cout << "YES" << endl : cout << "NO" << endl;

    Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 1);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    g1.isTree() ? cout << "YES" << endl : cout << "NO" << endl;

    return 0;
}