#include<bits/stdc++.h>
using namespace std;

int main(){
    // int arr[] = {3, 1, 4, 6, 5};
    int arr[] = {10, 4, 6, 12, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    bool flag = false;

    sort(arr, arr+n);

    for(int i=0;i<n;i++){
        arr[i] = arr[i]*arr[i];
    }

    for(int i=0;i<n;i++){
        int start = i+1;
        int end = n-1;
        while(start < end){
            int sum = arr[i] + arr[start];
            if(sum == arr[end]){
                flag = true;
                break;
            } else if(sum > arr[end]){
                start++;
            } else {
                end--;
            }
        }
        if(flag){
            break;
        }
    }

    cout<<((flag) ? "YES\n" : "NO\n");
    return 0;
}
