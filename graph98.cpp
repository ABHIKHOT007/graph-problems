#include<bits/stdc++.h>
using namespace std;
//space optimization.
const int row=3;
const int col=3;

int minimumcost(int cost[row][col])
{
    for(int i=1;i<row;i++){
        cost[i][0]+=cost[i-1][0];
    }
    for(int j=1;j<col;j++){
        cost[0][j]+=cost[0][j-1];
    }
    for(int i=1;i<row;i++){
        for(int j=1;j<col;j++){
            cost[i][j]+=min(cost[i-1][j-1],min(cost[i-1][j],cost[i][j-1]));
        }
    }
    return cost[row-1][col-1];
}

int main()
{
    int cost[row][col]={{1,2,3},{4,8,2},{1,5,3}};
    cout<<minimumcost(cost)<<endl;
    return 0;
}