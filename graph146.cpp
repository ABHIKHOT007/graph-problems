#include <bits/stdc++.h>
using namespace std;
#define V 4

void multiply(int a[][V], int b[][V], int c[][V])
{
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            c[i][j] = 0;
            for (int k = 0; k < V; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int getTrance(int graph[][V])
{
    int trance = 0;
    for (int i = 0; i < V; i++)
    {
        trance += graph[i][i];
    }
    return trance;
}

int triangleGraph(int graph[][V])
{
    int aux1[V][V];
    int aux2[V][V];
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            aux1[i][j] = aux2[i][j] = 0;
        }
    }
    multiply(graph, graph, aux1);
    multiply(graph, aux1, aux2);

    int trance = getTrance(aux2);
    return trance / 6;
}

int main()
{
    int graph[V][V] = {{0, 1, 1, 0},
                       {1, 0, 1, 1},
                       {1, 1, 0, 1},
                       {0, 1, 1, 0}};
    cout << "Total no of triangle in graph are:" << triangleGraph(graph);
    return 0;
}