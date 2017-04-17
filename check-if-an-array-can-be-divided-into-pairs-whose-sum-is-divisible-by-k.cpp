#include<bits/stdc++.h>
using namespace std;

bool checkPairs(int arr[], int k){
    map <int, int> frequency;
    int n = sizeof(arr) / sizeof(arr[0]);

    if(n & 1)
        return false;
    
    for(int i=0; i<n; i++){
        frequency[arr[i] % k]++;
    }

    for(int i=0; i<n; i++){
        int remainder = arr[i] % k;
        if(remainder == 0){
            if(frequency[remainder] & 1)
                return false;
        } else if(2*remainder == k){
            if(frequency[remainder] & 1)
                return false;
        } else {
            if(frequency[remainder] != frequency[k - remainder])
                return false;
        }
    }

    return true;
}

int main(){
    int arr[] = {92, 75, 65, 48, 45, 35, 70, 10};
    // int arr[] = {91, 74, 66, 48};
    int k = 10;

    cout<<(checkPairs(arr, k) ? "True" : "False")<<"\n"; 

    return 0;
}
