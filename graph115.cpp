#include <bits/stdc++.h>
using namespace std;
#define V 4
//count all possible path from source to destination in directed graph in most k edges.
//Time complexity=o(V^k).

/*int countPath(int graph[][V], int u, int v, int k)
{
    if (k == 0 && u == v)
    {
        return 1;
    }
    if (k == 1 && graph[u][v])
    {
        return 1;
    }
    if (k <= 0)
    {
        return 0;
    }

    int count = 0;

    for (int i = 0; i < V; i++)
    {
        if (graph[u][i] == 1)
        {
            count += countPath(graph, i, v, k - 1);
        }
    }
    return count;
}*/

//Efficent apporach using concepts of dynamic programming.
//Time complexity o(v^3).

#define V 4

int countPath(int graph[][V], int u, int v, int K)
{
    int count[v][V][K + 1];

    for (int k = 0; k < K; k++)
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                count[i][j][k] = 0;

                if (K == 0 && i == j)
                {
                    count[i][j][k] = 1;
                }
                if (k == 1 && graph[i][j])
                {
                    count[i][j][k] = 1;
                }
                if (k > 1)
                {
                    for (int a = 0; a < V; a++)
                    {
                        if (graph[i][a])
                        {
                            count[i][j][k] += count[a][i][k - 1];
                        }
                    }
                }
            }
        }
    }
    return count[u][v][K];
}
int main()
{
    int graph[V][V] = {{0, 1, 1, 1},
                       {0, 0, 0, 1},
                       {0, 0, 0, 1},
                       {0, 0, 0, 0}};

    int u = 0, v = 3, k = 2;
    cout << countPath(graph, u, v, k);
    return 0;
}