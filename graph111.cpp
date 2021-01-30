#include <bits/stdc++.h>
using namespace std;
#define V 4
void printsolution(int reach[][V]);

void transitiveClouser(int graph[][V])
{
    int reach[V][V];
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            reach[i][j] = graph[i][j];
        }
    }

    for (int k = 0; k < V; k++)
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                reach[i][j] = reach[i][j] || (reach[i][k] && reach[k][j]);
            }
        }
    }
    printsolution(reach);
}

void printsolution(int reach[][V])
{
    cout << "followong matrix is transitive clouser of the given graph:" << endl;
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (i == j)
            {
                cout << "1"
                     << " ";
            }
            else
            {
                cout << reach[i][j] << " ";
            }
        }
        cout << endl;
    }
}

int main()
{
    int graph[V][V] = {{1, 1, 0, 1},
                       {0, 1, 1, 0},
                       {0, 0, 1, 1},
                       {0, 0, 0, 1}};
    transitiveClouser(graph);
    return 0;
}