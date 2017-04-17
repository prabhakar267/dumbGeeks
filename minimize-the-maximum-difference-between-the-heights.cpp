#include<bits/stdc++.h>
using namespace std;

int main(){
    // int arr[] = {1, 15, 10}; int k = 6;
    // int arr[] = {1, 5, 15, 10}; int k = 3;
    // int arr[] = {4, 6}; int k = 10;
    // int arr[] = {6, 10}; int k = 3;
    // int arr[] = {1, 10, 14, 14, 14, 15}; int k = 6;
    int arr[] = {1, 2, 3}; int k = 2;
    
    int n = sizeof(arr)/sizeof(arr[0]);

    sort(arr, arr+n);

    int max_ele = arr[n-1];
    int min_ele = arr[0];
    int new_max, new_min;

    if(k >= (max_ele - min_ele)){
        for(int i=0;i<n;i++)
            arr[i] += k;
        new_max = max_ele;
        new_min = min_ele;
    } else {
        arr[0] += k;
        arr[n-1] -= k;

        new_max = max(arr[0], arr[n-1]);
        new_min = min(arr[0], arr[n-1]);

        for(int i=1;i<n-1;i++){
            if(arr[i] < new_min){
                arr[i] += k;
            } else if(arr[i] > new_max){
                arr[i] -= k;
            } else {
                if((arr[i] - new_min) > (new_max - arr[i])){
                    arr[i] -= k;
                } else {
                    arr[i] += k;
                }
            }
            new_max = max(new_max, arr[i]);
            new_min = min(new_min, arr[i]);
        }
    }

    cout<<(new_max - new_min)<<"\n";

    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<"\n";

    return 0;
}
