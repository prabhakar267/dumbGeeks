#include<bits/stdc++.h>
using namespace std;

int searchMimElement(int arr[], int low, int high){
    if(low == high)
        return low;

    if(high < low)
        return 0;

    int mid = (low + high) / 2;

    if((mid > low) && (arr[mid] < arr[mid - 1]))
        return mid;
    if((mid < high) && (arr[mid] > arr[mid + 1]))
        return mid+1;

    if(arr[mid] > arr[low])
        return searchMimElement(arr, mid + 1, high);
    return searchMimElement(arr, low, mid-1);
}

int main(){
    int arr[] = {5, 6, 1, 2, 3, 4};
    // int arr[] = {5, 6, 7, 1, 2, 3, 4};

    int n = sizeof(arr) / sizeof(arr[0]);
    int index = searchMimElement(arr, 0, n-1);

    cout<<arr[index]<<"\n";

    return 0;
}
