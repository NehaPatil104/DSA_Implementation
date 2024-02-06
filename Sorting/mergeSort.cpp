#include<iostream>

using namespace std;

void merge(int arr[], int s, int e){

    // divide the array
    int mid = (s + e) / 2;

    // Find the length of both parts
    int len1 = mid - s + 1;
    int len2 = e - mid;

    // create two array of len1 and len2 size respectively
    int *first = new int[len1];
    int *second = new int[len2];

    //copy array elements into first and second array
    int index = s;
    for(int i = 0; i < len1; i++)
        first[i] = arr[index++];
    
    index = mid + 1;
    for(int i = 0; i < len2; i++)
        second[i] = arr[index++];

    // merge both array into original array
    int index1 = 0, index2 = 0;
    int mainIndex = s;

    while(index1 < len1 && index2 < len2){
        // If first array's element is smaller
        if(first[index1] < second[index2])
            arr[mainIndex++] = first[index1++];
        else    
            arr[mainIndex++] = second[index2++];
    }

    // If first array size is greater than second
    while(index1 < len1)
        arr[mainIndex++] = first[index1++];

    // If second array size is greater than first
    while(index2 < len2)
        arr[mainIndex++] = second[index2++];  
    
    // delete both arrays
    delete []first;
    delete []second;
}

void mergeSort(int arr[], int s, int e){

    // base condition
    if(s >= e)
        return;

    // divide array
    int mid = s + (e-s)/2;

    // sort left part
    mergeSort(arr, s, mid);

    // sort right part
    mergeSort(arr, mid + 1, e);

    // merge both parts
    merge(arr, s, e);
}

int main(){

    int n;
    cin>>n;
    
    int arr[n];

    for(int i = 0; i < n; i++)
        cin>>arr[i];

    mergeSort(arr, 0, n-1);

    cout<<"Sorted Array==> ";

    for(int i = 0; i < n; i++)
        cout<<arr[i]<<" ";

    return 0;
}