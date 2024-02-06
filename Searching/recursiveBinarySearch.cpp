#include<iostream>

using namespace std;

int binarySearch(int arr[], int key, int s, int e){

    if(e >= s){
        int mid = s + (e - s)/2;

        if(key == arr[mid])
            return mid;
        
        if(key < arr[mid])
            return binarySearch(arr, key, s, mid - 1);
        
        return binarySearch(arr, key, mid + 1, e);
    }

    return -1;
}

int main(){

    int n;
    cin>>n;
    
    int arr[n];

    for(int i = 0; i < n; i++)
        cin>>arr[i];
    
    int key;
    cin>>key;

    cout<<"Array Index==> "<<binarySearch(arr, key, 0, n-1);

    return 0;
}