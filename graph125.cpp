#include <bits/stdc++.h>
using namespace std;

#define INF INT_MAX
#define N 4
/*
int mincostUtil(int cost[][N], int s, int d)
{
    if (s == d || s + 1 == d)
    {
        return cost[s][d];
    }

    int min = cost[s][d];

    for (int i = s + 1; i < d; i++)
    {
        int c = mincostUtil(cost, s, i) + mincostUtil(cost, i, d);
        if (c < min)
        {
            min = c;
        }
    }
    return min;
}
int mincost(int cost[][N])
{
    return mincostUtil(cost, 0, N - 1);
}

int main()
{
    int cost[N][N] = {{0, 15, 80, 90},
                      {INF, 0, 40, 50},
                      {INF, INF, 0, 70},
                      {INF, INF, INF, 0}};
    cout << "The minimum cost to reach ststion is:" << endl;
    mincost(cost);
    return 0;
}*/

int mincost(int cost[][N])
{
    int dist[N];
    for (int i = 0; i < N; i++)
    {
        dist[i] = INF;
    }
    dist[0] = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (dist[j] > dist[i] + cost[i][j])
            {
                dist[j] = dist[i] + cost[i][j];
            }
        }
    }
    return dist[N - 1];
}

int main()
{
    int cost[N][N] = {{0, 15, 80, 90},
                      {INF, 0, 40, 50},
                      {INF, INF, 0, 70},
                      {INF, INF, INF, 0}};
    cout << "minimum cost to reach statison is:" << endl;
    mincost(cost);
    return 0;
}