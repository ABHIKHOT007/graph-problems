#include<bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int> *adj;
    void topologicalsortUtil(int v, bool visited[], stack<int> &Stack);
public:
    Graph(int V);
    void addEdge(int v, int w);
    void topologicalsort();
};

Graph::Graph(int V)
{
    this->V=V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

void Graph::topologicalsortUtil(int v, bool visited[], stack<int> &Stack)
{
    visited[v]=true;
    list<int>::iterator i;
    for(i=adj[v].begin(); i!=adj[v].end(); i++){
        if(!visited[*i]){
            topologicalsortUtil(*i,visited,Stack);
        }
    }
    Stack.push(v);
}

void Graph::topologicalsort()
{
    stack<int> Stack;

    bool *visited = new bool[V];
    for(int i=0;i<V;i++){
        visited[i]=false;
    }

    for(int i=0;i<V;i++){
        if(visited[i]==false){
            topologicalsortUtil(i,visited,Stack);
        }
    }

    while(Stack.empty()){
        cout<<(char)('a'+Stack.top())<<" ";
        Stack.pop();
    }
}

int min(int x, int y)
{
    return (x<y)?x:y;
}

void printorder(string words[], int n, int alpha)
{
    Graph g(alpha);

    for(int i=0;i<n-1;i++){
        string word1=words[i];
        string word2=words[i+1];

        for(int j=0;j<min(word1.length(),word2.length());j++){
            if(word1[j]!=word2[j]){
                g.addEdge(word1[j]-'a',word2[j]-'a');
                break;
            }
        }
    }
    g.topologicalsort();
}

int main()
{
    string words[]={"caa","aaa","aab"};
    printorder(words,3,3);
    return 0;
}
