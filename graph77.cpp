#include<bits/stdc++.h>
using namespace std;
//knight tour problem

#define N 8

int solvetourUtil(int x, int y, int move, int soln[N][N], int xmove[], int ymove[]);

int isvalid(int x, int y, int soln[N][N])
{
    return (x>=0 && x<N && y>=0 && y<N && soln[x][y]==-1);
}

void printtour(int soln[N][N])
{
    for(int x=0;x<N;x++){
        for(int y=0;y<N;y++){
            cout<<" "<<setw(2)<<soln[x][y]<<" ";
        }
        cout<<endl;
    }
}

int sovletour()
{
    int soln[N][N];

    for(int x=0;x<N;x++){
        for(int y=0;y<N;y++){
            soln[x][y]=-1;
        }
    }

    int xmove[8]={2,1,-1,-2,-2,-1,1,2};
    int ymove[8]={1,2,2,1,-1,-2,-2,-1};
    soln[0][0]=0;

    if(solvetourUtil(0,0,1,soln,xmove,ymove)==0){
        cout<<"sloution dosen't exist"<<endl;
        return 0;
    }
    else{
        printtour(soln);
    }
    return 1;
}

int solvetourUtil(int x,int y,int move, int soln[N][N], int xmove[N], int ymove[N])
{
    int k,next_x,next_y;
    if(move==N*N){
        return 1;
    }

    for(k=0;k<8;k++){
        next_x=x+xmove[k];
        next_y=y+ymove[k];
        if(isvalid(next_x,next_y,soln)){
            soln[next_x][next_y]=move;
            if(solvetourUtil(next_x,next_y,move+1,soln,xmove,ymove)==1){
                return 1;
            }
            else{
                soln[next_x][next_y]=-1;
            }
        }
    }
    return 0;
}

int main()
{
    sovletour();
    return 0;
}