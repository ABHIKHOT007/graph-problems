#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> ipair;

class Graph
{
    int V;
    list<pair<int,int>> *adj;
    bool pathmorethanklengthUtil(int s, int k,vector<bool> &path);
public:
    Graph(int V);
    void addEdge(int u, int v, int w);
    bool pathmorethanklength(int s, int k);
};

Graph::Graph(int V)
{
    this->V=V;
    adj = new list<pair<int,int>>[V];
}

void Graph::addEdge(int v, int u, int w)
{
    adj[u].push_back(make_pair(v,w));
    adj[v].push_back(make_pair(u,w));
}

bool Graph::pathmorethanklength(int s, int k)
{
    vector<bool> path(V,false);

    path[s]=true;

    return pathmorethanklengthUtil(s,k,path);
}

bool Graph::pathmorethanklengthUtil(int s, int k, vector<bool> &path)
{
    if(k<=0){
        return true;
    }

    list<ipair>::iterator i;
    for(i=adj[s].begin(); i!=adj[s].end(); i++){
        int v=(*i).first;
        int w=(*i).second;

        if(path[v]==true){
            continue;
        }
        if(w>=k){
            return true;
        }
        path[v]=true;
        if(pathmorethanklengthUtil(v,k-w,path)){
            return true;
        }
        path[v]=false;
    }
    return false;
}

int main()
{
    int V=9;
    Graph g(V);

    g.addEdge(0,1,4);
    g.addEdge(0,7,8);
    g.addEdge(1,2,8);
    g.addEdge(1,7,11);
    g.addEdge(2,3,7);
    g.addEdge(2,8,2);
    g.addEdge(2,5,4);
    g.addEdge(3,4,9);
    g.addEdge(3,5,11);
    g.addEdge(4,5,10);
    g.addEdge(5,6,2);
    g.addEdge(6,8,6);
    g.addEdge(7,8,7);

    int s=0;
    int k=62;
    g.pathmorethanklength(s,k)?cout<<"YES"<<endl:cout<<"NO"<<endl;

    k=40;
    g.pathmorethanklength(s,k)?cout<<"YES"<<endl:cout<<"NO"<<endl;
    return 0;


}