#include<bits/stdc++.h>
using namespace std;

//clone directed acyclic graph

class Node
{
public:
    int key;
    vector<Node*> adj;
    Node(int key){
        this->key=key;
    }
};

void printGraph(Node *startNode, vector<bool> &visited)
{
    if(!startNode->adj.empty()){
        for(auto i:startNode->adj){
            if(!visited[startNode->key]){
                cout<<"edge"<<startNode<<"-"<<i<<startNode->key<<endl;

                if(!visited[i->key]){
                    printGraph(i,visited);
                    visited[i->key]=true;
                }
            }
        }
    }
}

Node *cloneGraph(Node *oldsource, Node *newsource, vector<bool> &visited)
{
    Node *clone = NULL;

    if(!visited[oldsource->key] && !oldsource->adj.empty()){
        for(auto old :oldsource->adj){
            if(clone==NULL || (clone->key != old->key)){
                clone = new Node(old->key);
            }
            newsource->adj.push_back(clone);
            cloneGraph(old,clone,visited);

            visited[old->key]=true;
        }
    }
    return newsource;
}

int main()
{
    Node *n0=new Node(0);
    Node *n1=new Node(1);
    Node *n2=new Node(2);
    Node *n3=new Node(3);
    Node *n4=new Node(4);

    n0->adj.push_back(n1);
    n1->adj.push_back(n2);
    n2->adj.push_back(n3);
    n3->adj.push_back(n4);

    vector<bool> visited(5,false);
    cout<<"Graph before cloning"<<endl;
    visited={false,false,false,false,false};

    Node *cloneGraphHead=cloneGraph(n0,new Node(n0->key),visited);
    visited={false,false,false,false,false};
    cout<<"Graph after cloning"<<endl;
    printGraph(cloneGraphHead,visited);
    return 0;
}