#include<bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int> *adj;
    bool iscyclicUtil(int v, bool visited[], bool *rs);
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
}

bool Graph::iscyclicUtil(int v, bool visited[], bool *restack)
{
    if(visited[v]==false){
        visited[v]=true;
        restack[v]=true;

        list<int>::iterator i;
        for(i=adj[v].begin();i!=adj[v].end();i++){
            if(!visited[*i]&&iscyclicUtil(*i,visited,restack)){
                return true;
            }
            else if(restack[*i]){
                return true;
            }
        }
    }
    restack[v]=false;
    return false;
}

bool Graph::iscyclic()
{
    bool *visited=new bool[V];
    bool *restack=new bool[V];

    for(int i=0;i<V;i++){
        if(iscyclicUtil(i,visited,restack)){
            return true;
        }
    }
    return false;
}

int main()
{
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(2,0);
    g.addEdge(2,3);
    g.addEdge(3,3);

    g.iscyclic()?cout<<"YES"<<endl:cout<<"NO"<<endl;
    return 0;
}

