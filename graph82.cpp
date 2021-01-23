#include<bits/stdc++.h>
using namespace std;
#define V 4

void printsolution(int color[]);

bool isvalid(int v, bool graph[V][V], int color[], int c)
{
    for(int i=0;i<V;i++){
        if(graph[V][i]==false && c==color[i]){
            return false;
        }
    }
    return true;
}

bool graphcoloringUtil(bool graph[V][V], int m, int color[], int v)
{
    if(v==V){
        return true;
    }

    for(int c=1;c<=m;c++){
        if(isvalid(v,graph,color,c)){
            color[v]=c;

            if(graphcoloringUtil(graph,m,color,v+1)==true){
                return true;
            }

            color[v]=0;
        }
    }
    return false;
}

bool graphcoloring(bool graph[V][V], int m)
{
    int color[V];
    for(int i=0;i<V;i++){
        color[i]=0;
    }

    if(graphcoloringUtil(graph,m,color,0)==false){
        cout<<"solution does not exits"<<endl;
        return false;
    }
    printsolution(color);
}

void printsolution(int color[])
{
    cout<<"following are the assigned colors"<<endl;
    for(int i=0;i<V;i++){
        cout<<color[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    bool graph[V][V]={{0,1,1,1},{1,0,1,0},{1,1,0,1},{1,0,1,0}};
    int m=3;
    graphcoloring(graph,m);
    return 0;
}