#include<bits/stdc++.h>
using namespace std;

int main(){
    // int arr[] = {1, 1, 0, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1};
    int arr[] = {1, 1, 0};
    // int arr[] = {1, 1, 1, 1, 0, 1, 1, 1, 1};

    int n = sizeof(arr)/sizeof(arr[0]);

    int prev = -1;
    int prev_prev = -1;
    int max_zeroes_so_far = 0;
    int max_index = -1;

    for(int i=0;i<n;i++){
        if(arr[i] == 0){
            int diff = (i - prev_prev);
            if(diff > max_zeroes_so_far){
                max_zeroes_so_far = diff;
                max_index = prev;
            }

            prev_prev = prev;
            prev = i;

        }
    }

    if((n - prev_prev) > max_zeroes_so_far)
        max_index = prev;    

    cout<<prev<<"\n";

    return 0;
}
