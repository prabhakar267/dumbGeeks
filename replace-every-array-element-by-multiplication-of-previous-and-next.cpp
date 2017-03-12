#include<bits/stdc++.h>
using namespace std;

int main(){
    // int arr[] = {1, 5, 10, 20, 40, 80};
    int arr[] = {2, 3, 4, 5, 6};
    int n = sizeof(arr)/sizeof(arr[0]);

    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<"\n";

    int prev = arr[0];
    int curr = arr[1];

    arr[0] = arr[0] * arr[1];
    for(int i=1;i<n-1;i++){
        curr = arr[i];
        arr[i] = prev * arr[i+1];
        prev = curr;
        // arr[i] = arr[]
    }

    arr[n-1] *= prev;

    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<"\n";

    return 0;
}
