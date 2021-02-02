#include <bits/stdc++.h>
using namespace std;

#define M 3
#define N 3

string dictionary[] = {"GEEKS", "FOR", "QUIZ", "GO"};
int n = sizeof(dictionary) / sizeof(dictionary[0]);

bool isword(string &str)
{
    for (int i = 0; i < n; i++)
    {
        if (str.compare(dictionary[i]) == 0)
        {
            return true;
        }
    }
    return false;
}

void findwordUtil(char boggle[M][N], bool visited[M][N], int i, int j, string &str)
{
    visited[i][j] = true;
    str = str + boggle[i][j];
    if (isword(str))
    {
        cout << str << endl;
    }
    for (int row = i - 1; row <= i + 1 && row < M; row++)
    {
        for (int col = j - 1; col <= j + 1 && col < N; col++)
        {
            findwordUtil(boggle, visited, row, col, str);
        }
    }
    str.erase(str.length() - 1);
    visited[i][j] = false;
}

void findword(char boggle[M][N])
{
    bool visited[M][N] = {{false}};
    string str = "";
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            findwordUtil(boggle, visited, i, j, str);
        }
    }
}

int main()
{
    char boggle[M][N] = {{'G', 'I', 'Z'},
                         {'U', 'E', 'K'},
                         {'Q', 'S', 'E'}};
    cout << "following word of dictionary are present \n";
    findword(boggle);
    return 0;
}