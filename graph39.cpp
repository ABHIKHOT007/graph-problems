#include<bits/stdc++.h>
using namespace std;

struct cell
{
    int x,y;
    int dis;
    cell(){}
    cell(int x, int y, int dis):x(x),y(y),dis(dis){}
};

bool inside(int x, int y, int N)
{
    if(x>=1 && x<=N && y>=1 && y<=N){
        return true;
    }
    else{
        return false;
    }
}


int minimumsteps(int pos[], int target[], int N)
{
    int dx[]={-2,-1,1,2,-2,-1,1,2};
    int dy[]={-1,-2,-2,-1,1,2,2,1};

    queue<cell> q;

    cell t;
    int x,y;
    bool visit[N+1][N+1];

    for(int i=1;i<N;i++){
        for(int j=1;j<=N;j++){
            visit[i][j]=false;
        }
    }
    visit[pos[0]][pos[1]]=true;

    while(!q.empty()){
        t=q.front();
        q.pop();
        if(t.x==target[0] && t.y==target[1]){
            return t.dis;
        }

        for(int i=0;i<8;i++){
            x=t.x+dx[i];
            y=t.y+dy[i];
            if(inside(x,y,N) && !visit[x][y]){
                visit[x][y]=true;
                q.push(cell(x,y,t.dis+1));
            }
        }
    }
}

int main()
{
    int N=30;
    int pos[]={1,1};
    int target[]={30,30};
    cout<<minimumsteps(pos,target,N);
    return 0;
}