#include <bits/stdc++.h>
using namespace std;
//Eulerian path in undirected graph.

void findpath(int graph[][5], int n)
{
    vector<int> numofadj;

    for (int i = 0; i < n; i++)
    {
        numofadj.push_back(accumulate(graph[i], graph[i] + 5, 0));
    }

    int startpoint = 0;
    int numofodd = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (numofadj[i] % 2 == 1)
        {
            numofodd++;
            startpoint = i;
        }
    }
    if (numofodd > 2)
    {
        cout << "NO solution" << endl;
        return;
    }
    stack<int> Stack;
    vector<int> path;
    int curr = startpoint;

    while (!Stack.empty() || accumulate(graph[curr], graph[curr] + 5, 0) != 0)
    {
        if (accumulate(graph[curr], graph[curr] + 5, 0) == 0)
        {
            path.push_back(curr);
            curr = Stack.top();
            Stack.pop();
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                if (graph[curr][i] == 1)
                {
                    Stack.push(curr);
                    graph[curr][i] = 0;
                    graph[i][curr] = 0;
                    curr = i;
                    break;
                }
            }
        }
    }
    for (auto ele : path)
        cout << ele << "->";
    cout << curr << endl;
}

int main()
{
    int graph1[][5] = {{0, 1, 0, 0, 1},
                       {1, 0, 1, 1, 0},
                       {0, 1, 0, 1, 0},
                       {0, 1, 1, 0, 0},
                       {1, 0, 0, 0, 0}};
    int n = sizeof(graph1) / sizeof(graph1[0]);
    findpath(graph1, n);
    return 0;
}