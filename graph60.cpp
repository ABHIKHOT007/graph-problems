#include<bits/stdc++.h>
using namespace std;

bool iscycle(int v, vector<int> adj[], vector<bool> &visited, vector<bool> &recur)
{
    visited[v]=true;
    recur[v]=true;

    for(int i=0;i<adj[v].size();i++){
        if(visited[adj[v][i]]==false){
            if(iscycle(adj[v][i],adj,visited,recur)){
                return true;
            }
        }
        else if(visited[adj[v][i]]==true && recur[adj[v][i]]==true){
            return true;
        }
    }
    recur[v]=false;
    return false;
}

bool cycle(int arr[], int n)
{
    vector<int> adj[n];
    for(int i=0;i<n;i++){
        if(i!=(i+arr[i]+n)%n){
            adj[i].push_back((i+arr[i]+n)%n);
        }
    }
    vector<bool> visited(n,false);
    vector<bool> recur(n,false);
    for(int i=0;i<n;i++){
        if(visited[i]==false){
            if(iscycle(i,adj,visited,recur)){
                return true;
            }
        }
    }
    return true;
}

int main()
{
    int arr[]={2,-1,1,2,2};
    int n=sizeof(arr)/sizeof(arr[0]);
    cycle(arr,n)?cout<<"YES":cout<<"NO";
    return 0;
}