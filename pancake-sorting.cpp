#include<bits/stdc++.h>
using namespace std;

void flip(int arr[], int i){
    int temp, start = 0;
    while (start < i)
    {
        temp = arr[start];
        arr[start] = arr[i];
        arr[i] = temp;
        start++;
        i--;
    }
}

int main(){
    int arr[] = {23, 10, 20, 11, 12, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);

    for(int curr_size = n-1; curr_size >= 0; curr_size--){
        int max_index = 0;
        for(int i=1;i<=curr_size;i++){
            if(arr[i] > arr[max_index])
                max_index = i;
        }

        if(max_index != curr_size){
            flip(arr, max_index);
            flip(arr, curr_size);
        }
    }
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<"\n";
    return 0;
}
