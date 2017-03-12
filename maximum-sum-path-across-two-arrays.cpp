#include<bits/stdc++.h>
using namespace std;

int main(){
    // int ar1[] = {2, 3, 7, 10, 12, 15, 30, 34};
    // int ar2[] = {1, 5, 7, 8, 10, 15, 16, 19};

    int ar1[] = {2, 3, 7, 10, 12};
    int ar2[] = {1, 5, 7, 8};
    
    int n = sizeof(ar1)/sizeof(ar1[0]);
    int m = sizeof(ar2)/sizeof(ar2[0]);

    int total_sum = 0;
    int i=0, sum1 = 0;
    int j=0, sum2 = 0;

    while(i < n && j < m){
        if(ar1[i] < ar2[j]){
            sum1 += ar1[i];
            i++;
        } else if (ar1[i] > ar2[j]){
            sum2 += ar2[j];
            j++;
        } else {
            total_sum += max(sum1, sum2);
            total_sum += ar1[i];
            i++;
            j++;
            sum1 = sum2 = 0;
        }
    }

    while(i < n){
        sum1 += ar1[i];
        i++;
    }

    while(j < m){
        sum2 += ar2[j];
        j++;
    }

    total_sum += max(sum1, sum2);

    cout<<total_sum<<"\n";
    return 0;
}
