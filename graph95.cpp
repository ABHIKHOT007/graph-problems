#include <bits/stdc++.h>
using namespace std;
//0-1 BFS
#define V 4

struct Node
{
    int to, weihgt;
};

vector<Node> edges[V];

void zerooneBFS(int s)
{
    int dist[V];
    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
    }

    deque<int> q;
    dist[s] = 0;
    q.push_back(s);
    dist[s] = 0;
    q.push_back(s);
    while (!q.empty())
    {
        int v = q.front();
        q.pop_front();
        for (int i = 0; i < edges[v].size(); i++)
        {
            if (dist[edges[v][i].to] > dist[v] + edges[v][i].weihgt)
            {
                dist[edges[i][i].to] = dist[v] + edges[v][i].weihgt;
            }

            if (edges[v][v].weihgt == 0)
            {
                q.push_front(edges[v][i].to);
            }
            else
            {
                q.push_back(edges[v][i].to);
            }
        }
    }

    for (int i = 0; i < V; i++)
    {
        cout << dist[i] << " ";
    }
}

void addEdge(int u, int v, int w)
{
    edges[u].push_back({v, w});
    edges[v].push_back({u, w});
}

int main()
{
    addEdge(0, 1, 0);
    addEdge(0, 7, 1);
    addEdge(1, 2, 1);
    addEdge(2, 3, 0);
    addEdge(2, 8, 1);
    addEdge(4, 5, 1);
    addEdge(5, 6, 1);
    addEdge(7, 8, 1);

    int s = 0;
    zerooneBFS(s);
    return 0;
}