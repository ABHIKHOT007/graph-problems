#include<bits/stdc++.h>
using namespace std;

bool DFS(int resdiff, int currstep, int w[], int arr[], int N, int steps)
{
    if(currstep > steps){
        return true;
    }

    for(int i=0;i<N;i++){
        if(arr[i] > resdiff && arr[i]!=w[currstep-1]){
            w[currstep]=arr[i];
            if(DFS(arr[i]-resdiff,currstep+1,w,arr,N,steps)){
                return true;
            }
        }
    }
    return false;
}

void printweightonscal(int arr[], int N, int steps)
{
    int w[steps];
    int i;
    if(DFS(0,0,w,arr,N,steps)){
        for(int i=0;i<steps;i++){
            cout<<w[i]<<" ";
        }
        cout<<endl;
    }
    else{
        cout<<"Not possible"<<endl;
    }
}

int main()
{
    int arr[]={2,3,5,6};
    int N=sizeof(arr)/sizeof(arr[0]);
    int steps=10;
    printweightonscal(arr,N,steps);
    return 0;
}