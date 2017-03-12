#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[] = {1, 12, -5, -6, 50, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 4;

    int sum = 0;
    for(int i=0;i<k;i++){
        sum += arr[i];
    }

    float best_avg = (float)sum / k;
    int avg_index = 0;

    for(int i=k; i<n; i++){
        sum += arr[i];
        sum -= arr[i-k];

        if(((float)sum / k) > best_avg){
            best_avg = ((float)sum / k);
            avg_index = i;
        }
    }

    cout<<(avg_index-k+1)<<"\n";

    return 0;
}
