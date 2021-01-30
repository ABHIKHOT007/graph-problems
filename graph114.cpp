#include <bits/stdc++.h>
using namespace std;

//No of islands in disconnected graph.

class DisjointsUnionSets
{
    vector<int> rank, parent;
    int n;

public:
    DisjointsUnionSets(int n)
    {
        rank.resize(n);
        parent.resize(n);
        this->n = n;
        makeSet();
    }
    void makeSet()
    {
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }
    int find(int x)
    {
        if (parent[x] != x)
        {
            return find(parent[x]);
        }

        return x;
    }

    void Union(int x, int y)
    {
        int xroot = find(x);
        int yroot = find(y);

        if (xroot == yroot)
        {
            return;
        }

        if (rank[xroot] < rank[yroot])
        {
            parent[xroot] = yroot;
        }
        else if (rank[yroot] < rank[xroot])
        {
            parent[yroot] = xroot;
        }
        else
        {
            parent[yroot] = xroot;
            rank[xroot] = rank[xroot] + 1;
        }
    }
};

int countIslands(vector<vector<int>> a)
{
    int n = a.size();
    int m = a[0].size();

    DisjointsUnionSets *d = new DisjointsUnionSets(n * m);

    for (int j = 0; j < n; j++)
    {
        for (int k = 0; k < m; k++)
        {
            if (a[j][k] == 0)
            {
                continue;
            }

            if (j + 1 < n && a[j + 1][k] == 1)
            {
                d->Union(j * (m) + k, (j + 1) * (m) + k);
            }
            if (j - 1 >= 0 && a[j - 1][k] == 1)
            {
                d->Union(j * (m) + k, (j - 1) * (m) + k);
            }
            if (k + 1 < m && a[j][k + 1] == 1)
            {
                d->Union(j * (m) + k, (j) * (m) + k);
            }
            if (k - 1 >= 0 && a[j][k - 1] == 1)
            {
                d->Union(j * (m) + k, (j) * (m) + k - 1);
            }
            if (j + 1 < n && k + 1 < m && a[j + 1][k + 1] == 1)
            {
                d->Union(j * (m) + k, (j + 1) * (m) + k + 1);
            }
            if (j - 1 < n && k - 1 >= 0 && a[j + 1][k - 1] == 1)
            {
                d->Union(j * m + k, (j - 1) * m + k + 1);
            }
            if (j - 1 >= 0 && k - 1 >= 0 && a[j - 1][k - 1] == 1)
            {
                d->Union(j * m + k, (j - 1) * m + k - 1);
            }
        }
    }

    int *c = new int[n * m];
    int no_of_islands = 0;
    for (int j = 0; j < n; j++)
    {
        for (int k = 0; k < m; k++)
        {
            if (a[j][k] == 1)
            {
                int x = d->find(j * m + k);
                if (c[x] == 0)
                {
                    no_of_islands++;
                    c[x]++;
                }
                else
                {
                    c[x]++;
                }
            }
        }
    }
    return no_of_islands;
}

int main()
{
    vector<vector<int>> v = {{1, 1, 0, 0, 0},
                             {0, 1, 0, 0, 1},
                             {1, 0, 0, 1, 1},
                             {0, 0, 0, 0, 0},
                             {1, 0, 1, 0, 1}};
    cout << "Numbers of islands is:" << countIslands(v) << endl;
    return 0;
}