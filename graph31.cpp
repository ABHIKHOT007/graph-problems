#include<bits/stdc++.h>
using namespace std;

int BFSwithdistance(vector<int> g[], bool mark[], int u, vector<int>& dis)
{
    int lastmarked;
    queue<int> q;
    q.push(u);
    dis[u]=0;
    while(!q.empty()){
        u=q.front();
        q.pop();
        if(mark[u]){
            lastmarked=u;
        }

        for(int i=0;i<g[u].size();i++){
            int v=g[u][i];
            if(dis[v]==-1){
                dis[v]=dis[u]+1;
                q.push(v);
            }
        }
    }
    return lastmarked;
}

int nodesatkdistance(int edges[][2], int V, int marked[], int N, int K)
{
    V=V+1;
    vector<int> g[V];
    int u,v;
    for(int i=0;i<(V-1);i++){
        u=edges[i][0];
        v=edges[i][1];

        g[u].push_back(v);
        g[v].push_back(u);
    }

    bool mark[V]={false};
    for(int i=0;i<N;i++){
        mark[marked[i]]=true;
    }
    vector<int> temp(V,-1),dl(V,-1),dr(V,-1);
    u=BFSwithdistance(g,mark,0,temp);
    v=BFSwithdistance(g,mark,u,dl);

    BFSwithdistance(g,mark,v,dr);
    int res=0;
    for(int i=0;i<V;i++){
        if(dl[i]<=K && dr[i] <= K)
        {
            res++;
        }
    }
    return res;
}

int main()
{
    int edges[][2]={{1,0},{0,3},{0,8},{3,6},{3,7},{4,5},{5,9}};

    int V=sizeof(edges)/sizeof(edges[0]);

    int marked[]={1,2,4};

    int N=sizeof(marked)/sizeof(marked[0]);

    int K=3;

    cout<<nodesatkdistance(edges,V,marked,N,K);

    return 0;
}