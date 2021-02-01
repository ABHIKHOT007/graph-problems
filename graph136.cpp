#include <bits/stdc++.h>
using namespace std;

int countnodes(vector<int> adj[], int n, int x, int y)
{
    bool visited[n + 1] = {false};
    int parent[n];
    queue<int> q;
    q.push(x);
    visited[x] = true;
    int m;
    while (!q.empty())
    {
        m = q.front();
        q.pop();
        for (int i = 0; i < adj[m].size(); i++)
        {
            int h = adj[m][i];
            if (!visited[h])
            {
                visited[h] = true;
                parent[h] = m;
                q.push(h);
            }
        }
    }
    int count = 0;
    int i = parent[y];
    while (i != x)
    {
        count++;
        i = parent[i];
    }
    return count;
}

int main()
{
    vector<int> adj[7];

    adj[1].push_back(4);
    adj[4].push_back(1);
    adj[5].push_back(4);
    adj[4].push_back(5);
    adj[4].push_back(2);
    adj[2].push_back(4);
    adj[2].push_back(6);
    adj[6].push_back(2);
    adj[6].push_back(3);
    adj[3].push_back(6);

    cout << countnodes(adj, 7, 1, 3);
    return 0;
}