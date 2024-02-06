#include<bits/stdc++.h> 
using namespace std; 

class Solution{   
public:
    long maximumSumSubarray(int K, vector<int> &Arr , int N){
        long maxSum = INT_MIN;
        long sum = 0;
        int i = 0, j = 0;
        
        while(j < N){
            sum += Arr[j];
            if(j - i + 1 == K){
                maxSum = max(sum, maxSum);
                sum -= Arr[i];
                i++;
            }
            j++;
        }
        return maxSum;
    }
};

int main() 
{ 

    int N,K;
    cin >> N >> K;;
    vector<int>Arr;
    for(int i=0;i<N;++i){
        int x;
        cin>>x;
        Arr.push_back(x);
    }
    Solution ob;
    cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    
    return 0; 
} 