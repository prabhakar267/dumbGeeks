#include<bits/stdc++.h>
using namespace std;

int main(){
    // int arr1[] = {0, 1, 0, 1, 1, 1, 1};
    // int arr2[] = {1, 1, 1, 1, 1, 0, 1};
    int arr1[] = {0, 1, 0, 0, 0, 0};
    int arr2[] = {1, 0, 1, 0, 0, 1};
    
    int n = sizeof(arr1)/sizeof(arr1[0]);

    int diff_arr[2*n + 1];
    for(int i=0;i<(2*n+1);i++){
        diff_arr[i] = -1;
    }

    int sum1 = 0, sum2 = 0;
    int max_len = 0;

    for(int i=0;i<n;i++){
        sum1 += arr1[i];
        sum2 += arr2[i];

        int diff = sum2 - sum1;
        int diff_index = diff + n;

        if(diff == 0)
            max_len = max(max_len, i+1);
        
        if(diff_arr[diff_index] < 0){
            diff_arr[diff_index] = i;
        } else {
            int len = i - diff_arr[diff_index];
            max_len = max(max_len, len);
        }
    }

    cout<<max_len<<"\n";

    return 0;
}
