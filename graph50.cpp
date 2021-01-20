#include<bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int> *adj;
    bool iscyclicUtil(int v, bool visited[], int parent);
public:
    Graph(int V);
    void addEdge(int v, int w);
    bool iscyclic();
};

Graph::Graph(int V)
{
    this->V=V;
    adj=new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}

bool Graph::iscyclicUtil(int v, bool visited[], int parent)
{
    visited[v]=true;

    list<int>::iterator i;
    for(i=adj[v].begin(); i!=adj[v].end(); i++){
        if(!visited[*i]){
            if(iscyclicUtil(*i,visited,v)){
                return true;
            }
        }
        else if(*i!=parent){
            return true;
        }
    }
    return false;
}

bool Graph::iscyclic()
{
    bool *visited=new bool[V];
    for(int i=0;i<V;i++){
        visited[i]=false;
    }

    for(int u=0;u<V;u++){
        if(!visited[u]){
            if(iscyclicUtil(u,visited,-1)){
                return true;
            }
        }
    }
    return false;
}

int main()
{
    Graph g(5);
    g.addEdge(1,0);
    g.addEdge(0,2);
    g.addEdge(2,1);
    g.addEdge(0,3);
    g.addEdge(3,4);
    g.iscyclic()?cout<<"YES"<<endl:cout<<"NO"<<endl;
    return 0;
}