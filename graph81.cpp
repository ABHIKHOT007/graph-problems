#include<bits/stdc++.h>
using namespace std;
#define V 4

void printsolution(int color[]);

bool isvalid(bool graph[V][V], int color[])
{
    for(int i=0;i<V;i++){
        for(int j=i+1;j<V;j++){
            if(graph[i][j]==false && color[j]==color[i]){
                return false;
            }
        }
    }
    return true;
}

bool graphcoloring(bool graph[V][V], int m,int i,int color[V])
{
    if(i==V){
        if(isvalid(graph,color)){
            printsolution(color);
            return true;
        }
        return false;
    }

    for(int j=1;j<=m;j++){
        color[i]=j;

        if(graphcoloring(graph,m,i+1,color)){
            return true;

            color[i]=0;
        }
    }
    return false;
}

void printsolution(int color[])
{
    cout<<"following exists the graph color:"<<endl;
    for(int i=0;i<V;i++){
        cout<<" "<<color[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    bool graph[V][V]={{0,1,1,1},{1,0,1,0},{1,1,0,1},{1,0,1,0}};
    int m=3;
    int color[V];
    for(int i=0;i<V;i++){
        color[i]=0;
    }
    if(!graphcoloring(graph,m,0,color)){
        cout<<"solution doesn't exits"<<endl;
    }
    return 0;
}