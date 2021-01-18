#include<bits/stdc++.h>
using namespace std;

void DFS(int u, int parent, int totalsum, vector<int> edge[], int subtree[], int & res)
{
	int sum=subtree[u];
	for(int i=0;i<edge[u].size();i++){
		int v=edge[u][i];
		if(v!=parent){
			DFS(v,u,totalsum,edge,subtree,res);
			sum+=subtree[v];
		}
	}
	subtree[u]=sum;
	
	if(u!=0 && abs(totalsum-2*sum)<res){
		res=abs(totalsum-2*sum);
	}
}

int getminsubtreediff(int vertex[], int edges[][2], int N)
{
	int totalsum=0;
	int subtree[N];

	for(int i=0;i<N;i++){
		subtree[i]=vertex[i];
		totalsum+=vertex[i];
	}

	vector<int> edge[N];

	for(int i=0;i<N-1;i++){
		edge[edges[i][0]].push_back(edges[i][1]);
		edge[edges[i][1]].push_back(edges[i][0]);
	}

	int res=INT_MAX;

	DFS(0,-1,totalsum,edge,subtree,res);
}

int main()
{
	int vertex[]={4,2,16,3,3,5,2};

	int edges[][2]={{0,1},{0,2},{0,3},{0,3},{2,4},{2,5},{3,6}};

	int N=sizeof(vertex)/sizeof(vertex[0]);

	cout<<getminsubtreediff(vertex,edges, N);
	return 0;
}