#include<bits/stdc++.h>
using namespace std;

int main(){
    // int arr[] = {-3, 2, 3, 1, 6};
    int arr[] = {4, 2, -3, 1, 6};
    int n = sizeof(arr)/sizeof(arr[0]);

    map <int, bool> hash;
    bool flag = false;

    int sum = 0;
    for(int i = 0; i < n; ++i){
        sum += arr[i];

        if(sum == 0 || hash[sum] == true){
            flag = true;
            break;
        }
        hash[sum] = true;
    }

    cout<<((flag) ? "YES" : "NO")<<"\n";

    return 0;
}
