#include <bits/stdc++.h>
using namespace std;
#define NTL -1
//strongly connected components in graph.

class Graph
{
    int V;
    list<int> *adj;
    void SCCUtil(int u, int disc[], int low[], stack<int> *Stack, bool stackmember[]);

public:
    Graph(int V);
    void addEdge(int v, int w);
    void SCC();
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

void Graph::SCCUtil(int u, int disc[], int low[], stack<int> *Stack, bool stackmember[])
{
    static int time = 0;
    disc[u] = low[u] = ++time;
    Stack->push(u);
    stackmember[u] = true;

    list<int>::iterator i;
    for (i = adj[u].begin(); i != adj[u].end(); i++)
    {
        int v = *i;
        if (disc[v] == -1)
        {
            SCCUtil(v, disc, low, Stack, stackmember);
            low[u] = min(low[u], low[v]);
        }
        else if (stackmember[v] == true)
        {
            low[u] = min(low[u], disc[v]);
        }
    }
    int w = 0;
    if (low[u] == disc[u])
    {
        while (Stack->top() != u)
        {
            w = (int)Stack->top();
            cout << w << " ";
            cout<<endl;
            stackmember[w] = false;
            Stack->pop();
        }

        w = (int)Stack->top();
        cout << w << " ";
        cout<<endl;
        stackmember[w] = false;
        Stack->pop();
    }
}

void Graph::SCC()
{
    int *disc = new int[V];
    int *low = new int[V];
    bool *stackmemer = new bool[V];
    stack<int> *Stack = new stack<int>();

    for (int i = 0; i < V; i++)
    {
        disc[i] = NTL;
        low[i] = NTL;
        stackmemer[i] = false;
    }

    for (int i = 0; i < V; i++)
    {
        if (disc[i] == NTL)
        {
            SCCUtil(i, disc, low, Stack, stackmemer);
        }
        cout<<endl;
    }
}

int main()
{
    cout << "strngly connected components in given graph is:" << endl;
    Graph g(5);
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(3, 4);
    g.SCC();

    return 0;
}