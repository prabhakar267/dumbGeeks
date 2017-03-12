#include<bits/stdc++.h>
using namespace std;

int main(){
    // int arr[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    // int arr[] = {2, 0, 2};
    int arr[] = {3, 0, 0, 2, 0, 4};

    int n = sizeof(arr) / sizeof(arr[0]);

    int left[n], right[n];

    left[0] = 0;
    int left_max = 0;
    for(int i=1;i<n;i++){
        left_max = max(left_max, arr[i-1]);
        left[i] = left_max;
    }
    
    right[n-1] = 0;
    int right_max = 0;
    for(int i=n-2;i>=0;i--){
        right_max = max(right_max, arr[i+1]);
        right[i] = right_max;
    }

    int total_water = 0;
    for(int i=1;i<n-1;i++){
        int min_height = min(left[i], right[i]);
        if(min_height != 0){
            total_water += max(0, (min_height-arr[i]));
        }
    }


    // for(int i=0;i<n;i++){
    //     cout<<right[i]<<" ";
    // }
    cout<<total_water<<"\n";

    return 0;
}
