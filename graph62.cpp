#include<bits/stdc++.h>
using namespace std;

int solve(int arr[], int n)
{
    int i,cnt=0,j;

    int parent[n+1];
    int vis[n+1];
    memset(parent,-1,sizeof(parent));
    memset(vis,0,sizeof(vis));

    for(int i=0;i<n;i++){
        j=i;

        if(parent[j]==-1){
            while(parent[j]==-1){
                parent[j]=i;
                j=(j+arr[i]+1)%n;
            }

            if(parent[i]==i){
                while(!vis[j]){
                    vis[j]=1;
                    cnt++;
                    j=(j+arr[j]+1)%n;
                }
            }
        }
    }
    return cnt;
}

int main()
{
    int arr[]={0,0,0,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<solve(arr,n);
    return 0;
}