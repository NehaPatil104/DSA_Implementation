#include<iostream>
#include<vector>
using namespace std;

void subsequence(int i , int *arr,int n, vector<vector<int>> &ans, vector<int> &temp){
    if(i >= n){
        ans.push_back(temp);
        return;
    }

    temp.push_back(arr[i]);
    // Take
    subsequence(i + 1, arr, n, ans, temp);
    temp.pop_back();
    // Not take
    subsequence(i + 1, arr, n, ans, temp);
}

int main(){

    int n;
    cin>>n;

    int arr[n];

    for(int i = 0; i < n; i++)
        cin>>arr[i];
    
    vector<vector<int>> ans;
    vector<int> temp;

    subsequence(0, arr, n, ans, temp);

    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}