#include<bits/stdc++.h>
using namespace std;

void DFS(vector<pair<int,int>> graph[], int s, int prev_len, int *max_len, vector<bool> &visited)
{
    visited[s]=1;
    int curr_len=0;
    pair<int,int> p;

    for(int i=0;i<graph[s].size();i++){
        p=graph[s][i];
        if(!visited[p.first]){
            curr_len=prev_len+p.second;
            DFS(graph,p.first,curr_len,max_len,visited);
        }
        if((*max_len)<curr_len){
            *max_len=curr_len;
        }
    }
}

int longestpath(vector<pair<int,int>> graph[], int n)
{
    int max_len=INT_MIN;

    for(int i=1;i<=n;i++){
        vector<bool> visited(n+1,false);
        DFS(graph,i,0,&max_len,visited);
    }
    return max_len;
}

int main()
{
    int n=6;
    vector<pair<int,int>> graph[n+1];

    graph[1].push_back(make_pair(2,3));
    graph[2].push_back(make_pair(1,3));

    graph[2].push_back(make_pair(3,4));
    graph[3].push_back(make_pair(2,4));

    graph[2].push_back(make_pair(6,2));
    graph[6].push_back(make_pair(2,2));

    graph[4].push_back(make_pair(6,6));
    graph[6].push_back(make_pair(4,6));

    graph[5].push_back(make_pair(6,5));
    graph[6].push_back(make_pair(5,5));

    cout<<longestpath(graph,n);
    return 0;

}