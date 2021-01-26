#include <bits/stdc++.h>
using namespace std;
//minimum path with left,right,up,down moves.

#define ROW 5
#define COL 5

struct cell
{
    int x, y;
    int distance;
    cell(int x, int y, int distance) : x(x), y(y), distance(distance) {}
};

bool operator<(const cell &a, const cell &b)
{
    if (a.distance == b.distance)
    {
        if (a.x != b.x)
        {
            return (a.x < b.x);
        }
        else
        {
            return (a.y < b.y);
        }
    }
    return (a.distance < b.distance);
}

bool isvalid(int i, int j)
{
    return (i >= 0 && i < COL && j >= 0 && j < ROW);
}

int shortestpath(int grid[ROW][COL], int row, int col)
{
    int dis[row][col];

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            dis[i][j] = INT_MAX;
        }
    }

    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};

    set<cell> st;
    st.insert(cell(0, 0, 0));
    dis[0][0] = grid[0][0];

    while (!st.empty())
    {
        cell k = *st.begin();
        st.erase(st.begin());

        for (int i = 0; i < 4; i++)
        {
            int x = k.x + dx[i];
            int y = k.y + dy[i];

            if (isvalid(x, y))
            {
                continue;
            }

            if (dis[x][y] > dis[k.x][k.y] + grid[x][y])
            {
                if (dis[x][y] != INT_MAX)
                {
                    st.erase(st.find(cell(x, y, dis[x][y])));
                }
                dis[x][y] = dis[k.x][k.y] + grid[x][y];
                st.insert(cell(x, y, dis[x][y]));
            }
        }
    }
    return dis[row - 1][col - 1];
}

int main()
{
    int gird[ROW][COL] = {{31, 100, 65, 12, 18}, {10, 13, 47, 157, 6}, {100, 113, 174, 11, 33}, {88, 124, 41, 20, 140}, {99, 32, 111, 41, 20}};

    cout << shortestpath(gird, ROW, COL) << endl;
    return 0;
}