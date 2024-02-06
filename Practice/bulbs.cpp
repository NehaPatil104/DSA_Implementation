#include<iostream>
using namespace std;

int main(){

    int n;
    cin>>n;

    int arr[n+1] = {0};
    int count = 0;

    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j+= i){
            if(arr[j] == 1)
                arr[j] = 0;
            else if(arr[j] == 0)
                arr[j] =  1;
        }
    }

    for(int i = 1; i <= n; i++){
        cout<<arr[i]<<" ";
        if(arr[i] == 1)
            count++;
    }

    cout<<"Ans ->"<<count;
    return 0;
}