#include<iostream>
#include<vector>

using namespace std;

void numSubseq(int i, int *arr, int n, int k, int sum, vector<vector<int>> &ans, vector<int> &temp,int mini, int maxi){

    if(i >= n){
        if(sum <= k)
            ans.push_back(temp);
        return;
    }

    numSubseq(i + 1, arr, n, k, sum, ans, temp, mini, maxi);
    temp.push_back(arr[i]);
    mini = min(mini, arr[i]);
    maxi = max(maxi,arr[i]);
    numSubseq(i + 1, arr, n, k, mini + maxi, ans, temp, mini, maxi);
    temp.pop_back();
    
}

int main(){

    int n;
    cin>>n;

    int arr[n];
    for(int i = 0; i < n; i++)
        cin>>arr[i];

    int k;
    cin>>k;

    vector<vector<int>> ans;
    vector<int> temp;

    numSubseq(0, arr, n, k, 0, ans, temp, 100, -1);

    cout<<"Answer -> "<<ans.size()-1<<endl;
    for(auto i : ans){
        for(auto j : i)
            cout<<j<<" ";
        
        cout<<endl;
    }
    

    return 0;
}