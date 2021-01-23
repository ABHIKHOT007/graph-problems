#include<bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int> *adj;
    vector<int> indegree;
    vector<int> topologicalsort();
public:
    Graph(int V);
    void addEdge(int v, int w);
    void maximumedge();
};

Graph::Graph(int V)
{
    this->V=V;
    adj = new list<int>[V];
    for(int i=0;i<V;i++){
        indegree.push_back(0);
    }
}
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    indegree[w]++;
}
vector<int>Graph::topologicalsort()
{
    vector<int> topological;
    queue<int> q;
    for(int i=0;i<V;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    while(q.empty()){
        int t=q.front();
        q.pop();

        topological.push_back(t);
        list<int>::iterator j;
        for(j=adj[t].begin(); j!=adj[t].end(); j++){
            indegree[*j]--;
            if(indegree[*j]==0){
                q.push(*j);
            }
        }
    }
    return topological;
}
void Graph::maximumedge()
{
    bool *visited = new bool[V];
    vector<int> v = topologicalsort();
    for(int i=0;i<v.size();i++){
        int t=v[i];
        list<int>::iterator j;
        for(j=adj[t].begin(); j!=adj[t].end(); j++){
            visited[*j]=true;
        }
        for(int j=i+1;j<v.size();j++){
            if(!visited[v[j]]){
                cout<<t<<" "<<v[i]<<" "; 
            }
            visited[v[j]]=false;
        }
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

    g.maximumedge();
    return 0;
}