#include <bits/stdc++.h>
using namespace std;
//krushal algorithm using STL.
/*class Edge
{
public:
    int s, dest, weight;
};

class Graph
{
public:
    int V, E;
    Edge *edge;
};

Graph *createGraph(int V, int E)
{
    Graph *graph = new Graph;
    graph->V = V;
    graph->E = E;
    graph->edge = new Edge[E];
    return graph;
}

class subset
{
public:
    int parent;
    int rank;
};

int find(subset subsets[], int i)
{
    if (subsets[i].parent != i)
    {
        subsets[i].parent = find(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}

void Union(subset subsets[], int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
    {
        subsets[xroot].parent = yroot;
    }
    else if (subsets[xroot].rank > subsets[yroot].rank)
    {
        subsets[yroot].parent = yroot;
    }
    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

int mycomp(const void *a, const void *b)
{
    Edge *a1 = (Edge *)a;
    Edge *b1 = (Edge *)b;
    return a1->weight > b1->weight;
}

void krushalalgorithm(Graph *graph)
{
    int V = graph->V;
    Edge result[V];
    int e = 0;
    int i = 0;

    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), mycomp);

    subset *subsets = new subset[(V * sizeof(subset))];

    for (int v = 0; v < V; v++)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }
    while (e < V - 1 && i < graph->E)
    {
        Edge next_edge = graph->edge[i++];
        int x = find(subsets, next_edge.s);
        int y = find(subsets, next_edge.dest);

        if (x != y)
        {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }
    cout << "following are the edges int the MST of the given graph:" << endl;
    int minimumcost = 0;
    for (int i = 0; i < e; i++)
    {
        cout << result[i].s << "--" << result[i].dest << "==" << result[i].weight << endl;
        minimumcost = minimumcost + result[i].weight;
    }
    cout << "minimum cost of the tree is:" << minimumcost << endl;
}

int main()
{
    int V = 4;
    int E = 5;

    Graph *graph = createGraph(V, E);

    graph->edge[0].s = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = 10;

    graph->edge[1].s = 0;
    graph->edge[1].dest = 2;
    graph->edge[1].weight = 6;

    graph->edge[2].s = 0;
    graph->edge[2].dest = 3;
    graph->edge[2].weight = 15;

    graph->edge[3].s = 1;
    graph->edge[3].dest = 3;
    graph->edge[3].weight = 15;

    graph->edge[4].s = 2;
    graph->edge[4].dest = 3;
    graph->edge[4].weight = 4;

    krushalalgorithm(graph);
    return 0;
}*/

typedef pair<int, int> ipair;

struct Graph
{
    int V, E;
    vector<pair<int, ipair>> edges;
    Graph(int V, int E)
    {
        this->V = V;
        this->E = E;
    }

    void addEdge(int u, int v, int w)
    {
        edges.push_back({w, {u, v}});
    }
    int krushalalgorithm();
};

struct DisjointSets
{
    int *parent, *rank;
    int n;

    DisjointSets(int n)
    {
        this->n = n;
        parent = new int[n + 1];
        rank = new int[n + 1];

        for (int i = 0; i <= n; i++)
        {
            rank[i] = 0;
            parent[i] = i;
        }
    }

    int find(int u)
    {
        if (u != parent[u])
        {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    void merge(int x, int y)
    {
        x = find(x), y = find(y);
        if (rank[x] > rank[y])
        {
            parent[y] = x;
        }
        else
        {
            parent[x] = y;
        }
        if (rank[x] == rank[y])
        {
            rank[y]++;
        }
    }
};

int Graph::krushalalgorithm()
{
    int mst_wt = 0;

    sort(edges.begin(), edges.end());

    DisjointSets ds(V);

    vector<pair<int, ipair>>::iterator it;
    for (it = edges.begin(); it != edges.end(); it++)
    {
        int u = it->second.first;
        int v = it->second.second;

        int set_u = ds.find(u);
        int set_v = ds.find(v);

        if (set_u != set_v)
        {
            cout << u << "=" << v << endl;
            mst_wt += it->first;
            ds.merge(set_u, set_v);
        }
    }
    return mst_wt;
}

int main()
{
    int V = 9, E = 14;
    Graph g(V, E);

    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 2);
    g.addEdge(3, 4, 9);
    g.addEdge(4, 5, 14);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 6);
    g.addEdge(7, 8, 7);

    cout << "edges of the mst are:" << endl;
    int mst_wt = g.krushalalgorithm();
    cout << "weight of the mst are:" << mst_wt;
    return 0;
}