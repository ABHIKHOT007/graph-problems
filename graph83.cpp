#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
    int color=1;
    set<int> edges;
};

int canpaint(vector<node> &nodes, int n, int m)
{
    vector<int> visited(n+1,0);
    int maxcolors=1;

    for(int sv=1;sv<=n;sv++){
        if(visited[sv]){
            continue;
        }
        visited[sv]=1;
        queue<int> q;
        q.push(sv);

        while(!q.empty()){
            int top=q.front();
            q.pop();
            for(auto it =nodes[top].edges.begin(); it!=nodes[top].edges.end();it++){
                if(nodes[top].color==nodes[*it].color){
                    nodes[*it].color+=1;
                }
                maxcolors=max(maxcolors,max(nodes[top].color,nodes[*it].color));

                if(maxcolors>m){
                    return 0;
                }

                if(!visited[*it]){
                    visited[*it]=1;
                    q.push(*it);
                }
            }
        }
    }
    return 1;
}

int main()
{
    int n=4;
    bool graph[n][n]={{0,1,1,1},{1,0,1,0},{1,1,0,1},{1,0,1,0}};
    int m=3;
    vector<node> nodes(n+1);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(graph[i][j]){
                nodes[i].edges.insert(i);
                nodes[j].edges.insert(j);
            }
        }
    }
    cout<<canpaint(nodes,n,m);
    return 0;
}