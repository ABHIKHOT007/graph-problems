#include <bits/stdc++.h>
using namespace std;

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

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void removEdge(int u, int v);
    void printEulertour();
    void printEulertourUtil(int s);
    int DFScount(int v, bool visited[]);
    bool isvalid(int u, int v);
};

void Graph::printEulertour()
{
    int u = 0;
    for (int i = 0; i < V; i++)
    {
        if (adj[i].size() & 1)
        {
            u = i;
            break;
        }
    }
}

void Graph::printEulertourUtil(int u)
{
    list<int>::iterator i;
    for (i = adj[u].begin(); i != adj[u].end(); i++)
    {
        int v = *i;
        if (V != -1 && isvalid(u, v))
        {
            cout << u << " " << v << " ";
            printEulertourUtil(v);
        }
    }
}

bool Graph::isvalid(int u, int v)
{
    int count = 0;
    list<int>::iterator i;
    for (i = adj[u].begin(); i != adj[u].end(); i++)
    {
        if (*i != -1)
        {
            count++;
        }
    }
    if (count == 1)
    {
        return true;
    }

    bool visited[V];
    memset(visited, false, V);
    int count1 = DFScount(u, visited);

    removEdge(u, v);
    memset(visited, false, V);
    int count2 = DFScount(u, visited);

    addEdge(u, v);

    return (count1 > count2) ? false : true;
}

void Graph::removEdge(int u, int v)
{
    list<int>::iterator iv = find(adj[u].begin(), adj[u].end(), v);
    *iv = -1;

    list<int>::iterator iu = find(adj[v].begin(), adj[v].end(), u);
    *iu = -1;
}

int Graph::DFScount(int v, bool visited[])
{
    visited[v] = true;
    int count = 1;

    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); i++)
    {
        if (*i = -1 && !visited[*i])
        {
            count += DFScount(*i, visited);
        }
    }
    return count;
}

int main()
{
    Graph g1(4);
    g1.addEdge(0, 1);
    g1.addEdge(0, 2);
    g1.addEdge(2, 3);
    g1.printEulertour();

    Graph g2(3);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.printEulertour();

    Graph g3(5);
    g3.addEdge(1, 0);
    g3.addEdge(0, 2);
    g3.addEdge(2, 1);
    g3.addEdge(0, 3);
    g3.addEdge(3, 4);
    g3.addEdge(3, 2);
    g3.addEdge(3, 1);
    g3.addEdge(2, 4);
    g3.printEulertour();

    return 0;
}
