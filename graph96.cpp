#include <bits/stdc++.h>
using namespace std;
//minimum path with only right and down moves.

#define R 3
#define C 3

int min(int x, int y, int z);

int mincost(int cost[R][C], int m, int n)
{
    if (n < 0 || m < 0)
    {
        return INT_MAX;
    }
    else if (m == 0 && n == 0)
    {
        return cost[m][n];
    }
    else
    {
        return cost[m][n] + min(mincost(cost, m - 1, n - 1), mincost(cost, m - 1, n), mincost(cost, m, n - 1));
    }
}

int min(int x, int y, int z)
{
    if (x < y)
    {
        return (x < z) ? x : z;
    }
    else
    {
        return (y < z) ? y : z;
    }
}

int main()
{
    int cost[R][C] = {{1, 2, 3}, {4, 8, 2}, {1, 5, 3}};
    cout << mincost(cost, 2, 2) << endl;
    return 0;
}