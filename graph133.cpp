#include <bits/stdc++.h>
using namespace std;

int minimum_cost(int arr[], int n)
{
    int mn = INT_MAX;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        mn = min(arr[i], mn);
        sum += arr[i];
    }
    return mn * (sum - mn);
}

int main()
{
    int arr[] = {6,2,1,5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << minimum_cost(arr, n) << endl;
    return 0;
}