#include<bits/stdc++.h>
using namespace std;

int  DFS(vector<pair<int,int>> g[], pair<int,int> disrev[], bool visit[], int u)
{
	visit[u]=true;
	int totalrev=0;

	for(int i=0;i<g[u].size();i++){
		int v=g[u][i].first;
		if(!visit[v]){
			disrev[v].first=disrev[u].first+1;
			disrev[v].second=disrev[u].second;

			if(g[u][i].second){
				disrev[v].second=disrev[u].second+1;
				totalrev++;
			}
			totalrev+=DFS(g,disrev,visit,v);
		}
	}
	return totalrev;
}

void printminedgerever(int edges[][2], int e, bool visit[])
{
	int V=e+1;
	vector<pair<int,int>> g[V];

	pair<int,int> disrev[V];

	bool visite[V];

	int u,v;

	for(int i=0;i<e;i++){
		u=edges[i][0];
		v=edges[i][1];
		g[u].push_back(make_pair(v,0));
		g[v].push_back(make_pair(u,1));
	}
	for(int i=0;i<V;i++){
		visit[i]=false;
		disrev[i].first=disrev[i].second=0;
	}
	int root=0;

	int totalrev=DFS(g,disrev,visit,root);

	int res=INT_MAX;

	for(int i=0;i<V;i++){
		int edgestorev=(totalrev-disrev[i].second)+(disrev[i].first-disrev[i].second);

		if(edgestorev<res){
			res=edgestorev;
			root=i;
		}
	}
	cout<<root<<" "<<res<<endl;
}

int main()
{
	int edges[][2]={{0,1},{2,1},{3,2},{3,4},{5,4},{5,6},{7,6}};

	int e=sizeof(edges)/sizeof(edges[0]);
	bool visit[]={false};
	printminedgerever(edges,e,visit);
	return 0;
}