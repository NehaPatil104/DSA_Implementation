#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    int target;
    cin>>target;

    vector<pair<int,int>> v;

    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            if(arr[i]+arr[j] == target){
                v.push_back({arr[i],arr[j]});
            }
        }
    }

    for(auto i : v){
        cout<<i.first<<" "<<i.second<<endl;
    }



    return 0;
}