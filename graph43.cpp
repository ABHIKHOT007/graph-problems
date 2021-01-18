#include<bits/stdc++.h>
using namespace std;

const int N=10000;
vector<int> graph[N];
bool visited[N];

void DFS(int node, int arr[], int mini)
{
    mini=min(mini,arr[node]);
    
    visited[node]=true;

    for(int i:graph[node]){
        if(!visited[i]){
            DFS(i,arr,mini);
        }
    }
}

void addEdge(int u, int v)
{
    graph[u-1].push_back(v-1);
    graph[v-1].push_back(u-1);
}

int minimumsun(int arr[], int n)
{
    int sum=0;

    for(int i=0;i<n;i++){
        if(!visited[i]){
            int mini=arr[i];
            DFS(i,arr,mini);
            sum+=mini;
        }
    }
    return sum;
}

int main()
{
    int arr[]={1, 6, 2, 7, 3, 8, 4, 9, 5, 10}; 
    int n=sizeof(arr)/sizeof(arr[0]);

    addEdge(1,2);
    addEdge(3,4);
    addEdge(5,6);
    addEdge(7,8);
    addEdge(9,10);

    cout<<minimumsun(arr,n)<<endl;

    return 0;
}