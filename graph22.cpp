#include<bits/stdc++.h>
using namespace std;

int fillheight(int p[], int node, int visited[], int height[])
{
    if(p[node]==-1){
        visited[node]=-1;
        return 0;
    }

    if(visited[node]){
        return height[node];
    }

    visited[node]=1;

    height[node]=1+fillheight(p,p[node],visited,height);

    return height[node];
}

int findheight(int parent[], int n)
{
    int ma=0;

    int visited[n];

    int height[n];

    memset(visited,0,sizeof(visited));
    memset(height,0,sizeof(height));

    for(int i=0;i<n;i++){
        if(!visited[i]){
            height[i]=fillheight(parent,i,visited,height);

            ma=max(ma,height[i]);
        }
    }
    return ma;
}

int main()
{
    int parent[]={-1,0,0,0,3,1,1,2};
    int n=sizeof(parent)/sizeof(parent[0]);

    cout<<"height of the n-array tree"<<findheight(parent,n);

    return 0;
}