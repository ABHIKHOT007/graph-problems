#include <bits/stdc++.h>
using namespace std;
#define INF INT_MAX
//shortest path in directed acyclic graph using topological sort.

class AdjListNode
{
    int v;
    int w;

public:
    AdjListNode(int _v, int _w)
    {
        v = _v;
        w = _w;
    }
    int getV()
    {
        return v;
    }
    int getW()
    {
        return w;
    }
};

class Graph
{
    int V;
    list<AdjListNode> *adj;
    void topologicalsortUtil(int v, bool visited[], stack<int> &Stack);

public:
    Graph(int V);
    void addEdge(int u, int v, int w);
    void shortestpath(int s);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<AdjListNode>[V];
}

void Graph::addEdge(int u, int v, int w)
{
    AdjListNode node(v, w);
    adj[u].push_back(node);
}

void Graph::topologicalsortUtil(int v, bool visited[], stack<int> &Stack)
{
    visited[v] = true;

    list<AdjListNode>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); i++)
    {
        AdjListNode node = *i;
        if (!visited[node.getV()])
        {
            topologicalsortUtil(node.getV(), visited, Stack);
        }
    }
    Stack.push(v);
}

void Graph::shortestpath(int s)
{
    stack<int> Stack;
    int dist[V];

    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
    }

    for (int i = 0; i < V; i++)
    {
        if (visited[i] == false)
        {
            topologicalsortUtil(i, visited, Stack);
        }
    }

    for (int i = 0; i < V; i++)
    {
        dist[i] = INF;
    }
    dist[s] = 0;

    while (!Stack.empty())
    {
        int u = Stack.top();
        Stack.pop();
        list<AdjListNode>::iterator i;
        if (dist[u] != INF)
        {
            for (i = adj[u].begin(); i != adj[u].end(); i++)
            {
                if (dist[i->getV()] > dist[u] + i->getW())
                {
                    dist[i->getV()] = dist[u] + i->getW();
                }
            }
        }
    }
    for (int i = 0; i < V; i++)
    {
        (dist[i] == INF) ? cout << "INF" : cout << dist[i] << " ";
    }
}

int main()
{
    Graph g(6);
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 3, 6);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(2, 3, 7);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);
    int s = 1;
    cout << "following are the shortest distance from the source" << s << "n" << endl;
    g.shortestpath(s);
    return 0;
}
