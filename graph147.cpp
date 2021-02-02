#include <bits/stdc++.h>
using namespace std;
#define V 4

int countTriangle(int graph[V][V], bool isdirected)
{
    int count_tiangle = 0;
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            for (int k = 0; k < V; k++)
            {
                if (graph[i][j] && graph[j][k] && graph[k][i])
                {
                    count_tiangle++;
                }
            }
        }
    }
    isdirected ? count_tiangle /= 3 : count_tiangle /= 6;
    return count_tiangle;
}

int main()
{
    int graph[][V] = {{0, 1, 1, 0},
                      {1, 0, 1, 1},
                      {1, 1, 0, 1},
                      {0, 1, 1, 0}};
    cout << "no of triangle in griven graph are:" << countTriangle(graph, false) << endl;
    return 0;
}