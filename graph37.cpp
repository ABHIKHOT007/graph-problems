#include<bits/stdc++.h>
using namespace std;

int DFS(vector<int> g[], int& currmax, int u, int v)
{
    int max1=0,max2=0,total=0;

    for(int i=0; i<g[u].size(); i++){
        if(g[u][i]==v){
            continue;
        }
        total=max(total,DFS(g,currmax,g[u][i],u));

        if(currmax>max1){
            max2=max1;
            max1=currmax;
        }
        else{
            max2=max(max2,currmax);
        }
    }
    total=max(total,max1+max2);

    currmax=max1+1;
    return total;
}

int maxproductofpaths(vector<int> g[], int N)
{
    int res=INT_MIN;
    int path1,path2;

    for(int i=1;i<N+2;i++){
        for(int j=0;j<g[i].size();j++){
            int currmax=0;
            path1=DFS(g,currmax,i,g[i][j]);

            currmax=0;
            path2=DFS(g,currmax,i,g[i][j]);

            res=max(res,path1*path2);
        }
    }
    return res;
}

void addEdge(vector<int> g[], int u, int v)
{
    g[u].push_back(v);
    g[v].push_back(u);
}

int main()
{
    int edges[][2]={{1,8},{2,6},{3,1},{5,3},{7,8},{8,4},{8,6}};

    int N=sizeof(edges)/sizeof(edges[0]);

    vector<int> g[N+2];

    for(int i=0;i<N;i++){
        addEdge(g,edges[i][0], edges[i][1]);
    }

    cout<<maxproductofpaths(g,N)<<endl;
    return 0;
}