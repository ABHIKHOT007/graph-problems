#include<bits/stdc++.h>
using namespace std;

void DFS(int parent, int ans[], vector<int> connectchars[])
{
    ans[parent]=1;

    for(int i=0; i<connectchars[parent].size(); i++){
        if(!ans[connectchars[parent][i]]){
            DFS(connectchars[parent][i],ans,connectchars);
        }
    }
}

void printbinarypalidrome(int n, int k)
{
    int arr[n],ans[n]={0};

    vector<int> connectchars[k];
    for(int i=0;i<n;i++){
        connectchars[arr[i]].push_back(arr[n-i-1]);
        connectchars[arr[n-i-1]].push_back(arr[i]);
    }

    DFS(0,ans,connectchars);

    for(int i=0;i<n;i++){
        cout<<ans[arr[i]];
    }
}

int main()
{
    int n=10,k=4;
    printbinarypalidrome(n,k);
    return 0;
}