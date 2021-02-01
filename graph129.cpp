#include <bits/stdc++.h>
using namespace std;

//Eulerian path.
/*
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

    void removeEdge(int u, int v);
    void printEulerianpath();
    void printEulerianUtil(int s);
    int DFSUtil(int v, bool visited[]);
    bool isvalid(int u, int v);
};

void Graph::printEulerianpath()
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
    printEulerianUtil(u);
    cout << endl;
}

void Graph::printEulerianUtil(int u)
{
    list<int>::iterator i;
    for (i = adj[u].begin(); i != adj[u].end(); i++)
    {
        int v = *i;
        if (v != -1 && isvalid(u, v))
        {
            cout << u << "-" << v << " ";
            removeEdge(u, v);
            printEulerianUtil(v);
        }
    }
}

bool Graph::isvalid(int u, int v)
{
    int count = 0;
    list<int>::iterator i;
    for (i = adj[u].begin(); i != adj[u].end(); i++)
    {
        if (*i = -1)
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
    int count1 = DFSUtil(u, visited);

    removeEdge(u, v);
    memset(visited, false, V);
    int count2 = DFSUtil(u, visited);

    addEdge(u, v);

    return (count1 > count2) ? false : true;
}

void Graph::removeEdge(int u, int v)
{
    list<int>::iterator iv = find(adj[u].begin(), adj[u].end(), V);
    *iv = -1;

    list<int>::iterator iu = find(adj[v].begin(), adj[v].end(), u);

    *iu = -1;
}

int Graph::DFSUtil(int v, bool visited[])
{
    visited[v] = true;
    int count = 1;

    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); i++)
    {
        if (*i != -1 && !visited[*i])
        {
            count += DFSUtil(*i, visited);
        }
    }
    return count;
}

int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.printEulerianpath();
    return 0;
}
*/