#include<bits/stdc++.h> 
using namespace std; 

void subsetSum(int i, int sum, int n, vector<int> &arr, vector<int> &ans, vector<int> &temp){
    if(i == n){
        ans.push_back(sum);
        return;
    }

    temp.push_back(arr[i]);
    subsetSum(i+1, sum+arr[i], n, arr, ans, temp);
    temp.pop_back();
    subsetSum(i+1, sum, n, arr, ans, temp);
}

int main() 
{ 

    int N;
    cin >> N;
    vector<int> arr(N);
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    vector<int> ans;
    vector<int> temp;
    subsetSum(0, 0, N, arr, ans, temp);

    sort(ans.begin(), ans.end());
    
    cout<<"Answer -> "<<endl;
    for(int i = 0; i < ans.size(); i++)
        cout<<ans[i]<<" ";
    
    return 0; 
} 