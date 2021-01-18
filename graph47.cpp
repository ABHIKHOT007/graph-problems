#include<bits/stdc++.h>
using namespace std;

#define ROW 5
#define COL 5
int isvalid(int arr[][COL], int row, int col, bool visited[][COL])
{
    return (row>=0)&&(row<ROW)&&(col>=0)&&(col<COL) && (arr[row][col] && !visited[row][col]);
}

void DFS(int arr[][COL], int row, int col, bool visited[][COL])
{
    static int rownbr[]={-1,-1,-1,0,0,1,1,1};
    static int colnbr[]={-1,0,1,-1,1,-1,0,1};

    visited[row][col]=true;

    for(int k=0;k<8;k++){
        if(isvalid(arr,row+rownbr[k],col+colnbr[k],visited)){
            DFS(arr,row+rownbr[k],col+colnbr[k],visited);
        }
    }
}

int countislands(int arr[][COL])
{
    bool visited[ROW][COL];
    memset(visited,0,sizeof(visited));

    int count=0;
    for(int i=0;i<ROW;i++){
        for(int j=0;j<COL;j++){
            if(arr[i][j] && !visited[i][j]){
                DFS(arr,i,j,visited);
                ++count;
            }
        }
    }
    return count;
}

int main()
{
    int arr[][COL]={{1,1,0,0,0},{0,1,0,0,1},{0,0,0,0,0},{1,0,0,1,1},{1,0,1,0,1}};

    cout<<"Number of island is:"<<countislands(arr);
    return 0;
}
