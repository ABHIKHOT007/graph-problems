#include <bits/stdc++.h>
using namespace std;

int compute(vector<int> graph[], int n)
{
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (graph[i].size() == 0)
        {
            count++;
        }
    }
    return count;
}

int main()
{
    int n = 6;
    vector<int> graph[7];

    graph[1].push_back(2);
    graph[2].push_back(1);
    graph[2].push_back(3);
    graph[3].push_back(2);
    graph[5].push_back(6);
    graph[6].push_back(5);

    cout << compute(graph, n);
    return 0;
}