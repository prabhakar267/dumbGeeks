#include<bits/stdc++.h>
using namespace std;

void flip(int arr[], int i){
    int temp, start = 0;
    while (start < i)
    {
        temp = arr[start];
        arr[start] = arr[i];
        arr[i] = temp;
        start++;
        i--;
    }
}

int findIndex(int arr[], int low, int high, int x){
    if(arr[low] >= x)
        return low;
    if(arr[high] < x)
        return -1;

    int mid = (low + high) / 2;
    
    if(arr[mid] == x){
        return mid;
    }

    if(arr[mid] < x){
        if((mid + 1) <= high && arr[mid+1] >= x){
            return mid+1;
        } else {
            return findIndex(arr, mid+1, high, x);
        }
    } else {
        if((mid-1) >= low && arr[mid-1] < x){
            return mid;
        } else {
            return findIndex(arr, low, mid-1, x);
        }
    }
}

int main(){
    int arr[] = {18, 40, 35, 12, 30, 35, 20, 6, 90, 80};
    int n = sizeof(arr)/sizeof(arr[0]);

    for(int i=1;i<n;i++){
        int j = findIndex(arr, 0, i-1, arr[i]);
        
        if(j != -1){
            flip(arr, j-1);
            flip(arr, i-1);
            flip(arr, i);
            flip(arr, j);
        }
    }

    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<"\n";
    return 0;
}
