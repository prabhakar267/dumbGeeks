#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[] = {-1, 2, -3, 4, 5, 6, -7, 8, 9};
    int n = sizeof(arr)/sizeof(arr[0]);

    int i=-1;

    for(int j=0;j<n;j++){
        if(arr[j] < 0){
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int neg = 0;
    int pos = i+1;

    while(pos < n && neg < pos && arr[neg] < 0){
        int temp = arr[neg];
        arr[neg] = arr[pos];
        arr[pos] = temp;
        neg += 2;
        pos += 1;
    }

    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<"\n";
    return 0;
}
