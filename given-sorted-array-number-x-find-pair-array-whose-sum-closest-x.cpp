#include<bits/stdc++.h>
using namespace std;

int main(){
    int ar1[] = {1, 4, 5, 7};
    int ar2[] = {10, 20, 30, 40};
    int n = sizeof(ar1)/sizeof(ar1[0]);
    int m = sizeof(ar2)/sizeof(ar2[0]);
    int x = 38;

    int l = 0;
    int r = n-1;
    int min_diff = INT_MAX;
    int index_n = -1, index_m = -1;

    while(l < n && r >= 0){
        int sum = ar1[l] + ar2[r];
        if(abs(sum - x) < min_diff){
            min_diff = sum - x;
            index_n = l;
            index_m = r;
        }

        if(sum > x){
            r--;
        } else {
            l++;
        }
    }

    cout<<ar1[index_n]<<" , "<<ar2[index_m]<<"\n";

    return 0;
}
