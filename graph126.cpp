#include <bits/stdc++.h>
using namespace std;
#define CHARS 26

class Graph
{
	int V;
	list<int> *adj;
	int *in;

public:
	Graph(int V);
	~Graph()
	{
		delete[] adj;
		delete[] in;
	}

	void addEdge(int v, int w)
	{
		adj[v].push_back(w);
		(in[w]++);
	}

	bool DFSUtil(int v, bool visited[]);
	bool isEuleriancycle();
	bool isconnected();
	Graph getTranspose();
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
	in = new int[V];
	for (int i = 0; i < V; i++)
	{
		in[i] = 0;
	}
}

bool Graph::isEuleriancycle()
{
	if (isconnected() == false)
	{
		return false;
	}
	for (int i = 0; i < V; i++)
	{
		if (adj[i].size() != in[i])
		{
			return false;
		}
	}
	return true;
}

bool Graph::DFSUtil(int v, bool visited[])
{
	visited[v] = true;

	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); i++)
	{
		if (!visited[*i])
		{
			DFSUtil(*i, visited);
		}
	}
}

Graph Graph::getTranspose()
{
	Graph g(V);
	for (int v = 0; v < V; v++)
	{
		list<int>::iterator i;
		for (i = adj[v].begin(); i != adj[v].end(); i++)
		{
			g.adj[*i].push_back(v);
			(g.in[v]++);
		}
	}
	return g;
}

bool Graph::isconnected()
{
	bool visited[V];
	for (int i = 0; i < V; i++)
	{
		visited[i] = false;
	}

	int n;
	for (n = 0; n < V; n++)
	{
		if (adj[n].size() > 0)
		{
			break;
		}
	}
	DFSUtil(n, visited);
	Graph gr = getTranspose();

	for (int i = 0; i < V; i++)
	{
		visited[i] = false;
	}

	gr.DFSUtil(n, visited);

	for (int i = 0; i < V; i++)
	{
		if (adj[i].size() > 0 && visited[i] == false)
		{
			return false;
		}
	}
	return true;
}

bool canbechained(string arr[], int n)
{
	Graph g(CHARS);

	for (int i = 0; i < n; i++)
	{
		string s = arr[i];
		g.addEdge(s[0] - 'a', s[s.length() - 1] - 'a');
	}

	return g.isEuleriancycle();
}

int main()
{
	string arr[] = {"for", "geek", "rig", "kaf"};
	int n = sizeof(arr) / sizeof(arr[0]);
	canbechained(arr, n) ? cout << "YES" << endl : cout << "NO" << endl;
}