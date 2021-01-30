#include <bits/stdc++.h>
using namespace std;

void DFS(vector<int> g[], int vis[], int odd[], int deg[], int comp, int v)
{
    vis[v] = 1;
    if (deg[v] % 2 == 1)
    {
        odd[comp]++;
    }

    for (int u : g[v])
    {
        if (vis[u] == 0)
        {
            DFS(g, vis, odd, deg, comp, u);
        }
    }
}

int minEdge(int n, int m, int s[], int d[])
{
    vector<int> g[n + 1], e, o;

    int deg[n + 1];
    int vis[n + 1];
    int odd[n + 1];
    memset(deg, 0, sizeof(deg));
    memset(vis, 0, sizeof(vis));
    memset(odd, 0, sizeof(odd));

    for (int i = 0; i < m; i++)
    {
        g[s[i]].push_back(d[i]);
        g[d[i]].push_back(s[i]);
    }

    int ans = 0;
    int comp = 0;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            comp++;
            DFS(g, vis, odd, deg, comp, i);

            if (odd[comp] == 0)
            {
                e.push_back(comp);
            }
            else
            {
                o.push_back(comp);
            }
        }
    }
    if (o.size() == 0)
    {
        return e.size();
    }
    if (e.size() != 0)
    {
        ans += e.size();
    }
    for (int i : o)
    {
        ans += odd[i] / 2;
    }

    return ans;
}

int main()
{
    int n = 3;
    int m = 2;
    int source[] = {1, 2};
    int destination[] = {2, 3};

    cout << minEdge(n, m, source, destination) << endl;
    return 0;
}