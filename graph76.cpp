#include<bits/stdc++.h>
using namespace std;

void subsetUtil(int *arr, int n, bool *curr_elemets, int no_of_elements, bool *soln, int *min_diff, int sum, int curr_sum, int curr_position)
{
    if(curr_position==n){
        return;
    }
    if((n/2-no_of_elements) > (n-curr_position)){
        return;
    }
    subsetUtil(arr,n,curr_elemets,no_of_elements,soln,min_diff,sum,curr_sum,curr_position+1);

    no_of_elements++;
    curr_sum=curr_sum+arr[curr_position];
    curr_elemets[curr_position]=true;

    if(no_of_elements==n/2){
        *min_diff=abs(sum/2-curr_sum);
        for(int i=0;i<n;i++){
            soln[i]=curr_elemets[i];
        }
    }
    else{
        subsetUtil(arr,n,curr_elemets,no_of_elements,soln,min_diff,sum,curr_sum,curr_position+1);
    }
    curr_elemets[curr_position]=false;
}

void subset(int *arr, int n)
{
    bool *curr_element = new bool[n];
    bool *soln=new bool[n];

    int min_diff=INT_MAX;
    int sum=0;

    for(int i=0;i<n;i++){
        sum+=arr[i];
        curr_element[i]=soln[i]=false;
    }
    subsetUtil(arr,n,curr_element,0,soln,&min_diff,sum,0,0);

    cout<<"the first subset is:"<<endl;
    for(int i=0;i<n;i++){
        if(soln[i]==true){
            cout<<arr[i]<<" ";
        }
    }
    cout<<endl;
    cout<<"the second subset is:"<<endl;
    for(int i=0;i<n;i++){
        if(soln[i]==false){
            cout<<arr[i]<<" ";
        }
    }
}

int main()
{
    int arr[]={23, 45, -34, 12, 0, 98, -99, 4, 189, -1, 4}; 
    int n=sizeof(arr)/sizeof(arr[0]);
    subset(arr,n);
    return 0;
}