#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f

//shortest path in unweighted graph
struct Edge
{
    int u;
    int v;
    int weight;
};

class Graph
{
    int V;
    list<pair<int, int>> *adj;

    vector<Edge> edge;

public:
    Graph(int V)
    {
        this->V = V;
        adj = new list<pair<int, int>>[V];
    }

    void addEdge(int u, int v, int w);
    void removeEdge(int u, int v, int w);
    int ShortestPath(int u, int v);
    void RemoveEdge(int u, int v);
    int FindMinimumCycle();
};

void Graph ::addEdge(int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));

    Edge e{u, v, w};
    edge.push_back(e);
}

void Graph ::removeEdge(int u, int v, int w)
{
    adj[u].remove(make_pair(v, w));
    adj[v].remove(make_pair(u, w));
}

int Graph ::ShortestPath(int u, int v)
{
    set<pair<int, int>> setds;

vector<int> dist(V, INF);

setds.insert(make_pair(0, u));
dist[u] = 0;

while (!setds.empty())
{
    pair<int, int> tmp = *(setds.begin());
    setds.erase(setds.begin());

    int u = tmp.second;

    list<pair<int, int>>::iterator i;
    for (i = adj[u].begin(); i != adj[u].end(); ++i)
    {
        int v = (*i).first;
        int weight = (*i).second;

        if (dist[v] > dist[u] + weight)
        {
            if (dist[v] != INF)
                setds.erase(setds.find(make_pair(dist[v], v)));

            dist[v] = dist[u] + weight;
            setds.insert(make_pair(dist[v], v));
        }
    }
}
return dist[v];
}

int Graph ::FindMinimumCycle()
{
    int min_cycle = INT_MAX;
    int E = edge.size();
    for (int i = 0; i < E; i++)
    {

        Edge e = edge[i];

        removeEdge(e.u, e.v, e.weight);

        int distance = ShortestPath(e.u, e.v);

        min_cycle = min(min_cycle, distance + e.weight);

        addEdge(e.u, e.v, e.weight);
    }

    return min_cycle;
}

int main()
{
    int V = 9;
    Graph g(V);

    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    cout << g.FindMinimumCycle() << endl;
    return 0;
}
