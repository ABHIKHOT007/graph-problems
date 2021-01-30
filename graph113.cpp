#include <bits/stdc++.h>
using namespace std;
//Disjoint set data structure.

class DisJointSet
{
    int *rank;
    int *parent;
    int n;

public:
    DisJointSet(int n)
    {
        rank = new int[n];
        parent = new int[n];
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
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    void Union(int x, int y)
    {
        int xset = find(x);
        int yset = find(y);

        if (xset == yset)
        {
            return;
        }

        if (rank[xset] < rank[yset])
        {
            parent[xset] = yset;
        }
        else if (rank[xset] > rank[yset])
        {
            parent[yset] = xset;
        }
        else
        {
            parent[yset] = xset;
            rank[xset] = rank[xset] + 1;
        }
    }
};

int main()
{
    DisJointSet d(5);
    d.Union(0, 2);
    d.Union(4, 2);
    d.Union(3, 1);

    if (d.find(4) == d.find(0))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    if (d.find(1) == d.find(0))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}