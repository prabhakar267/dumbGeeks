#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[] = {2, 7, 3, 5, 3, 4, 1, 7, 5, 5, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 8;

    for(int i=0; i<n; i++){
        arr[arr[i]%k] += k;
    }

    int max_index = 1;
    for(int i=1; i<n; i++){
        if(arr[i] > arr[max_index])
            max_index = i;
    }

    cout<<max_index<<"\n";

    return 0;
}
