#include <bits/stdc++.h>
using namespace std;
//dial's algorithm.
#define INF 0x3f3f3f3f
class Graph
{
    int V;
    list<pair<int, int>> *adj;

public:
    Graph(int V);
    void addEdge(int u, int v, int w);
    void shortestpath(int s, int w);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<pair<int, int>>[V];
}

void Graph::addEdge(int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}

void Graph::shortestpath(int s, int w)
{
    vector<pair<int, list<int>::iterator>> dist(V);
    for (int i = 0; i < V; i++)
    {
        dist[i].first = INF;
    }
    list<int> B[w * V + 1];
    B[0].push_back(s);
    dist[s].first = 0;

    int idx = 0;
    while (1)
    {
        while (B[idx].size() == 0 && idx < w * V)
        {
            idx++;
        }
        if (idx == w * V)
        {
            break;
        }
        int u = B[idx].front();
        B[idx].pop_front();

        for (auto i = adj[u].begin(); i != adj[u].end(); i++)
        {
            int v = (*i).first;
            int w = (*i).second;

            int du = dist[u].first;
            int dv = dist[v].first;

            if (dv > du + w)
            {
                if (dv != INF)
                {
                    B[dv].erase(dist[v].second);
                    dist[v].first = du + w;
                    dv = dist[v].first;
                    B[dv].push_front(v);
                    dist[v].second = B[dv].begin();
                }
            }
        }
    }
    cout << "vertex distance from source is:" << endl;
    for (int i = 0; i < V; i++)
    {
        cout << i << " " << dist[i].first << endl;
    }
}

int main()
{
    int V = 9;
    Graph g(V);

    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 2);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    g.shortestpath(0, 14);
    return 0;
}
