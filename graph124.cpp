#include <bits/stdc++.h>
using namespace std;

//print all possible from source to destination.

class Graph
{
    int V;
    list<int> *adj;
    void printallpathsUtil(int s, int d, bool visited[], int path[], int &path_index);

public:
    Graph(int V);
    void addEdge(int u, int v);
    void printallpaths(int s, int d);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v);
}

void Graph::printallpathsUtil(int s, int d, bool visited[], int path[], int &path_index)
{
    visited[s] = true;
    path[path_index] = s;
    path_index++;

    if (s == d)
    {
        for (int i = 0; i < path_index; i++)
        {
            cout << path[i] << " ";
        }
        cout << endl;
    }
    else
    {
        list<int>::iterator i;
        for (i = adj[s].begin(); i != adj[s].end(); i++)
        {
            if (!visited[*i])
            {
                printallpathsUtil(*i, d, visited, path, path_index);
            }
        }
    }
    path_index--;
    visited[s] = false;
}

void Graph::printallpaths(int s, int d)
{
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
    }

    int *path = new int[V];
    int path_index = 0;

    printallpathsUtil(s, d, visited, path, path_index);
}

int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(2, 0);
    g.addEdge(2, 1);
    g.addEdge(1, 3);

    int s = 2;
    int d = 3;
    cout << "following are all possiable path from" << s << "to" << d << endl;
    g.printallpaths(s, d);
    return 0;
}