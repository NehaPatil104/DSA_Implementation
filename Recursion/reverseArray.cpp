#include<iostream>

using namespace std;

void reverse(int *arr, int n, int s, int e){
    if(s > e)
        return;
    int temp = arr[s];
    arr[s] = arr[e];
    arr[e] = temp;

    reverse(arr, n, s+1, e-1);
}

int main(){

    int n;
    cin>>n;

    int arr[n];
    for(int i = 0; i < n; i++)
        cin>>arr[i];
    reverse(arr, n, 0, n-1);

    cout<<"Reverse -> ";
    for(int i = 0; i < n; i++) 
        cout<<arr[i]<<" ";
    return 0;
}