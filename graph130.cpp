#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int> *adj;
    void fillorder(int v, bool visited[], stack<int> &Stack);
    int DFSUtil(int v, bool visited[]);

public:
    Graph(int V);
    void addEdge(int u, int w);
    int countSCCnodes();
    Graph getTranspose();
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int u, int w)
{
    adj[u].push_back(w);
}

int Graph::DFSUtil(int v, bool visited[])
{
    visited[v] = true;
    int ans = 1;
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); i++)
    {
        if (!visited[*i])
        {
            ans += DFSUtil(*i, visited);
        }
    }
    return ans;
}

Graph Graph::getTranspose()
{
    Graph g(V);
    for (int v = 0; v < V; v++)
    {
        list<int>::iterator i;
        for (i = adj[v].begin(); i != adj[v].end(); i++)
        {
            g.adj[*i].push_back(v);
        }
    }
    return g;
}

void Graph::fillorder(int v, bool visited[], stack<int> &Stack)
{
    visited[v] = true;
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); i++)
    {
        if (!visited[*i])
        {
            fillorder(*i, visited, Stack);
        }
    }
    Stack.push(v);
}

int Graph::countSCCnodes()
{
    int res = 0;
    stack<int> Stack;
    bool *visited = new bool[V];

    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
    }

    for (int i = 0; i < V; i++)
    {
        if (visited[i] == false)
        {
            fillorder(i, visited, Stack);
        }
    }

    Graph gr = getTranspose();

    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
    }

    while (Stack.empty() == false)
    {
        int v = Stack.top();
        Stack.pop();
        if (visited[v] == false)
        {
            int ans = gr.DFSUtil(v, visited);
            if (ans > 1)
            {
                res += ans;
            }
        }
    }
    return res;
}

int countcycle(int arr[], int n)
{
    int res = 0;

    Graph g(n + 1);

    for (int i = 1; i <= n; i++)
    {
        int x = arr[i - 1];
        int v = (x + i) % n + 1;
        g.addEdge(i, v);
    }
    res += g.countSCCnodes();

    return res;
}

int main()
{
    int arr[] = {1, 1, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << countcycle(arr, n);
    return 0;
}