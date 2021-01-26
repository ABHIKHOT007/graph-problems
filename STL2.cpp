#include <bits/stdc++.h>
using namespace std;

//prim's algorithm

/*
#define V 5

int minkey(int key[], bool visited[])
{
    int min = INT_MAX;
    int min_index;

    for (int v = 0; v < V; v++)
    {
        if (visited[v] == false && key[v] < min)
        {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

void printsloution(int parent[], int graph[V][V])
{
    cout << "Edge\tWeight\n";
    for (int i = 1; i < V; i++)
    {
        cout << parent[i] << "="
             << "\t" << graph[i][parent[i]] << "\n";
    }
}

void primsalgorithm(int graph[V][V])
{
    int parent[V];
    int key[V];
    bool visited[V];
    for (int i = 0; i < V; i++)
    {
        key[i] = INT_MAX;
        visited[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++)
    {
        int u = minkey(key, visited);
        visited[u] = true;
        for (int v = 0; v < V; v++)
        {
            if (graph[u][v] && visited[v] == false && graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
    printsloution(parent, graph);
}

int main()
{
    int graph[V][V] = {{0, 2, 0, 6, 0},
                       {2, 0, 3, 8, 5},
                       {0, 3, 0, 0, 7},
                       {6, 8, 0, 0, 9},
                       {0, 5, 7, 9, 0}};
    primsalgorithm(graph);
    return 0;
}*/

#define INF 0x3f3f3f3f
typedef pair<int, int> ipair;

class Graph
{
    int V;
    list<pair<int, int>> *adj;

public:
    Graph(int V);
    void addEdge(int u, int v, int w);
    void primsalgorithm();
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<ipair>[V];
}

void Graph::addEdge(int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}

void Graph::primsalgorithm()
{
    priority_queue<ipair, vector<ipair>, greater<ipair>> pq;

    int s = 0;
    vector<int> key(V, INF);
    vector<int> parent(V, -1);
    vector<bool> ismst(V, false);

    pq.push(make_pair(0, s));
    key[s] = 0;
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        ismst[u] = true;

        list<pair<int, int>>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); i++)
        {
            int v = (*i).first;
            int weight = (*i).second;
            if (ismst[v] == false && key[v] > weight)
            {
                key[v] = weight;
                pq.push(make_pair(key[v], v));
                parent[v] = u;
            }
        }
    }
    for (int i = 1; i < V; i++)
    {
        cout << parent[i] << " = " << i << endl;
    }
}

int main()
{
    int V = 9;
    Graph g(V);

    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(7, 8, 7);

    g.primsalgorithm();
    return 0;
}