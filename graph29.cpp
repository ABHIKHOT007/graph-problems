#include<bits/stdc++.h>
using namespace std;

void printpath(vector<int>& path)
{
    for(int i=0; i<path.size(); i++){
        cout<<path[i]<<" ";
    }
    cout<<endl;
}

int isvisited(int x, vector<int>& path)
{
    for(int i=0; i<path.size(); i++){
        if(path[i]==x){
            return 0;
        }
    }
    return 1;
}

void findpaths(vector<vector<int>>&g, int src, int dest, int v)
{
    queue<vector<int>> q;
    vector<int> path;
    q.push(path);
    while(!q.empty()){
        path=q.front();
        q.pop();
        int last=path[path.size()-1];
        if(last==dest){
            printpath(path);
        }
        for(int i=0; i<g[last].size(); i++){
            if(isvisited(g[last][i],path)){
                vector<int> newpath(path);
                newpath.push_back(g[last][i]);
                q.push(newpath);
            }
        }
    }
}

int main()
{
    vector<vector<int>> g;
    int v=4;
    g.resize(4);
    g[0].push_back(3);
    g[0].push_back(1);
    g[0].push_back(2);
    g[1].push_back(3);
    g[2].push_back(0);
    g[2].push_back(1);

    int src=2,dest=3;
    cout<<"path from source"<<src<<"to destination"<<dest<<"are"<<endl;
    findpaths(g,src,dest,v);
    return 0;
}