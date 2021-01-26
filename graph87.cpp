#include <bits/stdc++.h>
using namespace std;

#define V 4
#define INF INT_MAX

int shortestpath(int graph[][V], int u, int v, int k)
{
    if (k == 0 && u == v)
        return 0;
    if (k == 1 && graph[u][v] != INF)
        return graph[u][v];
    if (k <= 0)
        return INF;

    int res = INF;

    for (int i = 0; i < V; i++)
    {
        if (graph[u][i] != INF && u != i && v != i)
        {
            int rec_res = shortestpath(graph, i, v, k - 1);
            if (rec_res != INF)
            {
                res = min(res, graph[u][i] + rec_res);
            }
        }
    }
    return res;
}

int main()
{
    int graph[V][V] = {{0, 10, 3, 2}, {INF, 0, INF, 7}, {INF, INF, 0, 6}, {INF, INF, INF, 0}};
    int u = 0, v = 3, k = 2;
    cout << "weight of the shortest path is:" << shortestpath(graph, u, v, k) << endl;
    return 0;
}