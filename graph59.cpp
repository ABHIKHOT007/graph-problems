#include<bits/stdc++.h>
using namespace std;

bool twocolorUtil(vector<int>g[], int s, int N, int color[])
{
    color[s]=1;
    queue<int> q;
    q.push(s);

    while(!q.empty()){
        int u=q.front();
        q.pop();

        for(int v=0;v<g[u].size();v++){
            if(color[g[u][v]]==-1){
                color[g[u][v]]=1-color[u];
                q.push(g[u][v]);
            }
            else if(color[g[u][v]]==color[u]){
                return false;
            }
        }
    }
    return true;
}

bool twocolor(vector<int>g[], int N)
{
    int color[N];
    for(int i=1;i<=N;i++){
        color[i]=-1;
    }

    for(int i=1;i<=N;i++){
        if(color[i]==-1){
            if(twocolorUtil(g,i,N,color)==false){
                return false;
            }
        }
        return true;
    }
}

bool isodd(int info[][3], int n, int m)
{
    vector<int> g[2*n];

    int pesduo=n+1;
    int pesduo_count=0;
    for(int i=0;i<m;i++){
        if(info[i][2]%2==1){
            int u=info[i][0];
            int v=info[i][1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        else{
            int u=info[i][0];
            int v=info[i][1];

            g[u].push_back(pesduo);
            g[pesduo].push_back(u);
            g[v].push_back(pesduo);
            g[pesduo].push_back(v);

            pesduo_count++;
            pesduo++;
        }
    }
    return twocolor(g,n+pesduo_count);
}

int main()
{
    int n=4,m=3;
    int info[4][3]={{1,2,12},{2,3,1},{4,3,1},{4,1,20}};
    isodd(info,n,m)?cout<<"YES":cout<<"NO";
    return 0;
}