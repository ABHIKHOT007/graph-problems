#include<bits/stdc++.h>
using namespace std;

int minimumdistance(int arr[], int N)
{
    bool visit[N];
    int distance[N];
    vector<int> digit[10];

    memset(visit,false,sizeof(visit));

    for(int i=1;i<N;i++){
        digit[arr[i]].push_back(i);
    }

    distance[0]=0;
    visit[0]=true;

    queue<int> q;
    q.push(0);

    while(!q.empty()){
        int ind=q.front();
        q.pop();
        if(ind==N-1){
            break;
        }

        int d=arr[ind];

        for(int i=0;i<digit[d].size();i++){
            int nextind=digit[d][i];
            if(!visit[nextind]){
                visit[nextind]=true;
                q.push(nextind);

                distance[nextind]=distance[ind]+1;
            }
        }
        digit[d].clear();

        if(ind-1>=0&&!visit[ind-1]){
            visit[ind-1]=true;
            q.push(ind-1);
            distance[ind-1]=distance[ind]+1;
        }

        if(ind+1<N&&!visit[ind+1]){
            visit[ind+1]=true;
            q.push(ind+1);
            distance[ind+1]=distance[ind]+1;
        }
    }
    return distance[N-1];
}

int main()
{
    int arr[]={5,4,3,5,0};
    int N=sizeof(arr)/sizeof(arr[0]);
    cout<<minimumdistance(arr,N);
    return 0;
}