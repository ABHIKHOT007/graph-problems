#include <bits/stdc++.h>
using namespace std;
#define V 4

//travelling salseman problem.
//o(n!)


int travellingsalseman(int graph[][V], int s)
{
    vector<int> v;
    for(int i=0;i<V;i++){
        if(i!=s){
            v.push_back(i);
        }
    }
    int min_path=INT_MAX;
    do{
        int current_path=0;
        int k=s;
        for(int i=0;i<v.size();i++){
            current_path+=graph[k][v[i]];
            k=v[i];
        }
        current_path+=graph[k][s];
        min_path=(min_path,current_path);
    }
    while{
       (next_permutaion(v.begin(),v.end()));
    }
    return min_path;
}

int main()
{
    int graph[][V] = {{0, 10, 15, 20},
                      {10, 0, 35, 25},
                      {15, 35, 0, 30},
                      {20, 25, 30, 0}};
    int s = 0;
    cout <<travellingsalseman(graph, s) << endl;
    return 0;
}