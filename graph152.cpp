#include <bits/stdc++.h>
using namespace std;
#define V 4

bool isBipertiteUtil(int g[][V], int color[], int pos, int c)
{
    if (color[pos] != -1 && color[pos] != c)
    {
        return false;
    }

    color[pos] = c;
    bool ans = true;
    for (int i = 0; i < V; i++)
    {
        if (g[pos][i])
        {
            if (color[i] == -1)
            {
                ans &= isBipertiteUtil(g, color, i, 1 - c);
            }
            if (color[i] != -1 && color[i] != 1 - c)
            {
                return false;
            }
        }
        if (!ans)
        {
            return false;
        }
    }
    return true;
}

bool isbipertite(int g[][V])
{
    int color[V];
    for (int i = 0; i < V; i++)
    {
        color[i] = -1;
    }
    int pos = 0;
    return isBipertiteUtil(g, color, pos, 1);
}
int main()
{
    int g[][V] = {{0, 1, 0, 1},
                  {1, 0, 1, 0},
                  {0, 1, 0, 1},
                  {1, 0, 1, 0}};
    isbipertite(g) ? cout << "YES" : cout << "NO" << endl;
    return 0;
}