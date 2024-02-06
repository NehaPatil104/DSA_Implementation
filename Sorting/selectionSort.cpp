#include<iostream>

using namespace std;

void selectionSort(int arr[], int n){
    int i, j, mini;

    for(i = 0; i < n - 1; i++){
        mini = i;

        for(j = i + 1; j < n; j++){
            if(arr[j] < arr[mini])
                mini = j;
        }

        int temp = arr[i];
        arr[i] = arr[mini];
        arr[mini] = temp;
    }
}

int main(){

    int n;
    cin>>n;
    
    int arr[n];

    for(int i = 0; i < n; i++)
        cin>>arr[i];

    selectionSort(arr, n);

    cout<<"Sorted Array==> ";

    for(int i = 0; i < n; i++)
        cout<<arr[i]<<" ";

    return 0;
}