#include<bits/stdc++.h>
using namespace std;
#define N 4
void printsolution(int board[N][N])
{
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool isvalid(int board[N][N], int row, int col)
{
    int i,j;

    for(int i=0;i<col;i++){
        if(board[row][i]){
            return false;
        }
    }

    for(int i=row,j=col;i>=0&&j>=0;i--,j--){
        if(board[i][j]){
            return false;
        }
    }

    for(i=row,j=col;j>=0&&i<N;i++,j--){
        if(board[i][j]){
            return false;
        }
    }
    return true;
}

bool solveUtil(int board[N][N], int col)
{
    if(col>=N){
        return true;
    }

    for(int i=0;i<N;i++){
        if(isvalid(board,i,col)){
            board[i][col]=1;

            if(solveUtil(board,col+1)){
                return true;
            }
            board[i][col]=0;
        }
    }
    return false;
}

bool solve()
{
    int board[N][N]={{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};

    if(solveUtil(board,0)==false){
        cout<<"No"<<endl;
    }
    else{
        printsolution(board);
    }
    return true;
}

int main()
{
    solve();
    return 0;
}