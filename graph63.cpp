#include<bits/stdc++.h>
using namespace std;
//itearative deeping depth first search.
class Graph
{
    int V;
    list<int> *adj;
    bool DLS(int v, int targe, int limit);
public:
    Graph(int V);
    void addEdge(int v, int w);
    bool IDDFS(int v, int target, int max_depth);
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

bool Graph::DLS(int s, int target, int limit)
{
    if(s=target){
        return true;
    }
    if(limit<=0){
        return false;
    }

    for(auto i=adj[s].begin(); i!=adj[s].end(); i++){
        if(DLS(*i,target,limit-1)==true){
            return true;
        }
    }
    return false;
}

bool Graph::IDDFS(int s, int target, int max_depth)
{
    for(int i=0;i<=max_depth;i++){
        if(DLS(s,target,i)==true){
            return true;
        }
    }
    return false;
}

int main()
{
    Graph g(7);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(1,4);
    g.addEdge(2,5);
    g.addEdge(2,6);

    int target=6,max_depth=3,s=0;
    g.IDDFS(s,target,max_depth)?cout<<"YES":cout<<"NO";
    return 0;
}

