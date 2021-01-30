#include <bits/stdc++.h>
using namespace std;

struct graph
{
    int V;
    int e;
    int **dir;
};

int finddegree(struct graph *G, int ver)
{
    int degree = 0;
    for (int i = 0; i < G->V; i++)
    {
        if (G->dir[ver][i] == 1)
        {
            degree++;
        }
    }

    if (G->dir[ver][ver] == 1)
    {
        degree++;
    }
    return degree;
}

struct graph *createGraph(int V, int e)
{
    struct graph *G = new graph;

    G->V = V;
    G->e = e;
    G->dir = new int *[V];

    for (int i = 0; i < V; i++)
    {
        G->dir[i] = new int[V];
    }

    G->dir[0][1] = 1;
    G->dir[0][2] = 1;
    G->dir[0][2] = 1;

    G->dir[1][0] = 1;
    G->dir[1][3] = 1;

    G->dir[2][0] = 1;
    G->dir[2][3] = 1;

    G->dir[3][0] = 1;
    G->dir[3][1] = 1;
    G->dir[3][2] = 1;
    return G;
}

int main()
{
    int vertices = 4;
    int edges = 5;
    struct graph *G = createGraph(vertices, edges);

    int ver = 0;
    int degree = finddegree(G, ver);
    cout << degree << "\n";
    return 0;
}