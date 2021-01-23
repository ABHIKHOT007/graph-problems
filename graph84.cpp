#include<bits/stdc++.h>
using namespace std;
//hamiltoioan cycle.
#define V 5
void printsolution(int path[]);

bool isvalid(int v, bool graph[V][V], int path[], int pos)
{
    if(graph[path[pos-1]][v]==0){
        return false;
    }
    for(int i=0;i<pos;i++){
        if(path[i]==v){
            return false;
        }
    }
    return true;
}

bool hamcycleUtil(bool graph[V][V], int path[], int pos)
{
    if(pos==V){
        if(graph[path[pos-1]][path[0]]==1){
            return true;
        }
        else{
            return false;
        }
    }

    for(int v=1;v<V;v++){
        if(isvalid(v,graph,path,pos)){
            path[pos]=v;
            if(hamcycleUtil(graph,path,pos+1)==true){
                return true;

                path[pos]=-1;
            }
        }
    }
    return false;
}

bool hamcycle(bool graph[V][V])
{
    int *path=new int[V];
    for(int i=0;i<V;i++){
        path[i]=-1;
    }

    path[0]=0;
    if(hamcycleUtil(graph,path,1)==false){
        return false;
    }
    else{
        printsolution(path);
        return true;
    }
}

void printsolution(int path[])
{
    cout<<"following is the hamiltonioan path"<<endl;
    for(int i=0;i<V;i++){
        cout<<path[i]<<" ";
    }
    cout<<path[0]<<" ";
    cout<<endl;
}

int main()
{
     bool graph1[V][V] = {{0, 1, 0, 1, 0},{1, 0, 1, 1, 1},{0, 1, 0, 0, 1},{1, 1, 0, 0, 1},{0, 1, 1, 1, 0}};  
    hamcycle(graph1);
    return 0;
}