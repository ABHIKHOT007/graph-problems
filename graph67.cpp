#include<bits/stdc++.h>
using namespace std;

//khan's algorithm

class Graph
{
    int V;
    list<int> *adj;
public:
    Graph(int V);
    void addEdge(int u, int v);
    void topologicalsort();
};

Graph::Graph(int V)
{
    this->V=V;
    adj=new list<int>[V];
}

void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v);
}

void Graph::topologicalsort()
{
    vector<int> IN_DEGREE(V,0);

    for(int u=0;u<V;u++){
        list<int>::iterator itr;
        for(itr=adj[u].begin(); itr!=adj[u].end(); itr++){
            IN_DEGREE[*itr]++;
        }
    }

    queue<int> q;
    for(int i=0;i<V;i++){
        if(IN_DEGREE[i]==0){
            q.push(i);
        }
    }

    int count=0;
    vector<int> top_order;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        top_order.push_back(u);

        list<int>::iterator itr;
        for(itr=adj[u].begin();itr!=adj[u].end();itr++){
            if(--IN_DEGREE[*itr]==0){
                q.push(*itr);
            }
        }
        count++;
    }
    if(count!=V){
        cout<<"there exits a cycle in the graph"<<endl;
        return;
    }

    for(int i=0;i<top_order.size();i++){
        cout<<top_order[i]<<" ";
    }
    cout<<endl;
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

    cout<<"following is the a topological sort"<<endl;
    g.topologicalsort();
    return 0;
}