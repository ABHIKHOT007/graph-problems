#include<bits/stdc++.h>
using namespace std;
#define N 4

class Graph
{
    int V;
    list<int> *adj;
public:
    Graph(int V)
    {
        this->V=V;
        adj=new list<int>[V];
    }
    void addEdge(int s, int d);
    int BFS(int s, int d);
};

void Graph::addEdge(int s, int d)
{
    adj[s].push_back(d);
    adj[d].push_back(s);
}

int Graph::BFS(int s, int d)
{
    if(s==d){
        return 0;
    }

    int *level=new int[V];
    for(int i=0;i<V;i++){
        level[i]=-1;
    }

    list<int> queue;
    queue.push_back(s);

    list<int>::iterator i;

    while(!queue.empty()){
        s=queue.front();
        queue.pop_front();

        for(i=adj[s].begin(); i!=adj[s].end(); i++){
            if(level[*i]<0 || level[*i] >level[s]+1){
                level[*i]=level[s]+1;
                queue.push_back(*i);
            }
        }
    }
    return level[d];
}

bool isright(int i, int j, int arr[][N])
{
    if((i<0 || i>=N) || (j<0 || j>=N) || arr[i][j]==0){
        return false;
    }
    return true;
}

int minimumpath(int arr[][N])
{
    int s,d;
    int V=N*N+2;
    Graph g(V);

    int k=1;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(arr[i][j]!=0){
                if(isright(i,j+1,arr)){
                    g.addEdge(k,k+1);
                }
                if(isright(i,j-1,arr)){
                    g.addEdge(k,k-1);
                }
                if(j<N-1 && isright(i-1,j,arr)){
                    g.addEdge(k,k+N);
                }
                if(i>0 && isright(i-1,j,arr)){
                    g.addEdge(k,k-N);
                }
            }
            if(arr[i][j]==2){
                d=k;
            }
            k++;
        }
    }
    return g.BFS(s,d);
}

int main()
{
    int arr[N][N]={{3,3,1,0},{3,0,3,3},{2,3,0,3},{0,3,3,3}};

    cout<<minimumpath(arr)<<endl;
    return 0;
}