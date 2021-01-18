#include<bits/stdc++.h>
using namespace std;

const int MAX=10001;
bool visit[MAX]={0};

int intime[MAX];
int outtime[MAX];

int timer=0;

void DFS(vector<int> graph[], int v)
{
    visit[v]=true;
    ++timer;
    intime[v]=timer;
    vector<int>::iterator it = graph[v].begin();
    while(it!=graph[v].end()){
        if(visit[*it]==false){
            DFS(graph,*it);
        }
        it++;
    }

    ++timer;
    outtime[v]=timer;
}

bool isonsamepath(int u, int v)
{
    return ((intime[u]<intime[v] && outtime[u]>outtime[v]) || (intime[v]<intime[u] && outtime[v]>outtime[u]));
}

int main()
{
    int n=9;
    vector<int> graph[n+1];
    graph[1].push_back(2);
    graph[1].push_back(3);
    graph[3].push_back(6);
    graph[2].push_back(4);
    graph[2].push_back(5);
    graph[5].push_back(7);
    graph[5].push_back(8);
    graph[5].push_back(9);
   
   DFS(graph,1);

   isonsamepath(1,5)?cout<<"Yes"<<endl:cout<<"No"<<endl;
   isonsamepath(2,9)?cout<<"Yes"<<endl:cout<<"No"<<endl;
   isonsamepath(2,6)?cout<<"Yes"<<endl:cout<<"No"<<endl;
   return 0;
}

