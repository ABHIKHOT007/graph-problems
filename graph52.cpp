#include<bits/stdc++.h>
using namespace std;
#define V 4
//biphertite graph detection.
bool containodd(int G[][V], int s)
{
    bool color[V];
    for(int i=0;i<V;i++){
        color[i]=false;
    }

    queue<int> q;
    q.push(s);

    while(!q.empty()){
        int u=q.front();
        q.pop();
        if(G[u][u]==1){
            return true;
        }
        for(int v=0;v<V;v++){
            if(G[u][v]&&color[v]==false){
                color[v]=1-color[u];
                q.push(v);
            }
            else if(G[u][v]&&color[v]==color[u]){
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int G[][V]={{0,1,0,1},{1,0,1,0},{0,1,0,1},{1,0,1,0}};
    containodd(G,0)?cout<<"Yes":cout<<"No";
    return 0;
}