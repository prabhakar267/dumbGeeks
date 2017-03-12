#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[] = {1, 11, 100, 1, 0, 200, 3, 2, 1, 250};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 280;

    int start = 0;
    int end = 0;
    int length = INT_MAX;
    int sum = 0;

    while(end < n){
        while(sum < k && end < n){
            sum += arr[end];
            end++;
        }

        while(sum > k && start < n){
            int len = end - start;
            length = min(length, len);

            sum -= arr[start];
            start++;
        }
    }

    cout<<length<<"\n";
    return 0;
}
