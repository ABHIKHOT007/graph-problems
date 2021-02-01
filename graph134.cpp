#include <bits/stdc++.h>
using namespace std;

int min_cost(int arr[], int n)
{
    int mn = INT_MAX;
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        mn = min(mn, arr[i]);
        sum += arr[i];
    }
    return mn * (sum - mn);
}

int main()
{
    int arr[] = {6, 2, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    min_cost(arr, n);
    return 0;
}