#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
vector<vector<pi>> graph;

void addEdge(int x, int y, int cost)
{
    graph[x].push_back(make_pair(cost,y));
    graph[y].push_back(make_pair(cost,x));
}

void bestfirstsearch(int source, int target, int n)
{
    vector<bool> visited(n,false);

    priority_queue<pi,vector<pi>, greater<pi> >pq;

    pq.push(make_pair(0,source));

    visited[0]=true;

    while(!pq.empty()){
        int x=pq.top().second;
        pq.pop();
        if(x==target){
            break;
        }
        for(int i=0;i<graph[x].size();i++){
            if(!visited[graph[x][i].second]){
                visited[graph[x][i].second]=true;
                pq.push(graph[x][i]);
            }
        }
    }
}

int main()
{
    int v=14;
    graph.resize(v);

    addEdge(0,1,3);
    addEdge(0,2,6);
    addEdge(0,3,5);
    addEdge(1,4,9);
    addEdge(1,5,8);
    addEdge(2,6,12);
    addEdge(2,7,14);
    addEdge(8,9,5);
    addEdge(8,11,1);
    addEdge(9,11,1);
    addEdge(9,12,10);
    addEdge(9,13,2);
    int source=0;
    int target=9;
     bestfirstsearch(source,target,v);
     return 0;
}