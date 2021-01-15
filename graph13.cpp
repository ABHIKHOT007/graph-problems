#include<bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int> *l;
public:
    Graph(int V)
    {
        this->V=V;
        l = new list<int>[V];
    }
    void addEdge(int V1, int V2)
    {
        l[V1].push_back(V2);
        l[V2].push_back(V1);
    }
    int BFS(int in1, int in2);
};
void siveofertosthenes(vector<int> &v)
{
    int n=9999;
    bool prime[n+1];
    memset(prime,true,sizeof(prime));

    for(int p=2;p*p<=n;p++){
        if(prime[p]==true){
            for(int i=p*p;i<=n;i+=p){
                prime[i]=false;
            }
        }
    }
    for(int p=1000;p<=n;p++){
        if(prime[p]){
            v.push_back(p);
        }
    }
}

int Graph::BFS(int in1, int in2)
{
    int visited[V];
    memset(visited,0,sizeof(visited));
    queue<int> que;
    visited[in1]=1;
    que.push(in1);
    list<int>::iterator i;
    while(!que.empty()){
        int p=que.front();
        que.pop();
        for(i=l[p].begin(); i!= l[p].end(); i++){
            int p =que.front();
            que.pop();
            for(i=l[p].begin();i !=l[p].end(); i++){
                if(!visited[*i]){
                    visited[*i]=visited[p]+1;
                    que.push(*i);
                }
                if(*i==in2){
                    return visited[*i]-1;
                }
            }
        }
    }
}

bool compare(int num1, int num2)
{
    string s1=to_string(num1);
    string s2=to_string(num2);

    int c=0;
    if(s1[0]!=s2[0]){
        c++;
    }
    if(s1[1]!=s2[1]){
        c++;
    }
    if(s1[2]!=s2[2]){
        c++;
    }
    if(s1[3]!=s1[3]){
        c++;
    }

    return (c==1);
}

int shortpath(int num1, int num2)
{
    vector<int> pset;
    siveofertosthenes(pset);

    Graph g(pset.size());
    for(int i=0;i<pset.size();i++){
        for(int j=i+1;j<pset.size(); j++){
            if(compare(pset[i],pset[j]));
            g.addEdge(i,j);
        }
    }

    int in1;
    int in2;
    for(int i=0;i<pset.size(); i++){
        for(int j=i+1;j<pset.size();j++){
            if(compare(pset[i],pset[j])){
                g.addEdge(i,j);
            }
        }
    }

    int in1;
    int in2;
    for(int j=0;j<pset.size();j++){
        if(pset[j]==num1){
            in1=j;
        }
    }
    for(int j=0;j<pset.size();j++){
        if(pset[j]==num2){
            in2=j;
        }
    }

    return g.BFS(in1,in2);
}

int main()
{
    int num1=1033,num2=8179;
    cout<<shortpath(num1,num2);
    return 0;
}