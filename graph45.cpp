#include<bits/stdc++.h>
using namespace std;

bool isvalid(int x, int y, int m, int n)
{
    return (x>=0 && x<m && y>=0 && y<n);
}

double probility(int m, int n, int x, int y, int steps)
{
    if(!isvalid(x,y,m,n)){
        return 0.0;
    }
    if(steps==0){
        return 1.0;
    }

    double prob=0.0;

    prob+=probility(m,n,x-1,y,steps-1)*0.25;//up
    prob+=probility(m,n,x,y+1,steps-1)*0.25;//right
    prob+=probility(m,n,x+1,y,steps-1)*0.25;//down
    prob+=probility(m,n,x,y-1,steps-1)*0.25;//left

    return prob;
}

int main()
{
    int m=5,n=5;

    int i=1,j=1;

    int steps=2;

    cout<<probility(m,n,i,j,steps);

    return 0;
}