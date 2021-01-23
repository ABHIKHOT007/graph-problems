#include<bits/stdc++.h>
using namespace std;

/*class Graph
{
    int V;
    list<int> *adj;
    vector<int> indegree;
    void topologicalsortUtil(vector<int> &res, bool visited[]);
public:
    Graph(int V);
    void addEdge(int v, int w);
    void topologicalsort();
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

void Graph::topologicalsortUtil(vector<int> &res, bool visited[])
{
    bool flag=false;
    for(int i=0;i<V;i++){
        if(indegree[i]==0 && !visited[i]){
            list<int>::iterator j;
            for(j=adj[i].begin(); j!=adj[i].end(); i++){
                indegree[*j]--;
                res.push_back(i);
                visited[i]=true;
                topologicalsortUtil(res,visited);

                visited[i]=false;
                res.erase(res.end()-1);
                for(j=adj[i].begin(); j!=adj[i].end();j++){
                    indegree[*j]++;
                }
                flag=true;
            }
        }
    }
     if(!flag){
           for(int i=0;i<res.size();i++){
               cout<<res[i]<<" ";
           }
           cout<<endl;
        }
}

void Graph::topologicalsort()
{
    bool *visited = new bool[V];
    for(int i=0;i<V;i++){
        visited[i]=false;
    }
    vector<int> res;
    topologicalsortUtil(res,visited);
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

    cout<<"All possible topological sort of the given graph are:"<<endl;
    g.topologicalsort();
    return 0;
}*/
