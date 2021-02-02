#include <bits/stdc++.h>
using namespace std;
const int V = 4;

//for disconnected graph.

bool isBipertiteUtil(int g[][V], int s, int color[])
{
    color[s] = 1;
    queue<int> q;
    q.push(s);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        if (g[u][u] == 1)
        {
            return false;
        }
        for (int v = 0; v < V; v++)
        {
            if (g[u][v] && color[v] == -1)
            {
                color[v] = 1 - color[u];
                q.push(v);
            }
            else if (g[u][v] && color[v] == color[u])
            {
                return false;
            }
        }
    }
    return true;
}

bool isBipertite(int g[][V])
{
    int color[V];
    for (int i = 0; i < V; i++)
    {
        color[i] = -1;
    }
    for (int i = 0; i < V; i++)
    {
        if (color[i] == -1)
        {
            if (isBipertiteUtil(g, i, color) == false)
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int g[][V] = {{0, 1, 0, 1},
                  {1, 0, 1, 0},
                  {0, 1, 0, 1},
                  {1, 0, 1, 0}};
    isBipertite(g) ? cout << "YES" : cout << "NO";
    return 0;
}