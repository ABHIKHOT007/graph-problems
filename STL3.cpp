#include <bits/stdc++.h>
using namespace std;

//dijkstra's algorithm.
/*#define V 9

int minimumdistance(int dist[], bool visited[])
{
    int min = INT_MAX;
    int min_index = 0;

    for (int v = 0; v < V; v++)
    {
        if (visited[v] = false && dist[v] <= min)
        {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void printsolution(int dist[])
{
    cout << "Vertex \t\t Distance form Source\n";
    for (int i = 0; i < V; i++)
    {
        cout<< i << dist[i];
    }
}

void dijstra(int graph[V][V], int s)
{
    int dist[V];
    bool visited[V];
    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    dist[s] = 0;
    for (int count = 0; count < V - 1; count++)
    {
        int u = minimumdistance(dist, visited);
        visited[u] = true;
        for (int v = 0; v < V; v++)
        {
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    printsolution(dist);
}

int main()
{
    int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                       {4, 0, 8, 0, 0, 0, 0, 11, 0},
                       {0, 8, 0, 7, 0, 4, 0, 0, 2},
                       {0, 0, 7, 0, 9, 14, 0, 0, 0},
                       {0, 0, 0, 9, 0, 10, 0, 0, 0},
                       {0, 0, 4, 14, 10, 0, 2, 0, 0},
                       {0, 0, 0, 0, 0, 2, 0, 1, 6},
                       {8, 11, 0, 0, 0, 0, 1, 0, 7},
                       {0, 0, 2, 0, 0, 0, 6, 7, 0}};
    dijstra(graph, 0);
    return 0;
}*/

#define INF INT_MAX
typedef pair<int, int> ipair;

class Graph
{
    int V;
    list<pair<int, int>> *adj;

public:
    Graph(int V);
    void addEdge(int u, int v, int w);
    void shortestpath(int s);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<ipair>[V];
}

void Graph::addEdge(int u, int v, int w)
{
    adj[u].push_back(make_pair(u, w));
    adj[v].push_back(make_pair(u, w));
}

void Graph::shortestpath(int s)
{
    priority_queue<ipair, vector<ipair>, greater<ipair>> pq;

    vector<int> dist(V, INF);

    pq.push(make_pair(0, s));
    dist[s] = 0;

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        list<pair<int, int>>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); i++)
        {
            int v = (*i).first;
            int weight = (*i).second;

            if (dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < V; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
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
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);
    g.shortestpath(0);
    return 0;
}