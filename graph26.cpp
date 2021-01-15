#include<bits/stdc++.h>
#define V 4
using namespace std;

bool containodd(int G[][V], int s)
{
    int colorarr[V];
    for(int i=0;i<V;i++){
        colorarr[i]=-1;
    }

    colorarr[s]=1;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int u=q.front();
        q.pop();

        if(G[u][u]==1){
            return true;
        }
        for(int v=0;v<V;v++){
            if(G[u][v] && colorarr[v]==-1){
                colorarr[v]=1-colorarr[u];
                q.push(v);
            }
            else if(G[u][v] && colorarr[v]==colorarr[u]){
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int G[][V]={{0,1,0,1},{1,0,0,1},{0,1,1,1},{0,0,1,1}};

    containodd(G,0)?cout<<"Yes":cout<<"No";
    return 0;
}