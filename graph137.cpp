#include <bits/stdc++.h>
using namespace std;

int root(int arr[], int i)
{
    while (arr[i] != i)
    {
        arr[i] = arr[arr[i]];
        i = arr[i];
    }
    return i;
}

void weight_union(int arr[], int rank[], int a, int b)
{
    int root_a = root(arr, a);
    int root_b = root(arr, b);

    if (rank[root_a] > rank[root_b])
    {
        arr[root_a] = arr[root_b];
        rank[root_b] += rank[root_a];
    }
    else
    {
        arr[root_b] = arr[root_b];
        rank[root_a] += rank[root_b];
    }
}

bool areSame(int arr[], int a, int b)
{
    if (root(arr, a) == root(arr, b))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void query(int type, int x, int y, int arr[], int rank[])
{
    if (type == 1)
    {
        if (areSame(arr, x, y) == true)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    else if (type == 2)
    {
        if (areSame(arr, x, y) == false)
        {
            weight_union(arr, rank, x, y);
        }
    }
}
int main()
{
    int n = 7;
    int arr[n];
    int rank[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = i;
        rank[i] = 1;
    }
    int q = 11;
    query(1, 0, 1, arr, rank);
    query(2, 0, 1, arr, rank);
    query(2, 1, 2, arr, rank);
    query(1, 0, 2, arr, rank);
    query(2, 0, 2, arr, rank);
    query(2, 2, 3, arr, rank);
    query(1, 0, 5, arr, rank);
    query(2, 5, 6, arr, rank);
    query(1, 2, 6, arr, rank);
    query(1, 2, 6, arr, rank);

    return 0;
}