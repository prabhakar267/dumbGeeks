#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[] = {1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    int zeroes_count = 0;
    int i=0, j=0;

    while(i<n){
        if(arr[i] == 0){
            i++;
            zeroes_count++;
        } else {
            arr[j] = arr[i];
            i++;
            j++;
        }
    }

    while(zeroes_count > 0){
        arr[n - zeroes_count] = 0;
        zeroes_count--;
    }

    for(i=0;i<n;i++)
        cout<<arr[i]<<" ";

    cout<<"\n";

    return 0;
}
