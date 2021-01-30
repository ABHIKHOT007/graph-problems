#include <bits/stdc++.h>
using namespace std;
#define ROW 5
#define COl 5

// No of islands.connected components

bool isvalid(int row, int col, int arr[ROW][COl], bool visited[][COl])
{
    return (row >= 0) && (row < ROW) && (col >= 0) && (col < COl) && (arr[row][col] != 0 && !visited[row][col]);
}

void DFS(int arr[][COl], int row, int col, bool visited[][COl])
{
    static int rowno[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    static int colno[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    visited[row][col] = true;

    for (int k = 0; k < 8; k++)
    {
        if (isvalid(row + rowno[k], col + colno[k], arr, visited))
        {
            DFS(arr, row + rowno[k], col + colno[k], visited);
        }
    }
}

int countIslands(int arr[][COl])
{
    bool visited[ROW][COl];
    memset(visited, false, sizeof(visited));

    int count = 0;
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COl; j++)
        {
            if (arr[i][j] && !visited[i][j])
            {
                DFS(arr, i, j, visited);
                count++;
            }
        }
    }
    return count;
}

int main()
{
    int arr[][COl] = {{1, 1, 0, 0, 0},
                      {0, 1, 0, 0, 1},
                      {1, 0, 0, 1, 1},
                      {0, 0, 0, 0, 0},
                      {1, 0, 1, 0, 1}};
    cout << "Number of islands is:" << countIslands(arr);
    return 0;
}