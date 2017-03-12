#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[] = {2, 3, 3, 2, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    for(int i=0;i<n;i++)
        arr[i]--;
    
    for(int i=0;i<n;i++){
        int num = arr[i] % n;
        arr[num] += n;
    }

    for(int i=0;i<n;i++){
        cout<<i+1<<" - "<<(arr[i] / n)<<"\n";
    }

    return 0;
}
