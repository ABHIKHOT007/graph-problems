#include <bits/stdc++.h>
using namespace std;

#define M 5
#define N 5

struct Node
{
    int i;
    int j;
    int distance;
};

int row[] = {-1, 0, 1, 0};
int col[] = {0, 1, 0, -1};

bool isvalid(int i, int j)
{
    if ((i < 0 || i > M - 1) || (j < 0 || j > N - 1))
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool issafe(int i, int j, char matrix[][N], int output[][N])
{
    if (matrix[i][j] != 'O' || output[i][j] != -1)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void findShortestDistance(char matrix[][N])
{
    int output[M][N];
    queue<Node> q;

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            output[i][j] = -1;
            if (matrix[i][j] == 'G')
            {
                Node pos = {i, j, 0};
                q.push(pos);
                output[i][j] = 0;
            }
        }
    }
    while (!q.empty())
    {
        Node curr = q.front();
        int x = curr.i;
        int y = curr.j;
        int dist = curr.distance;

        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (issafe(x + row[i], y + col[i], matrix, output) && isvalid(x + row[i], y + col[i]))
                {
                    output[x + row[i]][y + col[i]] = dist + 1;
                    Node pos = {x + row[i], y + col[i], dist + 1};
                    q.push(pos);
                }
            }
        }
        q.pop();
    }
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << setw(3) << output[i][j];
        }
        cout << endl;
    }
}

int main()
{
    char matrix[][N] = {{'O', 'O', 'O', 'O', 'G'}, {'O', 'W', 'W', 'O', 'G'}, {'O', 'O', 'O', 'W', 'G'}, {'O', 'O', 'O', 'O', 'G'}};

    findShortestDistance(matrix);
}