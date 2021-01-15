#include<bits/stdc++.h>
using namespace std;

bool ispossible(int m,int n,int r,int k,vector<int> X,vector<int> Y)
{
    int rect[m][n]={0};

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int p=0;p<k;p++){
                if(sqrt((pow((X[p]-1-i),2)+pow((Y[p]-1-i),2)))<=r){
                    rect[i][j]=-1;
                }
            }
        }
    }

    if(rect[0][0]==-1){
        return false;
    }

    vector<vector<int>> q;
    rect[0][0]=1;
    q.push_back({0,0});

    while(q.empty()){
        vector<int> arr = q.front();
        q.erase(q.begin());
        int elex=arr[0];
        int eley=arr[1];

        if((elex>0) && (eley>0) && rect[elex-1][eley-1]==0){
            vector<int> v={elex-1,eley-1};
            q.push_back(v);
        }
        if((elex>0) && (rect[elex-1][eley]==0)){
            rect[elex-1][eley]=1;
            vector<int> v={elex,eley-1};
        }
        if((elex>0) && (eley<n-1) && (rect[elex-1][eley+1]==0)){
            rect[elex-1][eley-1]=1;
            vector<int> v={elex,eley-1};
            q.push_back(v);
        }
        if((eley<n-1) && (rect[elex][eley+1]==0)){
            rect[elex][eley+1]=1;
            vector<int> v={elex,eley+1};
            q.push_back(v);
        }
        if((elex<m-1) && (eley>0) && (rect[elex+1][eley-1]==0)){
            rect[elex][eley+1]=1;
            vector<int> v={elex,eley+1};
            q.push_back(v);
        }
        if((elex<m-1) && (eley>0) && (rect[elex+1][eley-1])){
            rect[elex+1][eley-1]=1;
            vector<int> v={elex+1,eley-1};
            q.push_back(v);
        }
        if((elex<m-1) && (rect[elex+1][eley]==0)){
            rect[elex+1][eley]=1;
            vector<int> v={elex+1,eley};
            q.push_back(v);
        }
        if((elex<m-1) && (eley<n-1) && (rect[elex+1][eley+1]==0)){
            rect[elex+1][eley]=1;
            vector<int> v={elex+1,eley+1};
            q.push_back(v);
        }
    }
    return (rect[m-1][n-1]==1);
}

int main()
{
    int m1=5,n1=5,k1=2,r1=1;
    vector<int> X1={1,3};
    vector<int> Y1={3,3};

    if(ispossible(m1,n1,k1,r1,X1,Y1)){
        cout<<"possible"<<endl;
    }
    else{
        cout<<"Not possible"<<endl;
    }

    int m2=5,n2=5,k2=2,r2=1;
    vector<int> X2={1,1};
    vector<int> Y2={2,3};

    if(ispossible(m1,n2,k2,r2,X2,Y2)){
        cout<<"possible"<<endl;
    }
    else{
        cout<<"Not possible"<<endl;
    }

    return 0;
}