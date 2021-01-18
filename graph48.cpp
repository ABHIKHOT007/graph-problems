#include<bits/stdc++.h>
using namespace std;

#define ROW 4
#define COL 5

int isvalid(int arr[][COL], int row, int col, bool visited[][COL])
{
    return (row>=0)&&(row<ROW)&&(col>=0)&&(col<COL)&&(arr[ROW][COL]&&!visited[row][col]);
}

void DFS(int arr[][COL], int row, int col, bool visited[][COL], int &count)
{
    static int rownbr[]={ -1, -1, -1, 0, 0, 1, 1, 1 };
    static int colnbr[]={ -1, 0, 1, -1, 1, -1, 0, 1 };

    visited[row][col]=true;

    for(int k=0;k<8;k++){
        if(isvalid(arr,row+rownbr[k],col+colnbr[k],visited)){
            count++;
            DFS(arr,row+rownbr[k],col+colnbr[k],visited,count);
        }
    }
}

int largestregion(int arr[][COL])
{
    bool visited[ROW][COL];
    memset(visited,0,sizeof(visited));

    int result=INT_MIN;
    for(int i=0;i<ROW;i++){
        for(int j=0;j<COL;j++){
            int count=1;
            DFS(arr,i,j,visited,count);
            result =max(result,count);
        }
    }
    return result;
}

int main()
{
    int arr[][COL]={{0,0,1,1,0},{1,0,1,1,0},{0,1,0,0,0},{0,0,0,0,1}};

    cout<<largestregion(arr);
    return 0;
}