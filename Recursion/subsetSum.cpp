#include<bits/stdc++.h> 
using namespace std; 

class Solution{   
public:
    
    bool subsetSum(int i, int target, int sum, int n, vector<int> &arr, vector<vector<int>> &ans, vector<int> &temp){
        if(i == n){
            if(target == sum){
                return true;
            }
            return false;
        }
        
        temp.push_back(arr[i]);
        if(subsetSum(i+1, target+arr[i], sum, n, arr, ans, temp)== true) return true;
        temp.pop_back();
        if(subsetSum(i+1, target, sum, n, arr, ans, temp) == true ) return true;
        
        return false;
    }

    bool isSubsetSum(vector<int>arr, int sum){
        vector<vector<int>> ans;
        vector<int> temp;
        int n = arr.size();
        return subsetSum(0, 0, sum, n, arr, ans, temp);
    }
};

int main() 
{ 

    int N, sum;
    cin >> N;
    vector<int> arr(N);
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    cin >> sum;
    
    Solution ob;
    cout << ob.isSubsetSum(arr, sum) << endl;
    
    return 0; 
} 
