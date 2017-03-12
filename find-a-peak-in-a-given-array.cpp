#include<bits/stdc++.h>
using namespace std;

int findPeak(int arr[], int n, int low, int high){
    int mid = (low + high)/2;

    if((mid == 0 || arr[mid] >= arr[mid-1]) && (mid == n-1 || arr[mid] >= arr[mid+1]))
        return mid;

    if(mid > 0 && (arr[mid-1] > arr[mid])){
        return findPeak(arr, n, low, mid-1); 
    } else {
        return findPeak(arr, n, mid+1, high);
    }
}

int main(){
    int arr[] = {1, 3, 20, 4, 1, 0};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<findPeak(arr, n, 0, n-1);

    cout<<"\n";
    return 0;
}
