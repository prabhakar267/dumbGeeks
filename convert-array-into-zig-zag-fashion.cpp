#include<bits/stdc++.h>
using namespace std;

void swap(int arr[], int pos1, int pos2){
    int temp = arr[pos1];
    arr[pos1] = arr[pos2];
    arr[pos2] = temp;
}

int main(){
    // int arr[] = {4, 3, 7, 8, 6, 2, 1};
    int arr[] = {1, 4, 3, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    bool flag = true;

    for(int i=0;i<n-1;i++){
        if(flag && arr[i] > arr[i+1])
            swap(arr, i, i+1);
        else if(!flag && arr[i] < arr[i+1])
            swap(arr, i, i+1);

        flag = !flag;
    }


    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";

    return 0;
}
