#include<bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int> *adj;
    void topologicalsortUtil(int v, bool visited[], stack<int> &s);
public:
    Graph(int V);
    void addEdge(int v, int w);
    void topologicalsort();
};

Graph::Graph(int V)
{
    this->V=V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

void Graph::topologicalsortUtil(int v,bool visited[], stack<int> &s)
{
    visited[v]=true;

    list<int>::iterator i;
    for(i=adj[v].begin(); i!=adj[v].end(); i++){
        if(visited[*i] !=true){
            topologicalsortUtil(*i,visited,s);
        }
    }
     s.push(v);
}

void Graph::topologicalsort()
{
    stack<int> s;

    bool *visited = new bool[V];
    for(int i=0;i<V;i++){
        visited[i]=false;
    }

    for(int i=0;i<V;i++){
        if(visited[i]==false){
            topologicalsortUtil(i,visited,s);
        }
    }

    while(s.empty()==false){
        cout<<s.top()<<" ";
        s.pop();
    }
}

int main()
{
    Graph g(6);
    g.addEdge(5,2);
    g.addEdge(5,0);
    g.addEdge(4,0);
    g.addEdge(4,1);
    g.addEdge(2,3);
    g.addEdge(3,1);

    g.topologicalsort();
    return 0;
}