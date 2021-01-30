#include <bits/stdc++.h>
using namespace std;

//finding path between two vertices.

class Graph
{
    int V;
    list<int> *adj;

public:
    Graph(int V);
    void addEdge(int u, int v);
    bool ispathpresent(int s, int d);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v);
}

bool Graph::ispathpresent(int s, int d)
{
    if (s == d)
    {
        return true;
    }
    vector<bool> visited(V, false);
    list<int> q;
    q.push_front(s);
    visited[s] = true;

    while (!q.empty())
    {
        s = q.front();
        q.pop_front();
        list<int>::iterator i;
        for (i = adj[s].begin(); i != adj[s].end(); i++)
        {
            if (*i == d)
            {
                return true;
            }
            if (!visited[*i])
            {
                visited[*i] = true;
                q.push_back(*i);
            }
        }
    }
    return false;
}

int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    g.ispathpresent(1, 3) ? cout << "YES"<<endl : cout << "NO" << endl;
    g.ispathpresent(3, 1) ? cout << "YES"<<endl : cout << "NO" << endl;
    g.ispathpresent(0, 1) ? cout << "YES"<<endl : cout << "NO" << endl;

    return 0;
}