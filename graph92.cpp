#include <bits/stdc++.h>
using namespace std;
//weakly connected component.
set<int> node;
vector<int> graph[10001];

void DFS(bool visit[], int s)
{
    visit[s] = true;
    node.insert(s);
    int len = graph[s].size();
    for (int i = 0; i < len; i++)
    {
        if (!visit[graph[s][i]])
        {
            DFS(visit, graph[s][i]);
        }
    }
}

void buildgraph(int x[], int y[], int len)
{
    for (int i = 0; i < len; i++)
    {
        int p = x[i];
        int q = y[i];
        graph[p].push_back(q);
        graph[q].push_back(p);
    }
}

int compute(int n)
{
    bool visit[n + 3];
    memset(visit, false, sizeof(visit));
    int no_of_node = 0;

    for (int i = 0; i < n; i++)
    {
        if (!visit[i])
        {
            node.clear();
            DFS(visit, i);
            int count = 0;
            for (auto it = node.begin(); it != node.end(); it++)
            {
                count += graph[(*it)].size();
                count /= 2;
                if (count == node.size() - 1)
                {
                    no_of_node++;
                }
            }
        }
    }
    return no_of_node;
}

int main()
{
    int n = 6, m = 4;
    int x[m + 5] = {1, 1, 4, 4};
    int y[m + 5] = {2, 3, 5, 6};
    buildgraph(x, y, n);
    cout << compute(n) << "=weakly connected node" << endl;
    return 0;
}