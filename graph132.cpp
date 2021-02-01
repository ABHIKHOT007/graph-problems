#include <bits/stdc++.h>
using namespace std;

//Number of relation possible in friends using get connected componentes
/*
class Graph
{
    int V;
    list<int> *adj;
    int countUtil(int v, bool visited[]);

public:
    Graph(int V);
    void addrelation(int v, int w);
    void countgroups();
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addrelation(int v, int w)
{
    v--;
    w--;
    adj[v].push_back(w);
    adj[w].push_back(v);
}

int Graph::countUtil(int v, bool visited[])
{
    int count = 1;
    visited[v] = true;
    for (auto i = adj[v].begin(); i != adj[v].end(); i++)
    {
        if (!visited[*i])
        {
            count += countUtil(*i, visited);
        }
    }
    return count;
}

void Graph::countgroups()
{
    bool *visited = new bool[V];
    memset(visited, 0, V * sizeof(int));

    int original_group = 0;
    int new_group = 0;
    for (int i = 0; i < V; i++)
    {
        if (visited[i] == false)
        {
            original_group++;
            new_group += countUtil(8, visited);
        }
    }
    if (original_group == 1)
    {
        new_group = 0;
    }

    cout << "NO of original groups are:" << original_group << endl;
    cout << "No of new groups are:" << new_group << endl;
}

int main()
{
    int n = 6;
    Graph g(n);
    g.addrelation(1, 2);
    g.addrelation(3, 4);
    g.addrelation(5, 6);

    g.countgroups();
    return 0;
}
*/